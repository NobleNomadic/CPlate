#include "../header/header.h"
#include "../header/programStates.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_LINE_ARGUMENT_COUNT 3

// Entry point (Function explainations as a single line comment)
int main(int argc, char *argv[]) {
  // Check cmd line args first
  if (argc < CMD_LINE_ARGUMENT_COUNT) {
    fprintf(stderr, "Usage: %s <Action> <Argument>", argv[0]);
    return 1;
  }

  /* (Explain purpose of variables and functions with longer blocks)
   Create a variable in the main function to keep track of errors.
   Default to 1, change to 0 once success is reached
   Use this variable in all functions after the cmd line arguments are checked.
  */
  int programState = -1;

  // dothat argument
  if (strcmp(argv[1], "dothat") == 0) {
    int argument = atoi(argv[2]);

    printf("[*] Doing that\n");
    int variable = dothat(&programState, argument);
    /*
      Logging is done in the main file by checking programSuccess variable with:
      [*] for notifying
      [+] for a success
      [-] for failure
      Debug by using: [DEBUG] {Program state variable}
    */
    // printf("[DEBUG] %d\n", programState);
    if (programState == PROGRAM_GOOD_STATE) {
      printf("[+] Variable is %d\n", variable);
      // Return early to avoid wasted time on next checks
      return programState;
    }
    // On failures, print a general error message saying an error happened
    // Then print the specific fail code
    else if (programState == PROGRAM_FAILURE_STATE) {
      printf("[-] Failed to dothat: %d\n", PROGRAM_FAILURE_STATE);
      return programState;
    }
  }

  // Keep a backup of the program success code at the end
  return programState;
}
