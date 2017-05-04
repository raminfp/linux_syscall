### Dynamic linker without stdlib



```bash
root@raminfp:~# make
gcc -s -O2 -nostdlib -fno-unwind-tables -fno-asynchronous-unwind-tables -fPIC -shared -o libdyn.so  assm_syscall.c
gcc -o dytest dytest.c ./libdyn.so
root@raminfp:~# ./dytest
hello world
root@raminfp:~#
root@raminfp:~# make clean
```
