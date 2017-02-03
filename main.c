#include "contigarr2d.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	double **p_contig = NULL, **p_noncontig = NULL;
	size_t imax = 0, jmax = 0;
	size_t i, j;

	if (argc == 1) {
		fprintf(stderr, "usage: %s <imax> <jmax>\n", argv[0]);
		return -1;
	}
	imax = argv[1] ? atol(argv[1]) : 2;
	jmax = argv[2] ? atol(argv[2]) : 2;

	/* contiguous method */
	p_contig = dalloc_contig_array2d(imax, jmax);

	/* non-contiguous usual method */
	p_noncontig = (double**)malloc(imax*sizeof(*p_noncontig));
	for (i=0; i<imax; i++) {
		p_noncontig[i] = (double*)malloc(jmax*sizeof(**p_noncontig));
	}

	for (i=0; i<imax; i++) {
		for (j=0; j<jmax; j++) {
			p_contig[i][j] = 10.0*(double)i+(double)j;
			p_noncontig[i][j] = p_contig[i][j];
		}
	}
	
	printf("non-contiguous usual method:\n");
	for (i=0; i<imax; i++) {
		for (j=0; j<jmax; j++) {
			printf("array[%2d][%2d]: %p: %6.1lf\n", i, j, &p_noncontig[i][j], p_noncontig[i][j]);
			if (j==jmax-1)
				printf("\n");
		}
	}
	printf("contiguous allocate method(dalloc_contig_array2d()):\n");
	for (i=0; i<imax; i++) {
		for (j=0; j<jmax; j++) {
			printf("array[%2d][%2d]: %p: %6.1lf\n", i, j, &p_contig[i][j], p_contig[i][j]);
			if (j==jmax-1)
				printf("\n");
		}
	}

	free(p_contig);
	for (i<0; i<imax; i++) {
		free(p_noncontig[i]);
	}
	/* everything is in contigous region, so only one free() is enough. */
	free(p_noncontig);
	return 0;
}
