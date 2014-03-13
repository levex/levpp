.PHONY: all run clean

# configuration
CC = gcc
APP = levpp

OBJS = main.o

all: $(APP)

clean:
	-@rm $(APP)
	-@rm $(OBJS)

$(APP): $(OBJS)
	@echo "  LN           $(APP)"
	@$(CC) -o $(APP) $(OBJS)

%.o: %.c
	@echo "  CC           $@"
	@$(CC) -c $<
