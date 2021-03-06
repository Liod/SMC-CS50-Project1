//
//  main.c
//  Bank
//
//  Created by Yohan LE ROUZES on 02/04/2017.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 15
#define a 5


int numberOfClients = 0;
int x = 0;
int y = 0;
int n = 0;
int m = 0;
int z = 0;
int j = 0;
int transferAccount;
char transferAccountArray[a][SIZE];
int transferAmount;
int connected = 0;
char userFirstName[a][SIZE];
char buffer [50];
char userLastName[a][20];
char userPassword[a][SIZE];
char userBalance[a][SIZE];
char *ptr_userBalance;
char balanceArray[a];
long Balance;
int depositAmount;
int withdrawAmount;
int userAccountNumber[a][SIZE];
char menuAnswer[SIZE];
char *ptr_menuAnswer = menuAnswer;
char *balanceFileName[50];
char file_extension[] = ".txt";
char *userdata[2048];

/*

HOW THINGS WILL WORK
user logs in with account number + password -> code opens file with account number -> checks password -> get string from file -> segment it + put each piece of data into a part of the userdata[] array -> ez.

*/


// int usingTempFile() {
//    char buf[0x100];
//    snprintf(buf, sizeof(buf), "/Users/Yohan/Desktop/%d.txt", userAccountNumber[y][0]);
//
//    FILE* file = fopen(buf, "w+");
//
//
//    if (file != NULL)
//    {
//        fprintf(file, "%s_%s_%s\n", userFirstName[y], userLastName[y], userBalance[y]);
//
//
//
//        fclose(file);
//    }
//
//    return 0;
// }











