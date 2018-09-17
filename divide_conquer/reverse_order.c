#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * reverse_order(char *str) {
    int len = strlen(str);

    if (len == 1) return str;
    else {
        int n = len / 2;
        char *str1 = (char *)malloc(sizeof(char) * n);
        char *str2 = (char *)malloc(sizeof(char) * (len - n));
        strncpy(str1, str, n);
        strncpy(str2, &str[n], len - n);
        str1 = reverse_order(str1);
        str2 = reverse_order(str2);
        return strcat(str2, str1);
    }
}

int main(int argc, char const *argv[]) {
    if (argc <= 1) {
        printf("Input format: ./reverse_order str\n");
        return -1;
    }
    char *ret = (char *)malloc(sizeof(char) * strlen(argv[1]));
    ret = reverse_order(argv[1]);
    printf("ret = %s\n", ret);
    return 0;
}
