#include<stdio.h>
int main(){
    int n;
    printf("请输入打印项数：");
    scanf("%d",&n);
    int a0=0,a1=1,a2=0,count=0;
    printf("斐波那契数列前%d项为：\n",n);
    while (count<n){
        if(count==0){
            printf(" %d",a0);
        }
        else if(count==1){
            printf(" %d",a1);
        }
        else {
            a2=a0+a1;
            printf(" %d ",a2);
            a0=a1;
            a1=a2;
        }
        count++;
    }
}