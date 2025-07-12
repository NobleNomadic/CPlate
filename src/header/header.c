#include "header.h"
#include "programStates.h"

int dothat(int *successVariable, int argument) {
  // Peform functions here
  int returnValue = argument + 5;
  // Check if there was an error here, then set the successVariable
  // if (errorX) {
  //   *successVariable = PROGRAM_ERROR_CODE_X
  // }

  // No errors, set successVariable and return the value
  *successVariable = PROGRAM_GOOD_STATE;
  return returnValue;
}
