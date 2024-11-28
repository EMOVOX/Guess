#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int select_level(){
  int level_chose , level ;
  printf("Please enter a level eazy (1) , normal (2) , hard (3) : ");
  while (scanf("%d",&level_chose) != 1 && level_chose !=2 && level_chose != 3){
    puts("Please enter 1 or 2 or 3 :");
    while(getchar() != '\n');
  }
  if (level_chose == 1){
    level = 50 ;
  }
  if (level_chose == 2){
    level = 100;
  }
  if (level_chose == 3){
    level = 200 ;
  }
  system("clear");
  return level;
}

int main(){
  puts("\t\t\t\tWelcome to the Guessing Game\n");
  short int number , guess , result;
  const int MAX_NUMBER = select_level();
  srand(time(0));
  number = (rand() % MAX_NUMBER) ;

  do{
    printf("\nTake a guess : ");
    result = scanf("%hd",&guess); 
    if(result != 1){
      printf("Invalid. Please enter a number !");
      while(getchar() !='\n');
      continue;
    }
    if (guess < number ){
      printf("It's higher than that");
    }
    if(guess > number){
      printf("It's lower than that");
    }
    if (number - 10 <= guess && guess < number  ||  guess > number && guess <= number + 10){
      printf(", but you are so close");
    }
    if(number + 30 < guess || number - 30 > guess ){
      printf(", and you are way off");
    }  
  }while(guess!=number);

  printf("\033[1;32mCongratulations! You guessed it!\033[0m\n");
  system("aplay win_sound.wav > /dev/null 2>&1");
  return 0 ;    
  }

