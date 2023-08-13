# mttfile
My personal C library to handle files stuff

# Functions
- mttfile_load_file

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