int connectUser() {

    char welcomeAnswer[SIZE];
    char welcomeAnswer2[SIZE];
    char verifyFirstName[SIZE];
    char verifyLastName[20];
    char verifyPassword[SIZE];

    printf("Welcome to the Bank App!\n");
    printf("Do you already have an account? (yes/no)\n");
    scanf("%s", welcomeAnswer);
    int g = 0;
    while(welcomeAnswer[g]) {
      welcomeAnswer[g] = toupper(welcomeAnswer[g]);
      g++;
    }
    if ( strcmp( welcomeAnswer, "YES") == 0 )
    {
        char* userLoginAccNum[7];
        int gg = 0;
        while(gg < 1) {
          printf("Account #: ");
          scanf("%s", userLoginAccNum);
          if ( strlen(userLoginAccNum) == 7 )
          {
              gg++;
          } else {
            printf("[ERROR] Invalid account number. Please try again.\n");
          }
        }
        printf("Password: ");
        scanf("%s", verifyPassword);
        y = 0;
        while ( y < 10) {
          char *kasai[50];
          strcpy(balanceFileName, userLoginAccNum);
          strcpy(balanceFileName, strcat(balanceFileName, file_extension));
          FILE * balanceFile = fopen(balanceFileName, "w");
          fgets(kasai, 50, balanceFile);
          //printf("%s\n", kasai);
          fclose(balanceFile);
          /*
            if ( strcmp( verifyFirstName, userFirstName[y]) == 0 && strcmp( verifyLastName, userLastName[y]) == 0 && strcmp( verifyPassword, userPassword[y]) == 0 )
            {
                connected = 1;
                return connected;
            }
            else
            {
                y = y + 1;
            }
            */
        }


        printf("Sorry, it seems that your account doesn't exist\n");
        printf("Try Again !\n");

    }
    else if ( strcmp( welcomeAnswer, "NO") == 0)
    {
        if ( numberOfClients >= 5)
        {
            printf("We can't have more than 5 clients, sorry.\n");
        }

        else {
          printf("Let's create an account\n");
          y = y + 1;
          printf("What is your first name ?\n");
          scanf("%s", userFirstName[y]);
          if ( isupper(userFirstName[y][0]) )
          {
              userFirstName[y][0] = userFirstName[y][0];
          }

          else
          {
           userFirstName[y][0] = toupper( userFirstName[y][0] );
          }

          printf("What is your last name ?\n");
          scanf("%s", userLastName[y]);


              if ( isupper(userLastName[y][0]) )
              {
                  userLastName[y][0] = userLastName[y][0];
              }

              else
              {
                  userLastName[y][0] = toupper( userLastName[y][0] );
              }



          printf("What is your password?\n");
          scanf("%s", userPassword[y]);

          printf("Is this information correct? (yes/no)\n");
          printf("First Name: %s\n", userFirstName[y]);
          printf("Last Name: %s\n", userLastName[y]);
          printf("Password: %s\n", userPassword[y]);

          scanf("%s", welcomeAnswer2);
          int h = 0;
          while(welcomeAnswer2[h]) {
            welcomeAnswer2[h] = toupper(welcomeAnswer2[h]);
            h++;
          }
          if ( strcmp( welcomeAnswer2, "YES") == 0 )
          {
              numberOfClients = numberOfClients + 1;
              printf("Your account has been created!\n");
              strcpy( &userBalance[y][0], "0" );
              srand( (unsigned int) time(NULL) );
              userAccountNumber[y][0] = rand() % 9999999 + 1111111;
              printf("Your account number is: %d\n", userAccountNumber[y][0]);

              FILE* fichier = NULL;

              fichier = fopen("TransGroup06.txt", "a");

              // Don't mind this.
              int* startingBalance = 0;
              sprintf(balanceFileName, "%d", userAccountNumber[y][0]);
              strcpy(balanceFileName, strcat(balanceFileName, file_extension));
              FILE * balanceFile = fopen(balanceFileName, "w");
              fprintf(balanceFile, "%s,", userFirstName[y]);
              fprintf(balanceFile, "%s,", userLastName[y]);
              fprintf(balanceFile, "%s,", userPassword[y]);
              fprintf(balanceFile, "%i", startingBalance);
              fclose(balanceFile);

              if (fichier != NULL)
              {
                  unsigned long longueurLastName = 0;
                  unsigned long longueurFirstName = 0;
                  longueurLastName = strlen(userLastName[y]);
                  longueurFirstName = strlen(userFirstName[y]);
                  fprintf(fichier, "Last Name      | First Name     | Account Number | Password | Balance\n");
                  fprintf(fichier, "               |                |                |          |        \n");
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
                  fprintf(fichier, " %i        ", userAccountNumber[y][0]);
                  fprintf(fichier, "|");
                  fprintf(fichier, " %s     \n", userPassword[y]);
                  fclose(fichier); // On ferme le fichier qui a été ouvert
              }

              connected = 1;
              return connected;
          }
          else if ( strcmp( welcomeAnswer2, "NO") == 0 )
          {
              printf("Let's try again\n");
              return 0;
          }
      }
    }


    else
    {
        printf("Sorry, I didn't understand your answer.\n");
        printf("Try again!\n");
    }


    return 0;
}


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
    printf("close\t - Close your account.\n");

    return 0;
}


