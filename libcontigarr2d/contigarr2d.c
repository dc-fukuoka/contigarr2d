#include "contigarr2d.h"
#include <stdlib.h>

/*
 * to be able to use dynamic a[i][j] in contigious region
 * ex: a[2][3]
 * {}: index(pointer) (): data
 * index | data
 * (double*)  (double)
 * {0}{1} (2)(3)(4) (5)(6)(7)
 * {0}->(2)
 * {1}->(5)
 *
 * since this method uses contigious allocation, just free(p) is enough
 * but this method uses additional memory
 */

double **dalloc_contig_array2d(size_t imax, size_t jmax)
{
        int i;
        size_t index = imax*sizeof(double*);
        size_t data = imax*jmax*sizeof(double);
        /* allocate index and data simultaneously */
        double **ptr = (double**)malloc(index+data);
	if (!ptr)
		return NULL;
        for (i=0; i<imax; i++) {
                ptr[i] = (double*)(ptr+imax)+i*jmax;
        }
        return ptr;
}
