//I will add notes here bcz I suck at flowcharts.

#include <stdio.h>
#include <time.h> //to use the srand function
#include <stdlib.h> // to use the srand function as well

int main() {
    char reply;
    int ans, guess, guesses;
    int firstTime = 1;  // Flag to track if it's the first time playing

    srand(time(0)); //creating a random number

    do {
        guesses = 0;

        if (firstTime) {
            printf("\nWanna play a little number guessing game?\n");
            printf("If yes, enter 'y'; otherwise, enter 'n': "); //kept these two consecutive print statements seperated bcz i wanted to add a label and a goto statement at first
            scanf(" %c", &reply);
            firstTime = 0;  // Set the flag to 0 after the first game
        } else {
            printf("\nWanna play again?\n");
            printf("If yes, enter 'y'; otherwise, enter 'n': "); ////kept these two consecutive print statements seperated bcz i wanted to add a label and a goto statement at first
            scanf(" %c", &reply);
        }

        if (reply == 'y') {
            ans = (rand() % 100) + 1; //storing the randomly generated number
            printf("A random number between 1 to 100 has been generated. Take a guess:\n");

            do {
                if (scanf("%d", &guess) != 1) {
                    printf("Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n');
                    continue;
                } //error handling to clear buffers (if any) to avoid infinite feedback loops

                if (ans > guess) {
                    printf("Nope! Go higher.\n");
                } else if (ans < guess) {
                    printf("Nope! Go lower.\n");
                } else {
                    printf("Yay, you got it!!!\n");
                }

                guesses++;
            } while (ans != guess);

            printf("The answer was %d\n", ans);
            printf("The number of guesses you took was %d\n", guesses);
        } else if (reply != 'n') {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }

    } while (reply != 'n');

    printf("See you next time!\n");

    return 0;
}

//that's basically it...use this snippet anywhere you want and feel free to modify it...Signing off - MischievousRay