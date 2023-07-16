# mttfile
My personal C library to handle files stuff

# Enums
- mttfile_flags_t

# Functions
- mttfile_load_file

# Example
```c
#include "mttlib/mttfile/mttfile.h"

int main(void)
{
	char *cont;
	size_t lim = 0, size = mttfile_load_file("test2.c", &cont, 0, &lim, STRING);

	if (size)
	{
		printf("%zu %zu\n", size, lim);
		puts(cont);
		free(cont);
	}

	return 0;
}
```
