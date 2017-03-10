// gcc -s -O2 -nostdlib main.c
// gcc -s -O2 main.c
// gdb a.out
// break main
// run
// bt


#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("hello\n");

    return 0;
}
