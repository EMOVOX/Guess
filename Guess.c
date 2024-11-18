#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  puts("\t\t\t\tWelcome to the Guessing Game \n");

  short int number , guess , result ;
  const int MAX_NUMBER = 100 ;
  srand(time(0));
  number = (rand() % MAX_NUMBER) ;
  do{
    printf("\nTake a guess : ");
    fflush(stdout);
    result = scanf("%hd",&guess); 
    if(result!=1){
      printf("Invalid. Please enter a number !");
      while(getchar() !='\n');
      continue;
    }else{
    }
    if (guess < number ){
      printf("It's higher than that");
    }
    if(guess > number){
      printf("It's lower than that");
    }
    if (number - 10 <= guess && guess < number || guess > number  && guess <= number + 10){
      printf(" but you are so close");
    }
    if(number + 30 < guess ){
      printf(" and you are way off");
    }
    
  }while(guess!=number);
  puts("You win !");
  system("aplay win_sound.wav > /dev/null 2>&1");

  return 0 ;

     
  }



