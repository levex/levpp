.PHONY: all run link

# configuration
CC = gcc
APP = levpp

OBJS = main.o

all: $(APP)

$(APP): $(OBJS)
	@echo "  LN           $(APP)"
	@$(CC) -o $(APP) $(OBJS)

%.o: %.c
	@echo "  CC           $@"
	@$(CC) -c $<
