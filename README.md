# mttfile
My personal C library to handle files stuff

# Structs
- mttfile_cont_t

# Functions
- mttfile_load_file
- mttfile_load_wfile

# Example
```c
#include "mttfile.h"

int main(void)
{
	struct mttfile_cont_t cont = mttfile_load_file("test.c", 0, 0, 1);

	if (cont.data == NULL) return 1;

	puts(cont.data);

	return 0;
}
```
