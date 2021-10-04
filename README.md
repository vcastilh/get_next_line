# Get Next Line
![Medal](/images/get_next_linem.jpg "Project Medal")

### **Summary:** 
The aim of this project is to code a function that returns a line, read
from a file descriptor.

#### NAME
get_next_line - get line from a file descriptor

#### SYNOPSIS
```c
#include "get_next_line.h"

char	*get_next_line(int fd);
```
#### DESCRIPTION
**get_next_line()** read a file descriptor and search for a '\n'(a line).
If fd is -1, get_next_line() may detect the error.

#### RETURN VALUE
On success, the line read. If no '\n' is found and it reaches end of file, return
what was read. If there is nothing to read, return NULL.

