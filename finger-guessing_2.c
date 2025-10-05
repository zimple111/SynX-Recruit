#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    time_t start_time = time(NULL);
    srand(time(NULL));//初始化随机数种子
    int player,computer;
    int win=0;
    printf("*****猜拳小游戏*****\n");
    printf("石头=0，剪刀=1，布=2\n");
    while(!win){
        if (difftime(time(NULL), start_time) >= 10) {
            printf("\n时间到！10秒内未获胜，游戏失败！\n");
            return 0;
        }
        printf("请输入你的选择：");
        scanf("%d",&player);
        if (player>2||player<0){
            printf("输入错误，请重新输入");
            continue;
        }
        computer=rand()%3;
        if (computer==0){
            printf("电脑出石头");
        }
        if (computer==1){
            printf("电脑出剪刀");
        }
        if (computer==2){
            printf("电脑出布");
        }
        if (computer==player){
            printf("平局，再来一次");
        }
        if (computer==1&&player==0||computer==2&&player==1||computer==0&&player==2){
            printf("你赢了，游戏结束");
            win=1;
        }
        else
            printf("你输了，再来一次");

    }
    return 0;
}