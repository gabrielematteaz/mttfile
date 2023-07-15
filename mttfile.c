#include "mttfile.h"

size_t mttfile_load_file(struct mttfile_file_t *file, long off, size_t lim)
{
	FILE *f;
	int flags;
	size_t size;
	char *cont;

	if (file != NULL)
	{
		f = fopen(file->name, "rb");

		if (f != NULL)
		{
			flags = file->flags;

			if (lim == 0)
			{
				fseek(f, 0, SEEK_END);
				lim = ftell(f);
				size = lim;

				if (flags & CONT_AS_STR) size++;
			}
			else
			{
				size = lim;

				if (flags & CONT_AS_STR) lim--;
			}

			if (fseek(f, off, SEEK_SET) == 0)
			{
				cont = malloc(size);

				if (cont != NULL)
				{
					lim = fread(cont, 1, lim, f);

					if (flags & CONT_AS_STR)
					{
						cont[lim] = 0;

						if (flags & RESIZE_CONT)
						{
							size = lim + 1;
							cont = realloc(cont, size);
						}
					}
					else if (flags & RESIZE_CONT)
					{
						size = lim;
						cont = realloc(cont, size);
					}

					file->cont = cont;
					file->size = size;

					fclose(f);

					return lim;
				}
			}

			fclose(f);
		}
	}

	return 0;
}