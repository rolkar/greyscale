all: greyscale

test: greyscale23.ppm greyscale34.ppm

greyscale: greyscale.c
	gcc -o greyscale greyscale.c

greyscale23.ppm: greyscale
	./greyscale > greyscale23.ppm

greyscale34.ppm: greyscale
	./greyscale h=40 v=30 hb=400 vb=300 c=127 > greyscale34.ppm

clean:
	rm greyscale
	rm greyscale23.ppm
	rm greyscale34.ppm
