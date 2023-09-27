main: main.c
	$(CC) -o $@ $@.c

clean:
	-rm -f *.o
	@echo "All clean!"

