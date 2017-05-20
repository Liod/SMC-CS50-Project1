#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "jansson.h"
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define ACCOUNT_NUM_SIZE 10
#define SIZE 15
#define a 5
#define RAND_MAX 9
int numberOfClients = 0;
int y = 0;
int connected = 0;
char userFirstName[a][SIZE];
char userLastName[a][SIZE];
char userPassword[a][SIZE];
char menuAnswer[SIZE];
char *ptr_menuAnswer = menuAnswer;

int accountNumGen() {
  int lengthOfNum = 10;
  srand(time(NULL));
  char accountNumber[10];
  strcpy(accountNumber, rand());
  while (lengthOfNum != 0) {
    strcat(accountNumber, rand());
  }
  printf(accountNumber);
  return 0;
}

int connectUser() {

    char welcomeAnswer[SIZE];
    char welcomeAnswer2[SIZE];
    char verifyFirstName[SIZE];
    char verifyLastName[SIZE];
    char verifyPassword[SIZE];

    printf("Welcome to the Bank App!\n");
    printf("Do you already have an account? (Yes/no)\n");
    scanf("%s", welcomeAnswer);
    if ( strcmp( welcomeAnswer, "Yes") == 0 )
    {

        printf("What is your first name?\n");
        scanf("%s", verifyFirstName);
        printf("What is your last name?\n");
        scanf("%s", verifyLastName);
        printf("What is your password?\n");
        scanf("%s", verifyPassword);
        y = 0;
        while ( y < 10) {
            if ( strcmp( verifyFirstName, userFirstName[y]) == 0 && strcmp( verifyLastName, userLastName[y]) == 0 && strcmp( verifyPassword, userPassword[y]) == 0 )
            {
                connected = 1;
                return connected;
            }
            else
            {
                y = y + 1;
            }
        }
    }
    else if ( strcmp( welcomeAnswer, "yes") == 0)
    {
        printf("What is your first name?\n");
        scanf("%s", verifyFirstName);
        printf("What is your last name?\n");
        scanf("%s", verifyLastName);
        printf("What is your password?\n");
        scanf("%s", verifyPassword);
        y = 0;
        while ( y < 10) {
            if ( strcmp( verifyFirstName, userFirstName[y]) == 0 && strcmp( verifyLastName, userLastName[y]) == 0 && strcmp( verifyPassword, userPassword[y]) == 0 )
            {
                connected = 1;
                return connected;
            }
            else
            {
                y = y + 1;
            }
        }
    }

    else if ( strcmp( welcomeAnswer, "No") == 0)
    {
        if ( numberOfClients >= 5)
        {
            printf("We can't have more than 5 clients, sorry.\n");
        }

        else {
        printf("Let's create an account\n");
        y = y + 1;
        printf("What is your first name?\n");
        scanf("%s", userFirstName[y]);

        printf("What is your last name?\n");
        scanf("%s", userLastName[y]);

        printf("What is your password?\n");
        scanf("%s", userPassword[y]);

        printf("Is this information correct? (Yes/no)\n");
        printf("First Name: %s\n", userFirstName[y]);
        printf("Last Name: %s\n", userLastName[y]);
        printf("Password: %s\n", userPassword[y]);
        scanf("%s", welcomeAnswer2);
        if ( strcmp( welcomeAnswer2, "Yes") == 0 )
        {
            numberOfClients = numberOfClients + 1;
            printf("Your account has been created\n");
            FILE* fichier = NULL;

            fichier = fopen("TransGroup06.txt", "a+");

            if (fichier != NULL)
            {
                unsigned long longueurLastName = 0;
                unsigned long longueurFirstName = 0;
                longueurLastName = strlen(userLastName[y]);
                longueurFirstName = strlen(userFirstName[y]);
                fprintf(fichier, "Last Name      | First Name     | Account Number | Password\n");
                fprintf(fichier, "               |                |                |         \n");
                fprintf(fichier, "%s", userLastName[y]);
                while (longueurLastName < 15)
                {
                    fprintf(fichier, " ");
                    longueurLastName = longueurLastName + 1;
                }
                fprintf(fichier, "|");
                fprintf(fichier, " ");
                fprintf(fichier, "%s", userFirstName[y]);
                while (longueurFirstName < 15)
                {
                    fprintf(fichier, " ");
                    longueurFirstName = longueurFirstName + 1;
                }
                fprintf(fichier, "|");
                fprintf(fichier, " 1647389-1      | %s     \n", userPassword[y]);
                fclose(fichier); // On ferme le fichier qui a été ouvert
            }

            connected = 1;
            return connected;
        }

        else if ( strcmp( welcomeAnswer2, "yes") == 0 )
        {
            numberOfClients = numberOfClients + 1;
            printf("Your account has been created.\n");

            FILE* fichier = NULL;

            fichier = fopen("TransGroup06.txt", "a+");

            if (fichier != NULL)
            {
                unsigned long longueurLastName = 0;
                unsigned long longueurFirstName = 0;
                longueurLastName = strlen(userLastName[y]);
                longueurFirstName = strlen(userFirstName[y]);
                fprintf(fichier, "Last Name      | First Name     | Account Number | Password\n");
                fprintf(fichier, "               |                |                |         \n");
                fprintf(fichier, "%s", userLastName[y]);
                while (longueurLastName < 15)
                {
                    fprintf(fichier, " ");
                    longueurLastName = longueurLastName + 1;
                }
                fprintf(fichier, "|");
                fprintf(fichier, " ");
                fprintf(fichier, "%s", userFirstName[y]);
                while (longueurFirstName < 15)
                {
                    fprintf(fichier, " ");
                    longueurFirstName = longueurFirstName + 1;
                }
                fprintf(fichier, "|");
                fprintf(fichier, " 1647389-1      | %s     \n", userPassword[y]);
                fclose(fichier); // On ferme le fichier qui a été ouvert
            }

            connected = 1;
            return connected;

        }

        else if ( strcmp( welcomeAnswer2, "No") == 0 )
        {
            printf("Let's try again\n");
            return 0;
        }

        else if ( strcmp( welcomeAnswer2, "no") == 0 )
        {
            printf("Let's try again\n");
            return 0;
        }
    }
    }
    else if ( strcmp( welcomeAnswer, "no") == 0)
    {
        if ( numberOfClients >= 5)
        {
            printf("We can't have more than 5 clients, sorry.\n");
        }

        else {
        printf("Let's create an account\n");
        y = y + 1;
        printf("What is your first name?\n");
        scanf("%15s", userFirstName[y]);

        printf("What is your last name?\n");
        scanf("%15s", userLastName[y]);

        printf("What is your password?\n");
        scanf("%s", userPassword[y]);

        printf("Is this information correct? (Yes/no)\n");
        printf("First Name: %s\n", userFirstName[y]);
        printf("Last Name: %s\n", userLastName[y]);
        printf("Password: %s\n", userPassword[y]);
        scanf("%s", welcomeAnswer2);
        if ( strcmp( welcomeAnswer2, "Yes") == 0 )
        {
            numberOfClients = numberOfClients + 1;
            printf("Your account has been created.\n");

            FILE* fichier = NULL;

            fichier = fopen("TransGroup06.txt", "a+");

            if (fichier != NULL)
            {
                unsigned long longueurLastName = 0;
                unsigned long longueurFirstName = 0;
                longueurLastName = strlen(userLastName[y]);
                longueurFirstName = strlen(userFirstName[y]);
                fprintf(fichier, "Last Name      | First Name     | Account Number | Password\n");
                fprintf(fichier, "               |                |                |         \n");
                fprintf(fichier, "%s", userLastName[y]);
                while (longueurLastName < 15)
                {
                    fprintf(fichier, " ");
                    longueurLastName = longueurLastName + 1;
                }
                fprintf(fichier, "|");
                fprintf(fichier, " ");
                fprintf(fichier, "%s", userFirstName[y]);
                while (longueurFirstName < 15)
                {
                    fprintf(fichier, " ");
                    longueurFirstName = longueurFirstName + 1;
                }
                fprintf(fichier, "|");
                fprintf(fichier, " 1647389-1      | %s     \n", userPassword[y]);
                fclose(fichier); // On ferme le fichier qui a été ouvert
            }

            connected = 1;
            return connected;
        }

        else if ( strcmp( welcomeAnswer2, "yes") == 0 )
        {
            numberOfClients = numberOfClients + 1;
            printf("Your account has been created\n");
            FILE* fichier = NULL;

            fichier = fopen("TransGroup06.txt", "a+");

            if (fichier != NULL)
            {
                unsigned long longueurLastName = 0;
                unsigned long longueurFirstName = 0;
                longueurLastName = strlen(userLastName[y]);
                longueurFirstName = strlen(userFirstName[y]);
                fprintf(fichier, "Last Name      | First Name     | Account Number | Password\n");
                fprintf(fichier, "               |                |                |         \n");
                fprintf(fichier, "%s", userLastName[y]);
                while (longueurLastName < 15)
                {
                    fprintf(fichier, " ");
                    longueurLastName = longueurLastName + 1;
                }
                fprintf(fichier, "|");
                fprintf(fichier, " ");
                fprintf(fichier, "%s", userFirstName[y]);
                while (longueurFirstName < 15)
                {
                    fprintf(fichier, " ");
                    longueurFirstName = longueurFirstName + 1;
                }
                fprintf(fichier, "|");
                fprintf(fichier, " 1647389-1      | %s     \n", userPassword[y]);
                fclose(fichier); // On ferme le fichier qui a été ouvert
            }

            connected = 1;
            return connected;
        }

        else if ( strcmp( welcomeAnswer2, "No") == 0 )
        {
            printf("Let's try again\n");
            return 0;
        }

        else if ( strcmp( welcomeAnswer2, "no") == 0 )
        {
            printf("Let's try again\n");
            return 0;
        }
    }
    }
    return 0;
}

