#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("Error: Expected one argument, found %d\n", argc - 1);
        return -1;
    }

    int file = open(argv[1], O_RDONLY);

    int lines = 0;
    int words = 0;
    int chars = 0;
    int prevPrevChar = -1;
    int tabs = 0;
    
    int prevChar = -1;
    char currChar;

    if (file < 0) {
        printf("Error: Could not open the file %s\n", argv[1]);
        return -1;
    }
    
    while (read(file, &currChar, 1) > 0) {
        chars++;


        if (currChar == '\n'){
            lines++;
        }

        if (isspace(currChar)) {
            if (prevChar != 32 && prevChar != 2 && prevChar != 3 && prevChar != -1 && prevChar != 10){
                words++;
            }

        }

        if (isspace(currChar) && prevChar == 32 && prevPrevChar == 32) {
            tabs++;
        }



        prevPrevChar = prevChar;
        prevChar = currChar;

    }

    if (chars == 0) {
        printf("Error: File is empty\n");
        return -1;
    }

    if (prevChar >= 33 && prevChar <= 126 ) {
        lines++;
        words++;
    }

    if (chars > 0 && lines == 0) {
        lines = 1;
    }

    chars = chars - (2*tabs);

    printf("%d %d %d %s\n", lines, words, chars, argv[1]);
    close(file);

    return 0;
}
