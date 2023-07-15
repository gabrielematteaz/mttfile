# mttfile
My personal C library to handle files stuff

# Structs
- mttfile_file_t

# Enums
- mttfile_file_flags_t

# Functions
- mttfile_load_file

# Example
```c
#include "mttlib/mttfile/mttfile.h"

int main(void)
{
	struct mttfile_file_t file = { "test.c", .flags = CONT_AS_STR };
	size_t lim = mttfile_load_file(&file, 0, 1000);

	if (lim)
	{
		printf("%zu %zu\n", file.size, lim);
		puts(file.cont);
		free(file.cont);
	}

	return 0;
}
```
