# CSI281 Assignment 10

In this assignment you will be implementing Jarnik's algorithm on a weighted graph class to find a minimum-spanning-tree. You will also be answering some questions in `questions.txt`.

You should follow the pseudo-code we went over in class. You may not add any additional methods to `WeightedGraph`. The beginning and end of the `mst()` function are already defined. You must reuse this code.

NOTE: Because the code you need to add to `mst()` is only about 10-15 lines, I will not be helping you write these few lines. I am happy to answer as many conceptual questions about how the rest of the code works, or how Jarnik's algorithm works as you would like, but there is so little code to write here, that I don't think it's appropriate for me to help you write it. Again, I am not saying I am not open to questions, just that I won't help you write the literal code for `mst()`.

NOTE: If you prefer to use different pseudocode than we went over in class (Python code really), feel free to. Just cite it next to your `mst()` method. Please do not look at other C++ implementations of Jarnik's algorithm. 

REMINDER: In addition to being covered in class, Jarnik's algorithm was covered in Chapter 4 of Classic Computer Science Problems in Python, your assigned reading for Week 9.

## Basic Instructions

1. Download the contents of this repository.
2. Create your own private repository and add the contents of this repository to it.
3. Add me (@davecom) as a collaborator on your private repository.
4. Implement the missing parts where it says "YOUR CODE HERE"
5. Test it by following the build directions below.
6. Answer all of the questions in `questions.txt` in your own file `answers.txt`.
7. Submit the URL to your private repository on Canvas.

## Standard Library Restrictions

There are no standard library restrictions.

## Directory Structure and Files

- `/` Main directory including this `README.md`, the build scripts, the make files, and `questions.txt`.
- `/lib` A library for testing your work. There's no need to touch this.
- `/src` Source files, some of which you should modify and some of which you should not.

### Specific Files

*indicates do not modify
&indicates you must modify
%indicates you must create

- `GNUMakefile`* make file for GNU Make on macOS and GNU/Linux
- `Makefile`* make file for nmake/Visual Studio on Windows
- `README.md`* this file
- `LICENSE` MIT License
- `questions.txt`* Questions that you are expected to answer.
- `answers.txt`% Your answers to the questions in `questions.txt`

- `lib/catch.h`* a unit testing library

- `src/WeightedGraph.h`& the `WeightedGraph` class
- `src/main.cpp` the main file that runs the tests
- `src/test.cpp`* the unit tests to prove your code works

## Building and Running

### macOS and GNU/Linux

CD to the appropriate directory and run `make` and `./assignment10` to run all of the tests. Run `make clean` to remove all objects files, and the executable.

### Windows

From the start menu (assuming you have installed Visual Studio 2019) open the "Developer Command Prompt." CD to the appropriate directory and run `nmake` and `assignment10` to run all of the tests. Run `nmake clean` to remove all objects files, and the executable.

## Checklist for Submission

- [ ] Did you add me (@davecom) as a collaborator on the repository?
- [ ] Did you replace every area that said "YOUR CODE HERE" with your code?
- [ ] Did you ensure you are passing all of the unit tests?
- [ ] Did you cite all sources, especially any place that you copied code from? Put code citations right next to where you inserted it.
- [ ] Did you add sufficient comments?
- [ ] Did you double check your code for good style?
- [ ] Did you remember to free any memory you manually allocated on the heap?
- [ ] Did you put your name below mine at the top of any files you modified and any other appropriate places?
- [ ] Did you try cleaning, building, and running once to make sure everything is in working order before submitting?
- [ ] If you were working with an IDE, did you test building on the command line with make or nmake? I will only test your work with make or nmake.
- [ ] Did you check the repository is free of your object files and other garbage and just contains source files?
- [ ] Did you remember to include your `answers.txt` file with answers to every question?
- [ ] Did you submit the URL to your repository on Canvas?
