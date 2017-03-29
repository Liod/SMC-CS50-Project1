#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define ACCOUNT_SIZE 10

int helpmenu() {
  printf("Banking v0\n");
  printf("----------------------------------------------------------------\n");
  printf("Available commands:\n");
  printf("account\t - Start working with an account.\n");
  printf("balance\t - Gets avaialble balance.\n");
  printf("withdraw - Withdraw funds from an account.\n");
  printf("deposit\t - Deposit funds into an account.\n");
  printf("transfer - Transfer funds from one account into another account.\n");
  printf("charge\t - Charge a balance to your account.\n");
  printf("wire\t - Wire funds from one account to another.\n");
  printf("help\t - This menu.\n");
  return 0;
}

int createAccount(char* accDetails[3]) {
  // First name
  char *firstName = accDetails[0];
  // Last name
  char *lastName = accDetails[1];
  // Keep this number as a string, because it has a dash in it.
  char *accNumber = accDetails[2];
  return 0;
}
/*
int openAccountFile(int number[]) {
  char accnumStr[10];
  _itoa_s(number, accnumStr);
  char accountFile[14];
  //strcpy(".txt", accnumStr);
  FILE *accountdata = fopen(accountFile, "w+");
}
*/
int main() {
  char menuselection[100];
  // Handle the menu.
  helpmenu();
  while(1) {
    char menuselection[20];
    gets(menuselection);
    if(strcmp("menu", menuselection) == 0 || strcmp("help", menuselection) == 0) {
      helpmenu();
    } else if(strcmp("account", menuselection) == 0) {
      printf("account();\n");
    } else {
      printf("Unknown command.\n");
    }
  }
}
