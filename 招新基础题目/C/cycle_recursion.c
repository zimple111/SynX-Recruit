#include<stdio.h>
long long a(int n){
    if (n==0){
        return 1;
    }
    else {
        return n*a(n-1);
    }
}
int main(){
    int n;
    printf("请输入一个非负整数：");
    scanf("%d",&n);
    printf("%d的阶乘是%lld\n",n,a(n));
    return 0;
}