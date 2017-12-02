# hexview
A simple and short hex viewer written in C

# Usage:
```
hexview <file source> [# bytes to display max 255 bytes]
```

# Example output:
```
        Offset(h)  0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
0000000000000000: 23 69 6E 63 6C 75 64 65 20 3C 73 74 64 69 6F 2E #include <stdio.
0000000000000010: 68 3E 0D 0A 69 6E 74 20 6D 61 69 6E 28 29 0D 0A h>  int main()
0000000000000020: 7B 0D 0A 09 70 72 69 6E 74 66 28 22 48 65 6C 6C {   printf("Hell
0000000000000030: 6F 2C 20 57 6F 72 6C 64 21 22 29 3B 0D 0A 09 72 o, World!");   r
0000000000000040: 65 74 75 72 6E 20 30 3B 0D 0A 7D                eturn 0;  }
```
