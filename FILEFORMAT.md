DAT File
---

We store our .dat file as follows:

* The first four bytes of the file are the length of the list contained within
  * This gives us a hard limit of 2\*\*32 items
    which is unlikely to be exceeded by the grocer

* The next byte in the file is the length of the following string
  * e.g. 'potato' > 0b00000110
  * This has a hard limit of item names = 256c

* The next four bytes are the integer for how many of the item we have
  * Again this gives us a hard limit of 2\*\*32 items but
    I don't think the grocer will have that many potatoes


To read this file the program will read the first four bytes
and use this integer for outer loop control.

The program reads the next byte to determine the string length.
This byte will tell the program how many characters to read

and it will read that many.
The program will then read the next four bytes as an integer.

This process repeats until the outer loop is exhausted.



Writing the file is simply the reverse of this process.

The program will determine the current length of the map in menory
and write the first four bytes to the file as the number of items to follow.

The program will then write the list into the file following the above specification.
