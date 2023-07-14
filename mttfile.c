#include "mttfile.h"

#ifdef _WIN32
DWORD mttfile_load(struct mttfile_file_t *file, DWORD off, DWORD lim)
{
	HANDLE f;
	DWORD filesize;
#else
long mttfile_load(struct mttfile_file_t *file, long off, long lim)
{
	int f;
	long filesize;
#endif
	uint8_t flags;
	char *cont;

	if (file != NULL)
	{
#ifdef _WIN32
		f = CreateFileA(file->name, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (f != INVALID_HANDLE_VALUE)
		{
#else
		f = open(file->name, O_RDONLY);

		if (f != -1)
		{
#endif

		if (lim == 0)
		{
#ifdef _WIN32
			lim = SetFilePointer(f, 0, NULL, FILE_END);
#else
			lim = lseek(f, 0, SEEK_END);
#endif
		}

		if (off < lim)
		{
			lim = lim - off;
#ifdef _WIN32
			if (SetFilePointer(f, off, NULL, FILE_BEGIN) != INVALID_SET_FILE_POINTER)
#else
			if (lseek(f, off, SEEK_SET) != -1)
#endif
			{
				flags = file->flags;

				if (flags & CONT_AS_STR) cont = malloc(lim + 1);
				else cont = malloc(lim);

				if (cont != NULL)
				{
#ifdef _WIN32
					if (ReadFile(f, cont, lim, &filesize, NULL) == TRUE)
					{
#else
					filesize = read(f, cont, lim);

					if (filesize != -1)
					{
#endif
						if (flags & CONT_AS_STR)
						{
							cont[filesize] = 0;
							lim++;
							filesize++;
						}

						if (flags & RESIZE_CONT) cont = realloc(cont, filesize);

						file->cont = cont;
						file->size = filesize;
					}
					else free(cont);
				}
			}
		}

#ifdef _WIN32
		CloseHandle(f);
#else
		close(f);
#endif
		}

		return lim;
	}

	return 0;
}