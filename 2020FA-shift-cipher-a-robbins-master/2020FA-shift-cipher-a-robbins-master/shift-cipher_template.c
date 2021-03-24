#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 500

/*******************************************************************************************PROTOTYPES******************************************/

int getUserChoice();
int getShift();
void getString(char buf[]);
void encrypt(char buf[], int shift);
void decrypt(char buf[], int shift);

/*********************************************************************************************************MAIN*********************************/

int main()
{
  int userChoice = getUserChoice(); 
  int shiftVal = 3; 
  char userMessage[SIZE] ={0};
  char decryptMessage[SIZE] ={0}; 


  while(userChoice != 4)
  {
    if(userChoice == 1)
    {
      shiftVal = getShift(); 
    }

    if(userChoice == 2)
    {
      getString(userMessage); 
      encrypt(userMessage, shiftVal); 
      printf("Encrypted Message is: %s\n", userMessage);   
    }
    
    else if(userChoice == 3)
    {
      getString(decryptMessage); 
      decrypt(decryptMessage, shiftVal); 
      printf("Decrypted message is: %s\n", decryptMessage); 
    }

   userChoice = getUserChoice();  
  
  }
    if(userChoice == 4)
    {
      printf("Thanks for playing! Goodbye!!\n");

      exit(0);  
    }
       
return 0;

}


/****************************************************************************************************FUNCTIONS**********************************/

int getUserChoice()
{
  printf("---------------------------------\n"); 
  printf("|  1. Change Shift (default 3)  |\n"); 
  printf("|  2. Encrypt a message         |\n"); 
  printf("|  3. Decrypt a message         |\n"); 
  printf("|  4. Quit                      |\n"); 
  printf("---------------------------------\n"); 

  int choice = 0; 
  char tmpStr[2]; 

  fgets(tmpStr, 2, stdin); 
  sscanf(tmpStr, "%d", &choice); 

  while((choice <=0)||(choice >= 5))
  {
    printf("Please enter a value between 1-4: "); 
    fgets(tmpStr, 2, stdin); 
    sscanf(tmpStr, "%d", &choice);  
  }

  printf("Choice is: %d\n", choice); 

  while ((getchar()) != '\n');//remove NL char
  
return choice; 

} 



int getShift()
{
  int newVal; 
  char valStr[2]; 

  printf("Enter a new shift value: "); 
  fgets(valStr, 2, stdin); 
  sscanf(valStr, "%d", &newVal); 

  printf("New shift value is: %d\n", newVal); 

return newVal;  
}

void getString(char buf[])
{   
  printf("Enter a string: "); 
  fgets(buf, SIZE, stdin); 
}

void encrypt(char buf[], int shift)
{
  int i = 0; 
  
  for(i = 0; i < strlen(buf); i++)
  {
    if(buf[i] != ' ')
    {
      buf[i] += shift;  
    }
    else
    {
      i++; 
    }
     
  }

  //printf("%s\n", buf);
}

void decrypt(char buf[], int shift)
{
  int i = 0; 
  
  for(i = 0; i < strlen(buf); i++)
  {
    if(buf[i] != ' ')
    {
    //printf("original char: %c  |  ", buf[i]);
    buf[i] -= shift;  
   // printf("new char: %c\n", buf[i]); 
    }
    else
    {
      i++; 
    }
  }
     
}
