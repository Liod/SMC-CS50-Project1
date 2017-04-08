#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "jansson.h"

#define ACCOUNT_NUM_SIZE 10

// Logging, so I can see where this is all going wrong.

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
int createFile() {
	FILE * transFile = fopen("TransGroup06.txt", "w+");
	fclose(transFile);
	return 0;
}
int accountExists(char *accountNum) {
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];
	if((fopen_s(&fp, "TransGroup06.txt", "r")) != NULL) {
		return(-1);
	}
	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, accountNum)) != NULL) {
			find_result++;
			printf("%s", temp);
		}
		line_num++;
	}
	if(find_result == 0) {
		printf("false");
	}
	if(fp) {
		fclose(fp);
	}
   	return(0);
}
int balance(char * accountNumber) {
	long length;
	char * accountline = accountExists(accountNumber);
	char * findBalIdentifier = '$';
	char * bal;
	  bal = strchr(accountline, findBalIdentifier);
	  printf(bal);
  return 0;
}
/*
int withdraw(char* accountNum[ACCOUNT_NUM_SIZE], int amount) {
  if(accountExists(accountNum) == "true") {
    FILE *accountFile = fopen_s(&accountFile, accountNum + ".txt", "w+");

  }
  return 0;
}
*/
int deposit(char* accountNum[ACCOUNT_NUM_SIZE], int amount) {
  return 0;
}
int wire(char* originAcc[ACCOUNT_NUM_SIZE], char* destAcc[ACCOUNT_NUM_SIZE], int amount) {
  //withdraw(originAcc, amount);
  deposit(destAcc, amount);
  return 0;
}
int main() {
  char menuselection[100];
  helpmenu();
  while(1) {
    char menuselection[20];
    printf("> ");
    gets(menuselection);
	char accountNum[20];
    if(strcmp("menu", menuselection) == 0 || strcmp("help", menuselection) == 0) {
      helpmenu();
    }
	else if(strcmp("account", menuselection) == 0) {
      printf("account();\n");
    }
	else if(strcmp("balance", menuselection) == 0) {
		printf("Account number: ");
		gets(accountNum);
      balance(accountNum);
    }
	else if(strcmp("withdraw", menuselection) == 0) {
      printf("still gotta do this lol\n");
    }
	else if(strcmp("deposit", menuselection) == 0) {
      int totalDeposit = 0;
      printf("Account number: ");
      gets(accountNum);
      printf("How much would you like to deposit today? $");
      gets(totalDeposit);
      deposit(accountNum, totalDeposit);
    }
	else if(strcmp("testtemp", menuselection) == 0) {
		printf("Account number: ");
		char accountselect[20];
		gets(accountselect);
		accountExists(accountselect);
	}
	else if(strcmp("createFile", menuselection) == 0) {
		createFile();
	}
	else {
		printf("Unknown command.");
	}
  }
}
