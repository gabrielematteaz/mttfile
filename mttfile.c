#include "mttfile.h"

struct mttfile_cont_t mttfile_load_file(const char *name, long off, size_t lim, int str)
{
	FILE *file = fopen(name, "rb");
	struct mttfile_cont_t cont;

	if (file == NULL)
	{
		cont.data = NULL;

		return cont;
	}

	if (lim == 0)
	{
		fseek(file, 0, SEEK_END);
		lim = ftell(file);
		cont.size = lim;

		if (str) cont.size++;
	}
	else
	{
		cont.size = lim;

		if (str) lim--;
	}

	cont.data = malloc(cont.size);

	if (cont.data != NULL)
	{
		fseek(file, off, SEEK_SET);
		cont.size = fread(cont.data, 1, lim, file);
		
		if (str) cont.data[cont.size] = 0;
	}

	fclose(file);

	return cont;
}