#ifndef MTTFILE_H
#define MTTFILE_H

#include <stdio.h>
#include <stdlib.h>

struct mttfile_file_t
{
	char *name, *cont;
	size_t size;
	int flags;
};

enum mttfile_file_flags_t
{
	CONT_AS_VEC = 0,
	CONT_AS_STR = 1,
	DONT_RESIZE_CONT = 0,
	RESIZE_CONT = 2,
};

size_t mttfile_load_file(struct mttfile_file_t *file, long off, size_t lim);

#endif