// gcc -s -O2 -nostdlib write.c
/*
/tmp/ccyVj5OO.o: In function `main':
puts.c:(.text.startup+0x18): undefined reference to `write'
collect2: error: ld returned 1 exit status
*/

#include <unistd.h>

int main(int argc, char* argv[])
{
    write(1, "hello world\n", 13);

    return 0;
}

