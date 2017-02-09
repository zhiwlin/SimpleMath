#include <stdio.h>
#include <stdlib.h>

/* max value of math problem */
#define MAX_NUM 8
/* number of problems to create.
   4 problems per row, 14 rows per page
   16 pages = 896
   font size = 20, paragraph before&after=0.04 */
#define LOOP_COUNT (4*14*6)

/*
Generates a text file that contains simple math problems.
*/

int main() {
	FILE *fp;
	int c, d, e, f, g,h;
	
	if ((fp=fopen("math_mux.txt", "w")) == NULL) {
		fprintf(stderr, "Can't open file\n");
		exit(1);
	}
	
	f=RAND_MAX; /* maximum random variable */
	h=0;
	srand( time(0) ); /* initializes the random number generator */

	for(c=0;c<LOOP_COUNT;c++) {
		d = (int) (1.0*rand()/f*3); /* used to randomize type of problem */
		e = (int) (1.0*rand()/f*MAX_NUM);
		g = (int) (1.0*rand()/f*MAX_NUM);
		if ( (d>=0) && (d<1) ) {
			fprintf(fp,"%d X [       ] = %d", e, e * g);
		}
		else if ( (d>=1) && (d<2) ) {
			fprintf(fp,"[       ] X %d = %d", e, e * g);
		}
		else {
			fprintf(fp,"%d X %d = [       ]", e, g);
		}
		if (h==3) fprintf(fp,"\r\n");
		else fprintf(fp,";");
		/* printf("%d",h);  */
		h = (h+1) % 4;
	}
	
	fclose(fp);

	exit(0);
}

