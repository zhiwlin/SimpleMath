# Format for the make:
# target : dependent
#       command

# To make particular program, use: make [program name]

## CC is the compiler name
CC=gcc
## CCFLAGS=-mno-cygwin
## -mwindows results that no console is needed,i.e., all GUI
## CCFLAGSWIN=-mno-cygwin -mwindows
# $@ is the target itself
# $< is the full name of the dependent

math_add: math_add.c
	@echo Compiling the program math_add
	$(CC) $(CCFLAGSWIN) $< -o $@
math_sub: math_sub.c
	@echo Compiling the program math_sub
	$(CC) $(CCFLAGSWIN) $< -o $@
math_mux: math_mux.c
	@echo Compiling the program math_mux
	$(CC) $(CCFLAGSWIN) $< -o $@
math_div: math_div.c
	@echo Compiling the program math_div
	$(CC) $(CCFLAGSWIN) $< -o $@
clean:
	@echo Cleaning up...
	rm -f *~
	rm -f .*~
	rm -f *.o

# End of makefile
