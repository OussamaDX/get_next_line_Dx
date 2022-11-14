# get_next_line_Dx

NEED TO KNOW THIS : 

static int x = 5;
static int y;

The static variable x is stored in the initialized data segment and the static variable y is stored in the BSS segment.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Write a function that will store, in the parameter “line”, a line that has been read from the given file descriptor.

Return values
The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed (meaning read has returned 0), or if an error has happened respectively.

When you’ve reached the End Of File, you must store the current buffer in “line”. If the buffer is empty you must store an empty string in “line”.
When you’ve reached the End Of File, your function should keep 0 memory allocated with malloc except the last buffer that you should have stored in “line”.
What you’ve stored in “line” should be free-able.
Final words
Calling your function get_next_line in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines. Therfore, make sure that your function behaves well when it reads from a file, from the standard output, from a redirection etc. For the mandatory part, no call to another function will be done on the file descriptor between 2 calls of get_next_line.

Finally we consider that get_next_line has an undefined behavior when reading from a binary file. You may make this work accordingly, but its not part of the bonus nor is it required.

Testing
You can use francinette tester :

https://github.com/xicodomingues/francinette.git
