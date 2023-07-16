#ifndef MTTFILE_H
#define MTTFILE_H

#include <stdio.h>
#include <stdlib.h>

enum mttfile_flags_t
{
	STRING = 1,
	RESIZE = 2,
};

size_t mttfile_load_file(const char *name, char **cont, long off, size_t *lim, enum mttfile_flags_t flags);

#endif