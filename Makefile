all: greyscale.out

test: greyscale.ppm

greyscale.out: greyscale.c
	gcc -o greyscale.out greyscale.c

greyscale.ppm: greyscale.out
	./greyscale.out > greyscale.ppm

clean:
	rm greyscale.out
	rm greyscale.ppm
