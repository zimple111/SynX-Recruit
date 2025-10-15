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