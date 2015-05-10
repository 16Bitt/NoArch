SOURCES = $(patsubst %.c,%.o,$(wildcard *.c))
CFLAGS	= -I../include

all: copyup

clean:
	-rm $(SOURCES)

copyup: $(SOURCES)
	mv $(SOURCES) ..

nop:
	@@echo Nop
