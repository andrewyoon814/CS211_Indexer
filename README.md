# CS211_Indexer
Indexer project done in Prof. Nagakaratte's Comp Arch class in Fall 2015.

All use of this code must be consistent with the [DCS Academic Integrity Policy.] (https://www.cs.rutgers.edu/academic-integrity/introduction)


Short Assignment Description:

Our task is to write a program that reads in a collection of dictionary and data file pairs and generates statistics about
each pair. There are two parts to this assignment. The first part of the assignment is for regular credit and the second part of the assignment is extra credit.


Your task in the First part is to write a C program called first that reads an input file, which contains
a list of dictionary and data file pairs, and generates statistics for each pair.
Each line in your input file contains the names of the dictionary and data files. You have to read the
file and generate the following statistics:

1. For every word w in the dictionary file, count the number of words w0 that occur in the data file
such that w0 = w.
2. For every word w in the dictionary file, count the number of words w0 that occur in the data file
such that w is a proper prefx of w0 (we shall say w0 is a superword of w).


Your task in this second part is to write a C program called second that reads a input file, which contains
a list of dictionary and data file pairs, and generates statistics for each pair.
Each line in your input file contains the names of the dictionary and data file. You have to read the
dictionary and data file and generate the following statistics:

1. For every word w in the dictionary file, count the number of words w0 that occur in the data file
such that w0 = w.
2. For every word w in the dictionary file, count the number of words w0 that occur in the data file
such that w0 is a proper prefix of w.

  For example, both \Boo" and "bOo" are proper prefixes of \bOOk", which itself is a proper prefix of \booKING"
  
  
The hard part about this assignment was processing the HUGE data files. I did not include the auto grader but it would time you out if your program exceeded a certain time. 
 
In order to efficiently finish the project, a data structure called a [TRIE](https://en.wikipedia.org/wiki/Trie) was necessary to be used.

