INCLUDE:= 
LDFLAGS:= -lncurses


all: scroll

scroll: main.o display.o input.o
	cc -o $@ $^ $(LDFLAGS)

clean: 
	rm -f *.o scroll

main.o: main.c scroll.h
	cc -c $<

input.o: input.c scroll.h
	cc -o $@ -c $< $(INCLUDE) 

display.o: display.c scroll.h
	cc -o $@ -c $< $(INCLUDE)

run: scroll
	./scroll

