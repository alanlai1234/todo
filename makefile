all: main

main : main.cpp
	g++ -l sqlite3 main.cpp -o todo
