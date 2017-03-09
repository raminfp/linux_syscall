// SYSCALL with wrapper glibc function
// func : syscall()
// wahtis syscall
// man syscall
// source code wrapper syscall : https://github.molgen.mpg.de/git-mirror/glibc/blob/glibc-2.15/sysdeps/unix/sysv/linux/x86_64/syscall.S#L24-L42


#include <unistd.h>

int
main(int argc, char *argv[])
{
  unsigned long syscall_nr = 60;
  long exit_status = 42;

  syscall(syscall_nr, exit_status);
}