/* MERGED
int displayMenu() {

    printf("---------------------- Welcome %s %s ------------------------\n", userFirstName[y], userLastName[y]);
    printf("Available commands:\n");
    printf("account\t - Start working with an account.\n");
    printf("balance\t - Get your balance.\n");
    printf("withdraw - Withdraw funds from your account.\n");
    printf("deposit\t - Deposit funds into your account.\n");
    printf("transfer - Transfer funds from your account to another account.\n");
    printf("charge\t - Charge a price to your account.\n");
    printf("wire\t - Wire funds from one account to another one.\n");
    printf("exit\t - Exit your account.\n");

    return 0;
}
*/

/*
int main(int argc, const char * argv[]) {
    while ( connected == 0)
    {

         connectUser();
         while (connected == 1)
         {
             printf("You are connected\n");
             displayMenu();
             scanf("%s", menuAnswer);
             if ( strcmp( menuAnswer, "Exit") == 0 )
             {
                 connected = 0;
                 printf("Your are disconnected !\n");
             }
             else if ( strcmp( menuAnswer, "exit") == 0 )
             {
                 connected = 0;
                 printf("Your are disconnected !\n");
             }
         }
    }

    return 0;
}
*/
int helpmenu() {
  printf("Banking v0\n");
  printf("---------------------- Welcome %s %s ------------------------\n", userFirstName[y], userLastName[y]);
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

	int finalbalance, balanceread;

  if(accountExists(accountNum) == "true") {

  printf("now please give us amount for withdrawl");

  gets(amount);

  printf("now give us account number to proceed");

  gets(accountNum);

  printf("getting balance now...");

  balance(accountNum);

  balanceread = atoi(bal);

  finalbalance = balanceread - amount;

  printf("amounts withdrawn:%i", &amount);
  
  FILE *applyWithdraw;

  sprintf(tempfilewdrw, "%c.txt", accountNum)

  applyWithdraw = fopen_s( tempfilewdrw, "w");

  Char tempWdrw[30];
  
  char underbar[5] = "_";
  
  strcat(tempWdrw, LastName);
  strcat(tempWdrw, underbar);
  strcat(tempWdrw, FirstName);
  strcat(tempWdrw, underbar);
  strcat(tempWdrw, finalbalance_char1);
  char finalbalance_char1 = finalbalance + '0'; // converting int to char

  fprintf(applyWithdraw, "%c", tempWdrw); // recording file and final balance


  fclose(applyWithdraw);
  }
  return 0;
}
*/
int deposit(char* accountNum[ACCOUNT_NUM_SIZE], int amount) {
	/*
	
	int finalbalance, balanceread;

  if(accountExists(accountNum) == "true") {

  printf("now please give us amount for withdrawl");

  gets(amount);

  printf("now give us account number to proceed");

  gets(accountNum);

  printf("getting balance now...");

  balance(accountNum);

  balanceread = atoi(bal);

  finalbalance = balanceread + amount;

  printf("amounts depositing:%i", &amount);
  
  FILE *applyDeposit;

  sprintf(tempfileDpsit, "%c.txt", accountNum)

  applyDeposit = fopen_s( tempfileDpsit, "w");

  Char tempDpsit[30];
  char finalbalance_char2 = finalbalance + '0'; // converting int to char
  
  char underbar[5] = "_";
  
  strcat(tempDpsit, LastName);
  strcat(tempDpsit, underbar);
  strcat(tempDpsit, FirstName);
  strcat(tempDpsit, underbar);
  strcat(tempDpsit, finalbalance_char2);
  
  fprintf(applyDeposit, "%c", tempDpsit); // recording file and final balance
   
  fclose(applyDeposit);
  
  */
  return 0;
}
int wire(char* originAcc[ACCOUNT_NUM_SIZE], char* destAcc[ACCOUNT_NUM_SIZE], int amount) {
  //withdraw(originAcc, amount);
  deposit(destAcc, amount);
  return 0;
}
int main() {
  char menuselection[100];
  connectUser();
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
  else if(strcmp("exit", menuselection) == 0) {
    printf("Goodbye!");
    exit(0);
  }
  else if(strcmp("genAccNum", menuselection) == 0) {
    accountNumGen();
  }
  }
}
