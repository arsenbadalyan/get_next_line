# get_next_line

This project is about programming a function that returns a line read from a file descriptor. The function `get_next_line` reads a line from a file descriptor (such as `stdin` or a file) and returns that line without the newline character at the end. Subsequent calls to `get_next_line` will return the next line from the file descriptor, allowing for sequential reading of a file line by line.

## Features
- Reads lines from a file descriptor
- Handles different file descriptors (e.g., `stdin`, files)
- Returns each line read without the newline character

## Usage
To use the `get_next_line` function in your C projects, include the `get_next_line.h` header file and link with the appropriate source files.

```c
#include "get_next_line.h"

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("Line: %s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

## Contributors
- [Arsen Badalyan](https://github.com/arsenbadalyan)

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
