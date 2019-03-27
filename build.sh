g++ -g -Wall -fexceptions -g -c ./SURF/surf.cpp `pkg-config --libs --cflags opencv` -o ./surf.o
g++ -g -Wall -fexceptions -g -c ./ORB/orb.cpp `pkg-config --libs --cflags opencv` -o ./orb.o
g++ -g -Wall -fexceptions -g -c ./SIFT/sift.cpp `pkg-config --libs --cflags opencv` -o ./sift.o

g++ -g main.cpp ./surf.o ./orb.o ./sift.o `pkg-config --libs --cflags opencv` -o ./Test

./Test
