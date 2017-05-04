// gcc -s -O2 -nostdlib assm_syscall.S assm_syscall.c
// ./a.out
// wc -c a.out
// gcc -s -O2 -nostdlib -fno-unwind-tables -fno-asynchronous-unwind-tables assm_syscall.S assm_syscall.c

void* syscall(
    void* syscall_number,
    void* param1,
    void* param2,
    void* param3,
    void* param4,
    void* param5
);

typedef unsigned long int uintptr; /* size_t */
typedef long int intptr; /* ssize_t */

static
intptr write(int fd, void const* data, uintptr nbytes)
{
    return (intptr)
        syscall(
            (void*)1, /* SYS_write */
            (void*)(intptr)fd,
            (void*)data,
            (void*)nbytes,
            0, /* ignored */
            0  /* ignored */
        );
}

int print(){

    write(1, "hello world\n", 13);
    return 0;

}
