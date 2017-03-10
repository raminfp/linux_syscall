// gcc -s -O2 -nostdlib assm_syscall.S assm_syscall.c
// ./a.out
// wc -c a.out
// gcc -s -O2 -nostdlib -fno-unwind-tables -fno-asynchronous-unwind-tables assm_syscall.S assm_syscall.c
// objdump -s -j .comment a.out
// objdump a.out

void* syscall5(
    void* number,
    void* arg1,
    void* arg2,
    void* arg3,
    void* arg4,
    void* arg5
);

typedef unsigned long int uintptr; /* size_t */
typedef long int intptr; /* ssize_t */

static
intptr write(int fd, void const* data, uintptr nbytes)
{
    return (intptr)
        syscall5(
            (void*)1, /* SYS_write */
            (void*)(intptr)fd,
            (void*)data,
            (void*)nbytes,
            0, /* ignored */
            0  /* ignored */
        );
}

int main(int argc, char* argv[])
{
    write(1, "hello world\n", 13);

    return 0;
}
