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


// 2.字符串拼接，如果长度不够则计算所需要空间，然后 *2 扩展空间
void sdscat(sds* s1, char* s2){
    int len_s2 = strlen(s2);
    if (s1 -> free > len_s2) {
        strcat(s1 -> buf, s2);
        s1 -> len += len_s2;
        s1 -> free -= len_s2;
    } else {
        int total_len = s1->len + len_s2;
        s1 -> buf = realloc(s1 -> buf, total_len * 2 + 1);
        strcat(s1 -> buf, s2);
        s1 -> len = total_len;
        s1 -> free = total_len;
    }
    
}


int main()
{
    sds* s1 = sdsnew("hello world\n");
    printf("%s", s1 -> buf);
    printf("sds len is %d\n", s1 -> len);
    printf("sds free is %d\n", s1 -> free);

    sdscat(s1, "!!!");
    printf("%s", s1 -> buf);
    printf("sds len is %d\n", s1 -> len);
    printf("sds free is %d\n", s1 -> free);
    
    return 0;
}