#include <stdio.h>

/* This program generates 256 patches in a 16x16 grid.  The patches
   has the values 0,1,2,3,...,255.

   Deafult: Each patch is 75x50 pixels. The total area of the patches
   is then 1200x800 pixels. Included in each patch is a 1 pixel black
   frame. Around the patch area there is a black frame. Up and down it
   is 200 pixels and left and right it is 300 pixels. The total area
   then becomes 1800x1200 pixels. Black is 31. */

static int v = 50;
static int h = 75;

static int vborder = 200;
static int hborder = 300;

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

int main(int argc, char *argv)
{
  int width = 2*hborder + 16*h;
  int height = 2*vborder + 16*v;

  int i, ii, j, jj;

  printf("P2\n %d %d\n255\n", width, height);

  border(hborder, width, 1); /* Upper */

  for (i = 0; i < 16; i++) {
    border(spacing, width, 1); /* horizontal spacings */
    for (ii = 0; ii < v-spacing; ii++) {
      border(1, hborder, 0); /* Left */
      for (j = 0; j < 16; j++) {
	border(1, spacing, 0); /* Vertical spacings */
	for (jj = 0; jj < h-spacing; jj++) {
	  printf("%d ", j + 16*i);
	}
      }
      border(1, hborder, 1); /* Right */
    }
  }

  border(vborder, width, 1); /* Lower */

  return 0;
}
