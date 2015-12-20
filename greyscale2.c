#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program generates 32 patches in a 1x32 grid.  The patches
   has the values 0,8,16,...,240,248,255.

   Deafult: Each patch is 40x800 pixels. The total area of the patches
   is then 1280x800 pixels. Included the patches, there is 2 pixel black
   line. Around the patch area there is a black frame. Up and down it
   is 200 pixels and left and right it is 260 pixels. The total area
   then becomes 1800x1200 pixels. Black is 31. */

static int v = 200;
static int h = 40;

static int vborder = 500;
static int hborder = 260;

static int spacing = 2;

static int border_color = 31;

static void border(int i, int j, int do_nl) {
  int ii, jj;

  for (ii = 0; ii < i; ii++) {
    for (jj = 0; jj < j; jj++) {
      printf("%d ", border_color);
    }
    if (do_nl) printf("\n");
  }
}

static void usage()
{
  fprintf(stderr,
	  "usage: greyscale "
	  "[h=HSIZE] "
	  "[v=VSIZE] "
	  "[hb=HBORDERSIZE] "
	  "[vb=VBORDERSIZE] "
	  "[s=SPACINGSIZE] "
	  "[c=BORDERCOLOR]\n");
  exit(1);
}

static void arg(char *str)
{
  char *valpos = strchr(str, '=');
  int keysize;

  if (!valpos)
    usage();

  keysize = valpos - str;

  valpos++;

#if 0
  fprintf(stderr, "str = %s\n", str);
  fprintf(stderr, "valpos = %s\n", valpos);
  fprintf(stderr, "keysize = %d\n", keysize);
#endif

  if (strncmp(str,          "v", keysize) == 0)
    v = atoi(valpos);
  else if (strncmp(str,     "h", keysize) == 0)
    h = atoi(valpos);
  else if (strncmp(str,    "vb", keysize) == 0)
    vborder = atoi(valpos);
  else if (strncmp(str,    "hb", keysize) == 0)
    hborder = atoi(valpos);
  else if (strncmp(str,     "s", keysize) == 0)
    spacing = atoi(valpos);
  else if (strncmp(str,     "c", keysize) == 0)
    border_color = atoi(valpos);
  else
    usage();
}

int main(int argc, char *argv[])
{
  int i, j, jj;

  for (i=1; i<argc; i++) {
    arg(argv[i]);
  }

  int width = 2*hborder + 32*h;
  int height = 2*vborder + v;

#if 0
  fprintf(stderr, "h       = %d\n", h);
  fprintf(stderr, "v       = %d\n", v);
  fprintf(stderr, "hborder = %d\n", hborder);
  fprintf(stderr, "vborder = %d\n", vborder);
  fprintf(stderr, "spacing = %d\n", spacing);
  fprintf(stderr, "bcolor  = %d\n", border_color);
  fprintf(stderr, "width   = %d\n", width);
  fprintf(stderr, "height  = %d\n", height);
#endif

  printf("P2\n %d %d\n255\n", width, height);

  border(vborder, width, 1); /* Upper */

  for (i = 0; i < v; i++) {
    border(1, hborder, 1); /* Left */

    for (j = 0; j < 32; j++) {
      border(1, spacing, 0); /* Vertical spacings */
      for (jj = 0; jj < h-spacing; jj++) {
	printf("%d ", j*8);
      }
    }
    border(1, hborder, 1); /* Right */
  }

  border(vborder, width, 1); /* Lower */

  return 0;
}
