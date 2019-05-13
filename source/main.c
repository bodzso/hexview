#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n = (argc == 3) ? atoi(argv[2]) : 15;
    if(argc < 2 || n > 255 || n < 1){
        printf("Usage: hexview <file source> [# bytes to display max 255 bytes]\n");
        exit(1);
    }

    FILE *src = fopen(argv[1], "rb");
    char *BUFF = (char*)malloc(n+1);
    if(BUFF == NULL || src == NULL) exit(1);

    memset(BUFF, 0, n+1);
    unsigned char c;
    int i, j;
    unsigned int byte_count = 0;

    //header
    printf("%17s", "Offset(h)");
    for(i = 0; i < n; i++)
        printf(" %2x", i);

    //byte read
    printf("\n%016X: ", 0);
    for(i = n, j = 0; fread(&c, 1, 1, src) >= 1; i--){
        if(!i){
            printf("%s", BUFF);
            memset(BUFF, 0, n+1);
            putchar('\n');
            i = n; j = 0;
            byte_count += n;
            printf("%016X: ", byte_count); //print # bytes read
        }
        BUFF[j++] = (c >= '!' && c <= '~') ? c : ' '; //store character
        printf("%02X ", c); //print byte
    }

    for(; i != 0 ; i--) //put space before the last string
        printf("   ");

    printf("%s", BUFF); //print last string
    free(BUFF);
    fclose(src);
    return 0;
}
