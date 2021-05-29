/**
 *      file    :  main.c
 *      author  :  deepak_jangra
 *      created :  2021 May 28 12:01:11  IST
 *      lastMod :  Friday 28 May 2021 12:01:11 PM IST
 **/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
  char ch;
  int oCount = 0;
  int xCount = 0;
  int choice;
  
  printf("Choose your symbol\n");
  printf("1 : X\n");
  printf("2 : O\n");
  scanf("%c", &ch);

  switch(ch)
  {
    case '1':
      ch = 'X';
      break;
    case '2':
      ch = 'O';
  }
  if(ch == 'X')
  {
    printf("First player symbol is 'X'\n");
    printf("Second player symbol is 'O'\n");
  }
  else
  {
    printf("First player symbol is 'O'\n");
    printf("Second player symbol is 'X'\n");  
  }

  int turn = 1;
  printf("%s : Begin\n",__func__);

  char arr[] = { '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9'};

  printf("  %c  |  %c  |  %c  \n-----------------\n  %c  |  %c  |  %c  \n-----------------\n  %c  |  %c  |  %c  \n" , arr[0], arr[1], arr[2] , arr[3] , arr[4], arr[5] , arr[6] , arr[7] , arr[8]);
  printf("Turn of %c\n", ch);

  while(1)
  {
    printf("Enter your choice\n");
    scanf("%d", &choice);

    if(turn % 2 != 0)
    {

      if(ch == 'O')
      {
        printf("Next turn of X\n");
        arr[choice - 1] = 'O';
        oCount++;
      }
      else
      {
        printf("Next turn of O\n");
        arr[choice - 1] = 'X';
        xCount++;
      }
    }
    else
    {
      if(ch == 'O')
      {
        printf("Next turn of X\n");
        arr[choice - 1] = 'X';
        xCount++;
      }
      else
      {
        printf("Next turn of O\n");
        arr[choice - 1] = 'O';
        oCount++;
      }
    }

    printf("  %c  |  %c  |  %c  \n-----------------\n  %c  |  %c  |  %c  \n-----------------\n  %c  |  %c  |  %c  \n" , arr[0], arr[1], arr[2] , arr[3] , arr[4], arr[5] , arr[6] , arr[7] , arr[8]);


    if((arr[0] == arr[1] && arr[0] ==  arr[2]) || (arr[0] == arr[3] && arr[0] == arr[6]) || (arr[3] == arr[4] && arr[3] == arr[5]) || (arr[6] == arr[7] && arr[6] == arr[8]) || (arr[1] == arr[4] && arr[1] == arr[7])  || (arr[2] == arr[6] && arr[2] == arr[8] ))
    {

      if(xCount == oCount)
      {
        if(ch == 'X')
          printf("O is the winner\n");
        else
          printf("X is the winner\n");
        break;
      }
      printf("xCount %d\n", xCount);
      printf("oCount %d\n", oCount);
      char max = xCount>oCount?'X':'O';

      printf("%c is the winner\n", max);
      break;
    }
    turn++;
    if(turn == 10)
      break;
  }
  printf("%s : End\n",__func__);
  return 0;
}  