int main(int argc, const char * argv[]) {

    int transferAccount = 0;
    char transferAccountArray[a][SIZE];

    while ( connected == 0)
    {

         connectUser();
         while (connected == 1)
         {
             printf("You are connected\n");
             displayMenu();
             scanf("%s", menuAnswer);
             if ( strcmp( menuAnswer, "Close") == 0 )
             {
                 connected = 0;
                 printf("You are disconnected !\n");
             }
             else if ( strcmp( menuAnswer, "close") == 0 )
             {
                 connected = 0;
                 printf("You are disconnected !\n");
             }


             else if ( strcmp( menuAnswer, "Balance") == 0 )
             {

                 printf("Your actual balance is: %s", userBalance[y]);
                 printf("$\n");

             }

             else if ( strcmp( menuAnswer, "balance") == 0 )
             {
                 printf("Your actual balance is: %s", userBalance[y]);
                 printf("$\n");
             }


             else if ( strcmp( menuAnswer, "Deposit") == 0 )
             {
                 printf("How much would you like to deposit ?\n");
                 scanf("%d", &depositAmount);

                 Balance = strtol(userBalance[y], &ptr_userBalance, 10);
                 Balance = Balance + depositAmount;

                 sprintf (userBalance[y], "%ld", Balance);
                 printf("Success ! Your new Balance is: $%s\n", userBalance[y]);
                 Balance = 0;
             }


             else if ( strcmp( menuAnswer, "deposit") == 0 )
             {
                 printf("How much would you like to deposit ?\n");
                 scanf("%d", &depositAmount);

                 Balance = strtol(userBalance[y], &ptr_userBalance, 10);
                 Balance = Balance + depositAmount;

                 sprintf (userBalance[y], "%ld", Balance);
                 printf("Success ! Your new Balance is: %s$\n", userBalance[y]);
                 Balance = 0;
             }


             else if ( strcmp( menuAnswer, "Withdraw") == 0 )
             {
                 printf("How much would you like to withdraw ?\n");
                 scanf("%d", &withdrawAmount);

                 Balance = strtol(userBalance[y], &ptr_userBalance, 10);
                 Balance = Balance - withdrawAmount;
                 if ( Balance >= withdrawAmount)
                 {
                     sprintf (userBalance[y], "%ld", Balance);
                     printf("Success ! Your new Balance is: %s$\n", userBalance[y]);
                     Balance = 0;
                 }
                 else {
                     printf("Sorry you don't have that amount on your account !\n");
                 }
             }


             else if ( strcmp( menuAnswer, "withdraw") == 0 )
             {
                 printf("How much would you like to withdraw ?\n");
                 scanf("%d", &withdrawAmount);

                 Balance = strtol(userBalance[y], &ptr_userBalance, 10);
                 Balance = Balance - withdrawAmount;
                 if ( Balance >= withdrawAmount)
                 {
                     sprintf (userBalance[y], "%ld", Balance);
                     printf("Success ! Your new Balance is: %s$\n", userBalance[y]);
                     Balance = 0;
                 }
                 else {
                     printf("Sorry you don't have that amount on your account !\n");
                 }
             }


             else if ( strcmp( menuAnswer, "Transfer") == 0 )
             {
                 printf("What amount do you want to tranfer:\n");
                 scanf("%d", &transferAmount);

                 printf("To what account do you want to transfer your money:\n");
                 scanf("%d", &transferAccount);

                 Balance = strtol(userBalance[y], &ptr_userBalance, 10);
                 Balance = Balance - transferAmount;

                 sprintf (userBalance[y], "%ld", Balance);
                 printf("Success ! Your new Balance is: %s$\n", userBalance[y]);
                 Balance = 0;

                 char userAccountNumber[a][SIZE];
                 y = 0;
                 sprintf (transferAccountArray[y], "%d", transferAccount);
                 while ( y < 10) {
                     if ( strcmp( transferAccountArray[y], userAccountNumber[y]) == 0 )
                     {
                         Balance = strtol(userBalance[y], &ptr_userBalance, 10);
                         Balance = Balance + transferAmount;
                         sprintf (userBalance[y], "%ld", Balance);
                         Balance = 0;
                         y = y + 1;
                     }
                     else
                     {
                         y = y + 1;
                     }
                 }



             }


             else if ( strcmp( menuAnswer, "transfer") == 0 )
             {
                 printf("What amount do you want to tranfer:\n");
                 scanf("%d", &transferAmount);

                 printf("To what account do you want to transfer your money ( account number ):\n");
                 scanf("%d", &transferAccount);

                 char userAccountNumber[a][SIZE];


                 sprintf (transferAccountArray[m], "%d", transferAccount);
                 z = 0;
                 m = 0;

                 while ( z < 10 ) {
                     if ( strcmp( transferAccountArray[z], userAccountNumber[z]) == 0 )
                     {

                         printf("Success !\n");
                         Balance = strtol(userBalance[y], &ptr_userBalance, 10);
                         Balance = Balance - transferAmount;
                         sprintf (userBalance[y], "%ld", Balance);
                         printf("Your new balance is %s$\n", userBalance[y]);



                         Balance = strtol(userBalance[z], &ptr_userBalance, 10);
                         Balance = Balance + transferAmount;
                         sprintf (userBalance[z], "%ld", Balance);


                         z = 11;
                     }
                     else if ( strcmp( transferAccountArray[z], userAccountNumber[z]) != 0 )
                     {
                         z = z + 1;
                     }

                 }


             }

             else
            {
                printf("Sorry I didn't understand your answer !\n");
            }


         }
    }

    return 0;
}
