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
