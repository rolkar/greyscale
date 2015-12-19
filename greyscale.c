#include <stdio.h>

/* This program generates 256 patches in a 16x16 grid.  The patches
   has the values 0,1,2,3,...,255.  Each patch is 75x50 pixels. The
   total area of the patches is then 1200x800 pixels. Included in each
   patch is a 1 pixel black frame. Around the patch area there is a
   black frame. Up and down it is 200 pixels and left and right it is
   300 pixels. The total area then becomes 1800x1200 pixels. */

static void border(int i, int j, int do_nl) {
  int ii, jj;

  for (ii = 0; ii < i; ii++) {
    for (jj = 0; jj < j; jj++) {
      printf("%d ", 31);
    }
    if (do_nl) printf("\n");
  }
}

int main(int argc, char *argv)
{
  printf("P2\n1800 1200\n255\n");

  int i, ii, j, jj;

  border(200, 1800, 1); /* Upper */

  for (i = 0; i < 16; i++) {
    border(2, 1800, 1); /* horizontal spacings */
    for (ii = 0; ii < 50-2; ii++) {
      border(1, 300, 0); /* Left */
      for (j = 0; j < 16; j++) {
	border(1, 2, 0); /* Vertical spacings */
	for (jj = 0; jj < 75-2; jj++) {
	  printf("%d ", j + 16*i);
	}
      }
      border(1, 300, 1); /* Right */
    }
  }

  border(200, 1800, 1); /* Lower */

  return 0;
}
