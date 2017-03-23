/*
@author Hunter Nakagawa
@date March 17, 2017
@class CS50, Prof. Paiola
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define ACCOUNT_SIZE 10

int helpmenu() {
  printf("Banking v0\n");
  printf("---------------------------------------\n");
  printf("Available commands:\n");
  printf("account\t - Start working with an account.\n");
  printf("balance\t - Gets avaialble balance.\n");
  printf("withdraw - Withdraw funds from an account.\n");
  printf("deposit\t - Deposit funds into an account.\n");
  printf("transfer - Transfer funds from one account into another account.\n");
  printf("charge\t - Charge a balance to your account\n");
  printf("check\t - Withdraw funds using a paper cheque.\n");
  printf("help\t - This menu.");
  return 0;
}
int account(int number[]) {

}
int main() {
  char menuselection[100];
  // Handle the menu.
  helpmenu();
  while(1) {
    scanf("%s", menuselection);
    printf("%s\n");
    if(strcmp("menu", "%s") || strcmp("help", "%ss")) {
      helpmenu();
    } else if(strcmp("account", menuselection)) {
      //do account stuff here.
    } else {
      printf("Unknown command.\n");
    }
  }
}
