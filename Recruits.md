# <font face="仿宋" color=orange>SynX招新 基础题目</font>
## 一.github仓库地址
  https://github.com/zimple111/SynX-Recruit.git
## 二.git
### 1.git是什么？
- 通俗来说，git是帮助团队更高效地开发项目而诞生的开源控制系统，是代码的时光机。可以解决如“多人之间代码如何同步？某份代码是谁改的？改的什么？什么时间改的？”等问题（暴躁老哥Linus不鸟BitKeeper十天开发出来还是太强啦（doge）
- 专业一点说 Git是一个分布式版本控制系统，以本地库为核心，支持高效分支管理和离线工作，适合分布式开发团队。
### 2.git有什么用？
- git的必杀技在于其分支管理，这就为分布式开发提供了良好的平台。不管是本地开发，团队协作还是离线工作程序员都能借助git高效完成目标，快速合并更改。
### 3.为什么要用git？
- git的最大优势就是分支管理和追溯功能。一个开发团队，可以通过远程仓库如本次招新使用的github同步代码，非常适合团队成员的分布式开发且个人可以利用其记录项目迭代过程（如git log查看修改历史，git status查看状态等）
### 4. git优缺点
- 优点：每个开发者的本地都有完整的版本库，支持离线提交，对比，还原，适合大型项目和团队协作，非常适合分布式开发。效率很高，特别是克隆大型项目远超SVN。分支机制良好，主分支可以很纯净不受到污染，分支合并也很高效。
- 缺点：学习成本高（感受到了······）。git是把双刃剑，便捷分布式开发的同时也一定会带来保密性的问题，因为每一个开发者的本地都有各个完整的版本库。对代码权限管理要求高。
## 三.猜拳小游戏
- 1.
```
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    srand(time(NULL));//初始化随机数种子
    int player,computer;
    int win=0;
    printf("*****猜拳小游戏*****\n");
    printf("石头=0，剪刀=1，布=2\n");
    while(!win){
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
```
- 2.
```
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
```
    

