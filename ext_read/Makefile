#
#
#
CC    = gcc
CFLAGS= -O2
TARGET= test
DIRS  = . 
FILES = $(foreach dir,$(DIRS),$(wildcard $(dir)/*.c))
OBJS  = $(pathsubst %.c,%.o,$(FILES))
$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(FILES)
clean:
	$(RM) $(TARGET)
	$(RM) $(OBJS)
