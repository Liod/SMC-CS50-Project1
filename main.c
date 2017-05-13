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

#define SIZE 15
#define a 5

int numberOfClients = 0;
int y = 0;
int connected = 0;
char userFirstName[a][SIZE];
char userLastName[a][20];
char userPassword[a][SIZE];
char menuAnswer[SIZE];
char *ptr_menuAnswer = menuAnswer;

int connectUser() {
   
    char welcomeAnswer[SIZE];
    char welcomeAnswer2[SIZE];
    char verifyFirstName[SIZE];
    char verifyLastName[20];
    char verifyPassword[SIZE];
    
    printf("Welcome to the Bank App !\n");
    printf("Do you already have an account ?\n");
    printf("1 - Yes\n");
    printf("2 - No\n");
    scanf("%s", welcomeAnswer);
    if ( strcmp( welcomeAnswer, "Yes") == 0 )
    {
        
        printf("What is your first name ?\n");
        scanf("%s", verifyFirstName);
        
        
        if ( isupper(verifyFirstName[0]) )
        {
            verifyFirstName[0] = verifyFirstName[0];
        }
        
        else
        {
            verifyFirstName[0] = toupper( verifyFirstName[0] );
        }

        
        
        printf("What is your last name ?\n");
        scanf("%s", verifyLastName);
        
        
        if ( isupper(verifyLastName[0]) )
        {
            verifyLastName[0] = verifyLastName[0];
        }
        
        else
        {
            verifyLastName[0] = toupper( verifyLastName[0] );
        }

        
        
        printf("What is your password ?\n");
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
        
        printf("Sorry, it seems that your account doesn't exist\n");
        printf("Try Again !\n");
        
    }
    else if ( strcmp( welcomeAnswer, "yes") == 0)
    {
        printf("What is your first name ?\n");
        scanf("%s", verifyFirstName);
        
        
        if ( isupper(verifyFirstName[0]) )
        {
            verifyFirstName[0] = verifyFirstName[0];
        }
        
        else
        {
            verifyFirstName[0] = toupper( verifyFirstName[0] );
        }

        
        
        printf("What is your last name ?\n");
        scanf("%s", verifyLastName);
        
        
        if ( isupper(verifyLastName[0]) )
        {
            verifyLastName[0] = verifyLastName[0];
        }
        
        else
        {
            verifyLastName[0] = toupper( verifyLastName[0] );
        }

        
        
        printf("What is your password ?\n");
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
    
            
        
        printf("What is your password ?\n");
        scanf("%s", userPassword[y]);
        
        printf("Are these informations correct ?\n");
        printf("First Name: %s\n", userFirstName[y]);
        printf("Last Name: %s\n", userLastName[y]);
        printf("Password: %s\n", userPassword[y]);
        
        printf("1 - Yes\n");
        printf("2 - No\n");
        scanf("%s", welcomeAnswer2);
        if ( strcmp( welcomeAnswer2, "Yes") == 0 )
        {
            numberOfClients = numberOfClients + 1;
            printf("Your account has been created\n");
            FILE* fichier = NULL;
            
            fichier = fopen("/Users/Yohan/Desktop/TransGroup06.txt", "r+");
            
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
            
            fichier = fopen("/Users/Yohan/Desktop/TransGroup06.txt", "r+");
            
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
    
            
        
        printf("What is your password ?\n");
        scanf("%s", userPassword[y]);
        
        printf("Are these informations correct ?\n");
        printf("First Name: %s\n", userFirstName[y]);
        printf("Last Name: %s\n", userLastName[y]);
        printf("Password: %s\n", userPassword[y]);
        
        printf("1 - Yes\n");
        printf("2 - No\n");
        scanf("%s", welcomeAnswer2);
        if ( strcmp( welcomeAnswer2, "Yes") == 0 )
        {
            numberOfClients = numberOfClients + 1;
            printf("Your account has been created\n");
            
            FILE* fichier = NULL;
            
            fichier = fopen("/Users/Yohan/Desktop/TransGroup06.txt", "r+");
            
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
            
            fichier = fopen("/Users/Yohan/Desktop/TransGroup06.txt", "r+");
            
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
    
    
    else
    {
        printf("Sorry I didn't understand your answer\n");
        printf("Try again !\n");
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
                 printf("Your are disconnected !\n");
             }
             else if ( strcmp( menuAnswer, "close") == 0 )
             {
                 connected = 0;
                 printf("Your are disconnected !\n");
             }
            
            else
            {
                 printf("Sorry I didn't understand your answer !\n");
            }
         }
    }

    return 0;
}

