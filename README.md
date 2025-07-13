# CPlate
Template for the `nomadic standard` that I have created.
This is the standard that I use for projects as of 2025 and onwards.
Not all my projects use this standard, but as of July 2025 I am using this for new C projects.
This standard for C programming has some unconvential things in it, but this is just what I use for hobby projects.

## The Nomadic Standard
In a project, all source code is stored in the `src` folder.
Inside the src folder are `main` and `header`.
The main folder should contain main.c, and nothing else. This is the entry point.
Main.c controls command line arguments, and text output.
It controls how the input is used to redirect control to header files.
Main.c also controls the programState variable, which keeps track of the current state.
The states are defined in the programStates header file.
```c
#define PROGRAM_ALL_SUCCESS 0
#define PROGRAM_GENERAL_FAILURE -1
#define PROGRAM_ERROR_CODE_ONE 1
#define PROGRAM_ERROR_CODE_TWO 2
```
Each time main calls a function, it gives the function a pointer to this variable.
The function being called updates it according to what happens during that functions procesing.
Because the error code is not returned, both a success code and a result can be obtained from a function.<br>
Standard C:
```c
int addToNumber(int startingNumber) {
  int newNumber = startingNumber + 2;
  if (error) {
    return PROGRAM_ERROR_FAILED_TO_ADD;
  }
  return startingNumber;
}
```
Nomadic Standard:
```c
int addToNumber(int *successVariable, int startingNumber) {
  int newNumber = startingNumber + 2;

  // Failed, set success variable to correct code so main.c knows what to do with the returned value
  if (error) {
    *successVariable = PROGRAM_ERROR_FAILED_TO_ADD;
    return 0;
  }

  // If it does, work, return the value and set the success code to make sure main knows the function succeeded
  *successVariable = PROGRAM_ALL_SUCCESS;
  return newNumber
}
```

In the `header` file, functions are defined in pairs of header files with a .h and .c file of the same name.
There should be at least 2 headers. 1 for defining the states (`programStates.h`), and 1 or more for the general functions for the program, along with the needed .c implementations.

Each project should have a README.md and build.sh script as well.
All documentation should go in the README unless it is very large, in which case you can create other documentation files with links from the README.
The build.sh script should use cd to go into the src/main folder, generate an exectuable, and then move it into the build folder.

## Multithreaded Programs
When creating a multithreaded program, you should have a main program state variable, but I would also recommend giving each thread a state variable.
An indivdual thread worker function should not interact with the main program state variable, as multiple threads trying to update the state will cause race conditions.
Instead, the main program can observe the state of each thread, and modify its state based on that in a more controlled way.
