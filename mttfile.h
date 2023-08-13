#ifndef MTTFILE_H
#define MTTFILE_H

#include <stdio.h>
#include <stdlib.h>

struct mttfile_cont_t
{
	char *data;
	size_t size;
};

struct mttfile_cont_t mttfile_load_file(const char *name, long off, size_t lim, int str);

#endif