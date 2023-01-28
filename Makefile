all:
	@gcc -D BUFFER_SIZE=1 *.c | ./a.out | cat -e
sm:
	@gcc -D BUFFER_SIZE=1 *.c | ./a.out
fs:
	@gcc -D BUFFER_SIZE=40 -fsanitize=address -g *.c | ./a.out | cat -e