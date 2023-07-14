# mttfile
My personal C library to handle files stuff

# Structs
- mttfile_file_t

# Enums
- mttfile_file_flags_t

# Functions
- mttfile_load

# Example
This example takes at most 1000 bytes (As a string). "filesize" and "file.size" could be different depending on the actual size of the file ("file.cont" contains the actual number of bytes read)
```c
#include "mttlib/mttfile/mttfile.h"
#include <stdio.h>

int main(void)
{
	struct mttfile_file_t file = { "test.c", .flags = CONT_AS_STR | RESIZE_CONT };
	DWORD filesize = mttfile_load(&file, 0, 1000);

	if (filesize)
	{
		printf("%u %u\n%s", filesize, file.size, file.cont);
		free(file.cont);
	}
}
```
