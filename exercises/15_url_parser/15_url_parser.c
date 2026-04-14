#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * URL参数解析器
 * 输入：包含http/https超链接的字符串
 * 输出：解析出所有的key-value键值对，每行显示一个
 */

int parse_url(const char* url) {
    int err = 0;

    char *query = strchr(url, '?');
    if (!query) {
        err = -1;
        goto exit;
    }
    query++;

    char buf[512];
    strncpy(buf, query, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    char *token = strtok(buf, "&");
    while (token != NULL) {
        char *eq = strchr(token, '=');
        if (eq) {
            *eq = '\0';
            printf("key = %s, value = %s\n", token, eq + 1);
        }
        token = strtok(NULL, "&");
    }

exit:
    return err;
}

int main() {
    const char* test_url = "https://cn.bing.com/search?name=John&age=30&city=New+York";

    printf("Parsing URL: %s\n", test_url);
    printf("Parameters:\n");

    parse_url(test_url);

    return 0;
}