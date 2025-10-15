#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>
 
// 游戏参数配置 
#define MAP_WIDTH 80 
#define MAP_HEIGHT 25 
#define SNAKE_MAX_LEN 100 
#define INIT_SPEED 200  // 初始移动速度(ms)
 
// 难度级别配置 [1]()[4]()
#define EASY_SPEED   200 
#define MEDIUM_SPEED 150 
#define HARD_SPEED   100 
#define EXTREME_SPEED 50 
 
// 方向键ASCII码 
#define KEY_UP    72 
#define KEY_DOWN  80 
#define KEY_LEFT  75 
#define KEY_RIGHT 77 
#define PAUSE_KEY 'p'
 
// 数据结构 
typedef struct {
    int x, y;
} Point;
 
typedef struct {
    Point body[SNAKE_MAX_LEN];
    int length;
    int direction;
} Snake;
 
typedef struct {
    int x, y;
} Food;
 
// 全局变量 
int gameSpeed = INIT_SPEED;
bool isPaused = false;
 
// 光标定位 
void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
 
// 难度选择菜单 [4]()[6]()
int selectDifficulty() {
    system("cls");
    printf("\n\n\t====== 贪吃蛇游戏 ======\n");
    printf("\n\t请选择难度级别：\n");
    printf("\n\t1. 简单（适合新手）");
    printf("\n\t2. 中等（标准挑战）");
    printf("\n\t3. 困难（高手模式）");
    printf("\n\t4. 地狱（自虐体验）");
    printf("\n\n\t按ESC返回游戏");
    
    while(1) {
        if(_kbhit()) {
            int key = _getch();
            switch(key) {
                case '1': return EASY_SPEED;
                case '2': return MEDIUM_SPEED;
                case '3': return HARD_SPEED;
                case '4': return EXTREME_SPEED;
                case 27:  return gameSpeed; // ESC保持原难度 
            }
        }
        Sleep(50);
    }
}
 
// 绘制游戏界面（含难度显示）
void drawUI(Snake* snake, int difficultyLevel) {
    // 顶部信息栏 
    gotoxy(2, 0);
    printf("分数: %d", snake->length - 3);
    
    gotoxy(MAP_WIDTH/2 - 10, 0);
    printf("难度: ");
    switch(difficultyLevel) {
        case EASY_SPEED:    printf("简单"); break;
        case MEDIUM_SPEED:  printf("中等"); break;
        case HARD_SPEED:    printf("困难"); break;
        case EXTREME_SPEED: printf("地狱"); break;
    }
    
    gotoxy(MAP_WIDTH - 15, 0);
    printf("暂停: P");
}
 
// 绘制地图 
void drawMap() {
    // 上边界 
    for (int i = 0; i < MAP_WIDTH; i += 2) {
        gotoxy(i, 0);
        printf("■");
    }
    
    // 下边界 
    for (int i = 0; i < MAP_WIDTH; i += 2) {
        gotoxy(i, MAP_HEIGHT - 1);
        printf("■");
    }
    
    // 左边界 
    for (int i = 1; i < MAP_HEIGHT - 1; i++) {
        gotoxy(0, i);
        printf("■");
    }
    
    // 右边界 
    for (int i = 1; i < MAP_HEIGHT - 1; i++) {
        gotoxy(MAP_WIDTH - 2, i);
        printf("■");
    }
}
 
// 蛇移动逻辑 
void moveSnake(Snake* snake) {
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }
    
    switch (snake->direction) {
        case KEY_UP:    snake->body[0].y--; break;
        case KEY_DOWN:  snake->body[0].y++; break;
        case KEY_LEFT:  snake->body[0].x -= 2; break;
        case KEY_RIGHT: snake->body[0].x += 2; break;
    }
}
 
// 碰撞检测 
int checkCollision(Snake* snake) {
    Point head = snake->body[0];
    
    // 边界碰撞 
    if (head.x <= 0 || head.x >= MAP_WIDTH - 2 || 
        head.y <= 0 || head.y >= MAP_HEIGHT - 1) 
        return 1;
    
    // 自碰撞 
    for (int i = 1; i < snake->length; i++) {
        if (head.x == snake->body[i].x && head.y == snake->body[i].y)
            return 1;
    }
    return 0;
}
 
// 食物生成 
void createFood(Food* food, Snake* snake) {
    int valid;
    do {
        valid = 1;
        food->x = (rand() % (MAP_WIDTH/2 - 4)) * 2 + 2;
        food->y = rand() % (MAP_HEIGHT - 4) + 2;
        
        // 检查与蛇身重叠 
        for (int i = 0; i < snake->length; i++) {
            if (food->x == snake->body[i].x && food->y == snake->body[i].y) {
                valid = 0;
                break;
            }
        }
    } while (!valid);
}
 
// 主游戏逻辑 
int main() {
    srand((unsigned)time(NULL));
    
    // 初始化蛇 
    Snake snake = {
        .body = {{40, 12}, {38, 12}, {36, 12}},
        .length = 3,
        .direction = KEY_RIGHT 
    };
    
    // 初始化食物 
    Food food;
    createFood(&food, &snake);
    
    // 难度选择 [1]()[4]()
    gameSpeed = selectDifficulty();
    int difficultyLevel = gameSpeed;
 
    while (1) {
        if (!isPaused) {
            // 清屏并绘制元素 
            system("cls");
            drawMap();
            drawUI(&snake, difficultyLevel);
            
            // 绘制蛇 
            for (int i = 0; i < snake.length;  i++) {
                gotoxy(snake.body[i].x,  snake.body[i].y); 
                printf(i == 0 ? "◎" : "●");
            }
            
            // 绘制食物 
            gotoxy(food.x, food.y);
            printf("★");
            
            // 处理输入 
            if (_kbhit()) {
                int key = _getch();
                
                // 难度选择菜单 
                if (key == 'D' || key == 'd') {
                    gameSpeed = selectDifficulty();
                    difficultyLevel = gameSpeed;
                    continue;
                }
                
                // 暂停功能 
                if (key == PAUSE_KEY) {
                    isPaused = !isPaused;
                    gotoxy(MAP_WIDTH/2 - 5, MAP_HEIGHT/2);
                    printf("游戏暂停");
                    continue;
                }
                
                // 方向控制（防180°转向）
                if ((key == KEY_UP && snake.direction  != KEY_DOWN) ||
                    (key == KEY_DOWN && snake.direction  != KEY_UP) ||
                    (key == KEY_LEFT && snake.direction  != KEY_RIGHT) ||
                    (key == KEY_RIGHT && snake.direction  != KEY_LEFT)) {
                    snake.direction  = key;
                }
            }
            
            // 移动蛇 
            moveSnake(&snake);
            
            // 碰撞检测 
            if (checkCollision(&snake)) {
                gotoxy(MAP_WIDTH/2 - 5, MAP_HEIGHT/2);
                printf("游戏结束！得分: %d", snake.length  - 3);
                break;
            }
            
            // 吃食物检测 
            if (snake.body[0].x  == food.x && snake.body[0].y  == food.y) {
                snake.length++; 
                createFood(&food, &snake);
                
                // 难度递增 [2]()[7]()
                if (difficultyLevel > EXTREME_SPEED) {
                    gameSpeed = max(gameSpeed - 10, EXTREME_SPEED);
                }
            }
        } else {
            // 暂停状态处理 
            if (_kbhit() && _getch() == PAUSE_KEY) {
                isPaused = false;
            }
        }
        
        Sleep(gameSpeed);  // 难度控制的核心 [7]()
    }
    
    getch();  // 等待任意键退出 
    return 0;
}