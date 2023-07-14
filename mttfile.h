#ifndef MTTFILE_H
#define MTTFILE_H

#ifdef _WIN32
#include <Windows.h>
#else
#include <fcntl.h>
#include <stdio.h>
#endif
#include <stdint.h>
#include <stdlib.h>

struct mttfile_file_t
{
	char *name, *cont;
#ifdef _WIN32
	DWORD size;
#else
	long size;
#endif
	uint8_t flags;
};

enum mttfile_file_flags_t
{
	CONT_AS_VEC = 0,
	CONT_AS_STR = 1,
	DONT_RESIZE_CONT = 0,
	RESIZE_CONT = 2,
};

#ifdef _WIN32
DWORD mttfile_load(struct mttfile_file_t *file, DWORD off, DWORD lim);
#else
long mttfile_load(struct mttfile_file_t *file, long off, long lim);
#endif

#endif