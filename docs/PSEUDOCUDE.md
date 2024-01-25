main
* initialize app
* check if we have input flags
  to support something like `./main -f grocer.txt` in order to
  allow someone to test the app by loading a lot of data quickly
* if we have an input file we should feed the arguments to the app
  assuming menu item one

app
* init data object
* init menu object
* execute menu function one if called explicitly
* show menu if called
* sava data

menu
* opt 1
  * search for string in data
* opt 2
  * print numeric values for items purchased
* opt 3
  * print historgram for items purchased
* opt 4
  * exit

data
* store data in std::map<string, unsigned int> during operation
* load data from `frequency.dat` (if there is any)
  * frequency.dat should be stored as packed binary data
    we should figure out if classes can be packed like this
    or if we use structs (allegedly they are the same in C++)
* save data
