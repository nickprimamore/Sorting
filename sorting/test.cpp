#include "sorting.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define TOTAL_TESTS 10


bool isSorted(std::string arr[], int len){
  for(int i = 1; i < len; i++){
    if(arr[i-1]> arr[i]){
      return false;
    }
  }
  return true;
}


bool run_test(int test_number) {
  switch(test_number) {
  case 1: {
    // test01 :(description here)
    //(implementation here)
    break;
  }

  case 2: {
    // test02: (description here)
    // (implementation here)
    break;
  }

  case 3: {
    // test03 :(description here)
    //    (implementation here)
    break;
  }

    /*
  case 4: {
    // test04 : (description here)
    (implementation here)
    break; // if your test suceeds, break
  }
    */

  default: {
    printf("ERROR! Test number %d was not found!\n", test_number);
    exit(1);
  }
    
  }
  // test must have passed.
  return true;
}

int main() {
  int num_fail = 0;
  for (int tn = 1; tn <= TOTAL_TESTS; tn++) {
    printf("- running test # %02d ... ", tn);
    int result = run_test(tn);
    printf("%s\n", (result == true ? "succeed" : "FAIL"));
    if (result == false) num_fail++;
  }
  printf("SUMMARY: %d FAIL, %d succeed\n", num_fail, TOTAL_TESTS - num_fail);
}

  
