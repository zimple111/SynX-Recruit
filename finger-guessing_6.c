#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    srand(time(NULL));//初始化随机数种子
    int player,computer,a=0,b=0;
    printf("*****猜拳小游戏*****\n");
    printf("石头=0,剪刀=1,布=2\n");
    while(a!=3&&b!=2){
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
            printf("你赢了这一局！");
            b++;
        }
        if(computer==0&&player==1||computer==1&&player==2||computer==2&&player==0){
            printf("你输了，再来一次");
            a++;
        }   
    }
    printf("游戏结束，你赢了%d局，输了%d局",b,a);
    if(a>b){
        printf("你输掉了比赛");
    }
    else {
        printf("你赢得了比赛");
    }
    return 0;
}