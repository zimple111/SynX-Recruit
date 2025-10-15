#include<stdio.h>
int main(){
    int n;
    long long a=1;
    printf("请输入一个非负整数：");
    scanf("%d",&n);
    if (n==0){
        a=1;
    }
    else {
        for (int i=1;i<=n;i++){
            a=a*i;
        }
    }
    printf("%d的阶乘是%lld\n",n,a);
    return 0;
}