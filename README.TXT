LAB 8: CHEATERS README - ejo527

PURPOSE: The purpose of this lab is to detect suspicious activity (plagiarism) within a set of documents

HOW TO RUN CODE:
    1) unzip cheaters_ejo527.zip
    2) put all .cpp files, .h files, and makefile into a linux directory
    3) ensure that some document directory (sm_doc_set) is in the current directory as all .cpp,.h ,etc files
    4) type and input command "make"
    5) type "ls" (and press enter) to the command line to check if executable was generated: "./plagiarismCatcher"
    6) to call the executable, input "./plagiarismCatcher DIR P M", where DIR is the folder containing all the
       txt files you want to compare, P being a integer describing how to divide each txt file (ie p=6 means we will
       collect all 6 word sequences in a txt file), and M being the baseline "suspicion index" required for the
       comparison to be returned to the user

       example ./plagiarismCatcher sm_doc_set 6 200

    7) view results to see which students have been naughty, no repeats will be generated
    8) make sure to have an amazing rest of the year :           ^)
       thank you so much for your hard work, grading copious amounts of labs is certainly not the most
       interesting thing to do in the world. Your effort has made this semester more pleasant than I

NAMES OF ALL SOURCES FILES:
    - main.cpp (runs program)
    - Essay.h, Essay.cpp
    - PrimeGenerator.h, PrimeGenerator.cpp
    - HashTable.h, HashTable.cpp


Brief Description of Classes and Algorithms used:
----------------------------------------------
Essay:
    General Description: Essay acts as a container to hold all possible p-sized filtered substrings within an essay.
                         Said substrings are stored in a vector, which can be inserted into a HashTable class, or compared
                         with a current HashTable

PrimeGenerator:
    General Description: PrimeGenerator is a support class (but not a subclass) of HashTable, providing a complete list of
                         from 2 to n (user specifies n), in order so that the HashTable can support varying sizes

    Algorithms Used: I used a common prime generation algorithm known as the sieve of eratosthenes, which provides
                     all primes from 1 to n (perfect for what I intended).

    Personal Set Limits: Since the amount of docs and size of docs to be tested is primarily going to come from
                         the small doc set - I set the limit on prime number generation to be 40000 (MAX_NUM).
                         This number can be changed if so desired.

HashTable:
    General Description: Simple hash table, implemented using a vector of vector<strings>, collisions on insertion are
                         handled with chaining.

    Hash Function Used: Polynomial character hashing - take the sum of every character multiplied by its index and
                        modulo the sum by the current size of the hash table (which is guaranteed to be a prime number)

NOTEABLE ISSUES
- Clion sometimes cannot properly decrypt certain characters - thus for some of my files the � character appeared
  inexplicably, this may knock some my results off by a tiny bit here and there.
- The abf0704.txt and edo26.txt comparison is off by a large degree, however, in reading different Piazza posts,
  I believe the result I obtained is valid after re-evaluation

