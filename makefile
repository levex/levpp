.PHONY: all run clean

# configuration
CC = gcc
APP = levpp

OBJS = main.o

include syntax/makefile

all: $(APP)

clean:
	-@rm $(APP)
	-@rm $(OBJS)

$(APP): $(OBJS)
	@echo "  LN           $(APP)"
	@$(CC) -o $(APP) $(OBJS)

%.o: %.c
	@echo "  CC           $@"
	@$(CC) -Iinclude -c $< -o $@
