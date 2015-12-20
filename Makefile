all: greyscale greyscale2

test: greyscale23.ppm greyscale34.ppm greyscale2.ppm greyscale2noborder.ppm

greyscale: greyscale.c
	gcc -o greyscale greyscale.c

greyscale2: greyscale2.c
	gcc -o greyscale2 greyscale2.c

greyscale23.ppm: greyscale
	./greyscale > greyscale23.ppm

greyscale34.ppm: greyscale
	./greyscale h=40 v=30 hb=400 vb=300 c=127 > greyscale34.ppm

greyscale2.ppm: greyscale2
	./greyscale2 > greyscale2.ppm

greyscale2noborder.ppm: greyscale2
	./greyscale2 s=0 > greyscale2noborder.ppm

clean:
	-rm greyscale
	-rm greyscale2
	-rm greyscale23.ppm
	-rm greyscale34.ppm
	-rm greyscale2.ppm
	-rm greyscale2noborder.ppm
