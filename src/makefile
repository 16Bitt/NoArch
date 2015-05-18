SOURCES = $(patsubst %.c,%.o,$(wildcard *.c))
CFLAGS	= -Iinclude

all: $(SOURCES)
	$(CC) $(SOURCES) -o noarch

clean:
	-rm $(SOURCES) noarch

run: all
	./noarch

nop:
	@@echo Nop
