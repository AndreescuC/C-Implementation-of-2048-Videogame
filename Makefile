
build: wholething.c curent_user.txt users.txt highscores.txt
	gcc wholething.c -o 2048 -lncurses
curent_user.txt:
	touch curent_user.txt
	echo "Guest" >> curent_user.txt
highscores.txt:
	touch highscores.txt
	echo "1\nGuest 100" >> highscores.txt
users.txt:
	touch users.txt
	echo "1\nGuest guest"
run: build
	./2048
clean: 2048
	rm 2048
	 
