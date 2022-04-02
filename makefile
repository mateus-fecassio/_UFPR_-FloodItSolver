CC      	  = gcc -std=c11 -g -O3
LFLAGS        =
CFLAGS  = 	-pipe \
			-ggdb3 -fstack-protector-all \
			-W -Wall -Wextra \
			-Wmissing-declarations \
			-Wmissing-format-attribute \
			-Wmissing-noreturn \
			-Wmissing-prototypes \
			-Wredundant-decls

#------------------------------------------------------------------------------
PROG = floodit
OBJS = stack.o \
       $(PROG).o
#------------------------------------------------------------------------------
.PHONY : all clean
#------------------------------------------------------------------------------
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

all: $(PROG)

$(PROG):  $(PROG).o

$(PROG): $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)
#------------------------------------------------------------------------------
clean:
	@echo "Limpando ...."
	@rm -f *~ *.bak *.tmp

purge:   clean
	@echo "Faxina ...."
	@rm -f *.o core a.out
	@rm -f $(PROG)