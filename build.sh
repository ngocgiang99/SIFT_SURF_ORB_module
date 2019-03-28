g++ -g -Wall -fexceptions -g -c ./SURF/surf.cpp `pkg-config --libs --cflags opencv` -o ./SURF/surf.o
g++ -g -Wall -fexceptions -g -c ./ORB/orb.cpp `pkg-config --libs --cflags opencv` -o ./ORB/orb.o
g++ -g -Wall -fexceptions -g -c ./SIFT/sift.cpp `pkg-config --libs --cflags opencv` -o ./SIFT/sift.o

g++ -g main.cpp ./SURF/surf.o ./ORB/orb.o ./SIFT/sift.o `pkg-config --libs --cflags opencv` -o ./Test

./Test
