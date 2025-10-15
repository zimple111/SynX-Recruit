# 招新基础部分C语言
## 1.launch.json与tasks.json配置（未作修改，可执行文件已通过gcc来重命名，具体情况在汇报的问题里有阐述）
- launch.json
<a href="https://imgse.com/i/pV7mXEd"><img src="https://s21.ax1x.com/2025/10/05/pV7mXEd.png" alt="pV7mXEd.png" border="0" /></a>
- tasks.json
<a href="https://imgse.com/i/pV7mjUA"><img src="https://s21.ax1x.com/2025/10/05/pV7mjUA.png" alt="pV7mjUA.png" border="0" /></a>
## 2.ASCII码
- 其输出结果为97，原因为'a'为字符型数据，但输出使用了%d格式转换符，所以会输出a对应的ASCII码97。
```
- #include <stdio.h>
    int main(){
       char a = '1';
       //预期输出结果 1
       //请在这里补全代码
       a=a-'0';
       //
       printf("%d",a);
       return 0;
   }
```
- 前者赋值的'1'是字符型数据，后者输出的1是整型，通过-'0'来实现转换'
## 3.数组
```
#include<stdio.h>
int main(){
    int n;
    printf("请输入学生个数：");
    scanf("%d",&n);
    int scores[n];
    int count[101]={0};
    float average,sum=0;
    for(int i=0;i<n;i++){
        printf("请输入第%d个学生的成绩：",i+1);
        scanf("%d",&scores[i]);
        count[scores[i]]++;
        sum+=scores[i];
    }
    average=sum/n;
    printf("平均分为：%.2f\n",average);
    printf("\n成绩分布情况如下：\n");
    printf("分数\t人数\n");
    for(int i=0;i<=100;i++){
        if(count[i]>0){
            printf("%d\t%d\n",i,count[i]);
        }
    }
}
```
## 4.循环结构
### 4.1 for循环
```
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
```
### 4.2 while循环
```
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
```
### 4.3 递归
```
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
```
## 5.指针
### 5.1 指针基础概念
```
#include <stdio.h>
    int main() {
        int num = 10;
        int *ptr = &num; // 填空：将ptr指向num
        printf("num的值: %d\n",*ptr); // 填空：通过指针访问num的值
        printf("num的地址: %p\n", ptr); // 填空：通过指针获取num的地址
        *ptr = 20; // 通过指针修改num的值
        printf("修改后num的值: %d\n", num);
        return 0;
   }
```
### 5.2 指针和数组
```
#include <stdio.h>
    int main() {
        int arr[5] = {1, 2, 3, 4, 5};
        int *ptr = arr; // 数组名就是数组首元素的地址
        // 使用指针访问数组元素
        for(int i = 0; i < 5; i++) {
            printf("arr[%d] = %d", i, *ptr); // 填空：通过指针访问数组元素
            printf(", 地址: %p\n", ptr); // 填空：获取每个元素的地址
            ptr++; // 指针移动到下一个元素
        }
        return 0;
   }
```
### 5.3 指针的运算
```
#include <stdio.h>
    int main() {
        int arr[3] = {10, 20, 30};
        int *ptr = arr;
        printf("%d\n", *ptr);      // 输出: 数组的首元素的值
        printf("%d\n", *(ptr+1));  // 输出: 数组第二个元素的值
        printf("%d\n", *ptr+1);    // 输出: 数组首元素的值加1
        ptr++;
        printf("%d\n", *ptr);      // 输出: 数组第二个元素的值
        return 0;
   }
```
### 5.4 swap交换函数
```
#include<stdio.h>
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int x = 10, y = 20;
    printf("交换前: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("交换后: x = %d, y = %d\n", x, y);
    return 0;
}
```
