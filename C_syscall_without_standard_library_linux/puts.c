// gcc -s -O2 -nostdlib puts.c
/*
/tmp/ccyVj5OO.o: In function `main':
puts.c:(.text.startup+0x18): undefined reference to `write'
collect2: error: ld returned 1 exit status
*/

// gcc -s -O2 puts.c
// usage : strace a.out

#include <stdio.h>

int main(int argc, char* argv[])
{

    //write(1, "hello\n", 6);
    puts("hello");

    return 0;
}

