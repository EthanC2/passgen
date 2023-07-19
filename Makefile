passgen: main.c
	gcc -o passgen -Wall -Wextra -Werror main.c

clean:
	rm passgen