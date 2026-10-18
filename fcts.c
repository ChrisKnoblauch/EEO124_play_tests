/* stdio_demo.c
   Demonstrates the key functions in <stdio.h>.
   The only user input needed is three short prompts (an integer, a letter, a name).
   Every file the program reads is created by the program itself first. */

#include <stdio.h>                          // declares printf, scanf, fopen, and all the functions below

int main(void)                              // program starts here
{
    int num;                                // an integer read from the keyboard
    int a, b, c;                            // three integers read from a file
    int pos;                                // a position (byte offset) in a file
    int n;                                  // an integer read from a string
    int ch;                                 // int (not char) so it can hold EOF
    int nums[5] = {1, 2, 3, 4, 5};          // array written to a binary file
    int copy[5];                            // array that the binary file is read back into
    char letter;                            // one character typed by the user
    char name[50];                          // line typed by the user (max 49 characters)
    char line[100];                         // one line read from a file
    char text[50];                          // string built by sprintf
    FILE *fp;                               // file pointer used for all file operations

    /* ================= OUTPUT TO THE SCREEN ================= */

    printf("--- OUTPUT ---\n");             // printf: formatted output to the screen
    printf("Age: %d\n", 20);                // %d is replaced by the integer 20
    putchar('A');                           // putchar: print a single character
    putchar('\n');                          // putchar can print the newline character too
    puts("Hello");                          // puts: print a string and add a newline automatically
    fputs("fputs to stdout\n", stdout);     // fputs: like puts but no automatic newline; stdout = screen
    fprintf(stdout, "fprintf to stdout\n"); // fprintf: printf that can target any stream
    fprintf(stderr, "This goes to stderr\n"); // stderr: separate stream meant for error messages

    /* ================= INPUT FROM THE KEYBOARD ================= */

    printf("\n--- INPUT ---\n");             // section heading
    printf("Enter an integer: ");           // prompt the user
    scanf("%d", &num);                      // scanf: read a formatted value (& gives the variable's address)
    printf("You entered %d\n", num);        // show what scanf read
    getchar();                              // getchar: here it just removes the newline scanf left behind
    printf("Type one letter: ");            // prompt the user
    letter = getchar();                     // getchar: read a single character
    printf("You typed %c\n", letter);       // show the character
    getchar();                              // remove the newline left behind by the previous getchar
    printf("Enter your name: ");            // prompt the user
    fgets(name, 50, stdin);                 // fgets: read a whole line safely (never more than 49 chars)
    printf("Hello, %s", name);              // name already ends in a newline, so no \n needed
    /* gets() is NOT used: it has no size limit, so it was removed from the C standard. */

    /* ================= WRITING A TEXT FILE ================= */

    printf("\n--- WRITING A FILE ---\n");    // section heading
    fp = fopen("demo.txt", "w");            // fopen: open for writing ("w" erases any old contents)
    if (fp == NULL) {                       // fopen returns NULL when it fails
        printf("Could not open demo.txt\n");// tell the user what went wrong
        return 1;                           // stop the program with an error code
    }
    fprintf(fp, "Name: %s\n", "Chris");     // fprintf: formatted output into the file
    fputs("Line two\n", fp);                // fputs: write a string into the file
    fputc('X', fp);                         // fputc: write one character into the file
    fputc('\n', fp);                        // fputc: write the newline character
    fclose(fp);                             // fclose: close the file so everything is saved
    printf("demo.txt written\n");           // confirm

    /* ================= READING A TEXT FILE ================= */

    printf("\n--- READING A FILE ---\n");    // section heading
    fp = fopen("demo.txt", "r");            // open the same file for reading ("r")
    if (fp == NULL) {                       // check that it opened
        printf("Could not open demo.txt\n");// report the problem
        return 1;                           // stop with an error code
    }
    ch = fgetc(fp);                         // fgetc: read one character from the file
    printf("First character: %c\n", ch);    // prints N
    rewind(fp);                             // rewind: jump back to the start of the file
    while (fgets(line, 100, fp) != NULL) {  // fgets: read one line at a time; returns NULL at end of file
        printf("Line: %s", line);           // print each line (it already contains its newline)
    }
    rewind(fp);                             // go back to the start again
    printf("Whole file with fgetc: ");      // label for the next output
    while ((ch = fgetc(fp)) != EOF) {       // EOF is the value fgetc returns when the file runs out
        putchar(ch);                        // print each character as it is read
    }
    fclose(fp);                             // close the file

    /* ================= fscanf: FORMATTED READ FROM A FILE ================= */

    printf("\n--- FSCANF ---\n");            // section heading
    fp = fopen("numbers.txt", "w");         // create a file holding three integers
    fprintf(fp, "10 20 30\n");              // write the numbers separated by spaces
    fclose(fp);                             // close it
    fp = fopen("numbers.txt", "r");         // reopen it for reading
    fscanf(fp, "%d %d %d", &a, &b, &c);     // fscanf: like scanf but reads from a file
    printf("Read from file: %d %d %d\n", a, b, c); // show the three numbers
    fclose(fp);                             // close the file

    /* ================= FILE POSITION: fseek, ftell, rewind ================= */

    printf("\n--- FILE POSITION ---\n");     // section heading
    fp = fopen("demo.txt", "r");            // open demo.txt for reading
    fseek(fp, 0, SEEK_END);                 // fseek: move 0 bytes from the end of the file
    pos = ftell(fp);                        // ftell: report the current position (= file size here)
    printf("File size: %d bytes\n", pos);   // show the size
    fseek(fp, 6, SEEK_SET);                 // move 6 bytes from the start (skips "Name: ")
    fgets(line, 100, fp);                   // read from that spot to the end of the line
    printf("After skipping 6 bytes: %s", line); // prints Chris
    rewind(fp);                             // rewind: same as fseek(fp, 0, SEEK_SET)
    printf("Position after rewind: %ld\n", ftell(fp)); // prints 0
    fclose(fp);                             // close the file

    /* ================= BINARY FILE: fwrite and fread ================= */

    printf("\n--- BINARY FILE ---\n");       // section heading
    fp = fopen("nums.bin", "wb");           // "wb" = write binary
    fwrite(nums, sizeof(int), 5, fp);       // fwrite: write 5 items, each sizeof(int) bytes
    fclose(fp);                             // close the file
    fp = fopen("nums.bin", "rb");           // "rb" = read binary
    fread(copy, sizeof(int), 5, fp);        // fread: read 5 items into the copy array
    fclose(fp);                             // close the file
    printf("Third number: %d\n", copy[2]);  // prints 3 because the data survived the round trip

    /* ================= STRINGS: sprintf and sscanf ================= */

    printf("\n--- STRING FUNCTIONS ---\n");  // section heading
    sprintf(text, "%d apples", 5);          // sprintf: printf that writes into a string
    printf("%s\n", text);                   // show the string that was built
    sscanf("42", "%d", &n);                 // sscanf: scanf that reads from a string
    printf("n = %d\n", n);                  // prints 42

    /* ================= ERRORS: perror ================= */

    printf("\n--- ERROR MESSAGE ---\n");     // section heading
    fp = fopen("missing.txt", "r");         // try to open a file that does not exist
    if (fp == NULL) {                       // fopen failed, so fp is NULL
        perror("Error");                    // perror: prints "Error: " followed by the system's reason
    }

    /* ================= RENAME AND DELETE ================= */

    printf("\n--- RENAME AND REMOVE ---\n"); // section heading
    fp = fopen("old.txt", "w");             // create a file so there is something to rename
    fclose(fp);                             // close it
    if (rename("old.txt", "new.txt") == 0) {// rename: returns 0 on success
        printf("Renamed old.txt to new.txt\n"); // confirm
    }
    if (remove("new.txt") == 0) {           // remove: delete a file, returns 0 on success
        printf("Deleted new.txt\n");        // confirm
    }

    return 0;                               // program ended normally
}