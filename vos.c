/* Steven Rand */
/* Test for Monty-Hall Problem */
/* 06/28/2012 */

/* There are three curtains. Behind one of them is a car.
   Behind the other two are goats. The player gets to pick
   a curtain. The host then raises a curtain which hides a
   goat and is not the curtain which the player picked. Then 
   the player gets to pick the curtain behind which he or 
   she thinks the car is. The goal is to pick correctly,
   which results in winnning the car. The question, then, is 
   whether the player should switch his or her original pick
   after the host reveals the goat behind one of the curtains.
   The answer, surprisingly, is that switching one's guess 
   results in a 67% winning percentage, while keeping to one's
   original guess gives only a 33% chance of winning the car. 
   This is because in two thirds of cases the player originally
   picked a goat, meaning that he or she knows the location of
   two goats after the host reveals one of them, and therefore
   that the car is behind the curtain that was neither selected
   at first or raised. The following program corroborates the above
   hypothesis. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int trials = 0;
  int correct =  0;

  int car, first_guess, show_goat, switch_guess;
  srand(time(NULL));

  while (trials++ < 10000) {
    car = rand() % 3;
    first_guess = rand() % 3;
    
    /* Case in which 1st guess was a goat: switching is right */
    if (first_guess != car) {
      show_goat = 3 - (car + first_guess);
      switch_guess = 3 - (first_guess + show_goat);
      if (switch_guess == car) {
	correct++;
      }
    }
  }

  /* Case in which first guess was a car is ignored: 
     switching is wrong, so counter cannot be bumped */

  printf("Stats for switching one's guess:\n");
  printf("Percentage correct: %f\n", (float)correct / 100.0);
  printf("Percentage incorrect: %f\n", (float)(10000 - correct) / 100.0);
  return 0;
}
    


