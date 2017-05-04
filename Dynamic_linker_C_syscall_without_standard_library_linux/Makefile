CC=gcc
ASSMSYSCALLSOURCE=assm_syscall.c
CONFIG=-nostdlib -fno-unwind-tables -fno-asynchronous-unwind-tables
LIBDYNNAME=libdyn.so
DYNTESTSOURCE=dytest.c
DYNELF=dytest

all:
	$(CC) -s -O2 $(CONFIG) -fPIC -shared -o $(LIBDYNNAME)  $(ASSMSYSCALLSOURCE)
	$(CC) -o $(DYNELF) $(DYNTESTSOURCE) ./$(LIBDYNNAME)

nodyn:
	$(CC) -s -O2 $(CONFIG) -fPIC -shared -o $(LIBDYNNAME)  $(ASSMSYSCALLSOURCE)
	$(CC) -o $(DYNELF) $(DYNTESTSOURCE)

clean:
	rm -rf $(LIBDYNNAME) $(DYNELF)
