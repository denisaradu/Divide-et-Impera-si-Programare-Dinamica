CC ?= gcc
CFLAGS ?= -Wall -Wextra -pedantic -Werror -Wfatal-errors -g -std=gnu99 
LDFLAGS ?= -g

FILES = main2.o
EXEC = "ex2"

.PHONY: build
build: $(EXEC)

$(EXEC): $(FILES) 
	$(CC) $(LDFLAGS) -o $(EXEC) $(FILES) -lm

%.o: %.c 
	$(CC) $(CFLAGS) -c $<

.PHONY: run
run: $(EXEC)
	./$(EXEC)

.PHONY: clean
clean:
	rm $(FILES) $(EXEC)