# Word-Counter
This is a C program that counts the number of lines, words, and characters in a given file. It takes a single command-line argument 
representing the file name. 

- The program opens the file and reads its contents character by character.
- It increments the line count whenever a newline character is encountered.
- Word boundaries are determined by whitespace characters, and the program increments the word count accordingly.
- It handles special cases such as consecutive spaces or tabs to ensure accurate word counting.
- Finally, it prints the line count, word count, character count, and the filename to the console.

In addition, the wordcount.c file handles various edge cases, such as empty files or files with consecutive spaces or tabs, to ensure accurate counting.
