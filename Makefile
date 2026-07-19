CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = student_registry
OBJS = main.o student_registry.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.c student_registry.h
	$(CC) $(CFLAGS) -c main.c -o main.o

student_registry.o: student_registry.c student_registry.h
	$(CC) $(CFLAGS) -c student_registry.c -o student_registry.o

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
