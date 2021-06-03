all: torrent

main.o: main.cc torrent.hpp game.hpp film.hpp software.hpp server.hpp

torrent: main.o
	g++ main.o -o torrent

clean:
	rm -f *.o server
