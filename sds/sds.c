#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 手动实现 sds 结构

1.初始化 sds 字符串
2.获取字符串长度
3.字符串拼接
4.移除字符串两端给定到的字符
5.比较两个字符
*/


// 1.初始化 sds 字符串
typedef struct sds {
    int len;
    int free;
    char* buf;
}sds;


sds* sdsnew (const char* str)
{
    // 创建长度和字符串一样的内存空间
    int lenght = strlen(str);
    sds* s = (sds*)malloc(sizeof(struct sds));
    s -> len = lenght;
    s -> free = 0;
    s -> buf = malloc(sizeof(lenght+1));
    strcpy(s -> buf, str);
    return s;
}


// 2.返回 sds 长度
int get_sds_len(sds* s){
    return s -> len;
}


int main()
{
    sds* s = sdsnew("hello world\n");
    printf("%s", s -> buf);
    printf("sds len is %d\n", s -> len);
    return 0;
}