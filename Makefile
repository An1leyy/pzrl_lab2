name = sed_simplified
cfiles = main.c labpzrl2.c
objects = $(cfiles:.c=.o)
input = text.txt -r "a" "b"
.PHONY: clean test

$(name): $(objects)
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@ -Wall

clean:
	rm -f $(name) $(objects)

test:
	./$(name) $(input)
