#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 5
#define NAME_LENGTH 50

// Structure to store player information
typedef struct {
    char name[NAME_LENGTH];
    int totalGuesses; // Total number of guesses made by the player
    int correctGuesses; // Number of correct guesses made by the player
} Player;

Player players[MAX_PLAYERS];
int playerCount = 0;

// Function to generate a 4-digit magic number
void generateMagicNumber(char magicNumber[]) {
    for (int i = 0; i < 4; i++) {
        magicNumber[i] = '0' + rand() % 10;
    }
    magicNumber[4] = '\0'; // Null-terminate the string
}

// Function to display the magic number with correct guesses revealed
void displayMagicNumber(const char magicNumber[], const char guess[], int revealed[]) {
    for (int i = 0; i < 4; i++) {
        if (magicNumber[i] == guess[i]) {
            revealed[i] = 1; // Mark this digit as correctly guessed
        }
        if (revealed[i]) {
            putchar(magicNumber[i]);
        } else {
            putchar('_');
        }
    }
    putchar('\n');
}

// Function to print the lucky ratios for all players
void printLuckyRatios() {
    printf("\n--- Lucky Ratios History ---\n");
    for (int i = 0; i < playerCount; i++) {
        double luckyRatio = (double)players[i].correctGuesses / players[i].totalGuesses;
        printf("Player: %s, Total Guesses: %d, Lucky Ratio: %.2f\n",
               players[i].name, players[i].totalGuesses, luckyRatio);
    }
}

// Function to update the history of a player
void updatePlayerHistory(const char playerName[], int totalGuesses, int correctGuesses) {
    int playerFound = 0;
    for (int i = 0; i < playerCount; i++) {
        if (strcmp(players[i].name, playerName) == 0) {
            if (totalGuesses < players[i].totalGuesses) {
                players[i].totalGuesses = totalGuesses;
                players[i].correctGuesses = correctGuesses;
            }
            playerFound = 1;
            break;
        }
    }

    if (!playerFound && playerCount < MAX_PLAYERS) {
        // Add new player if not found and there's space
        strcpy(players[playerCount].name, playerName);
        players[playerCount].totalGuesses = totalGuesses;
        players[playerCount].correctGuesses = correctGuesses;
        playerCount++;
    } else if (!playerFound) {
        // Replace the player with the highest total guesses if new player has fewer guesses
        int maxIdx = 0;
        for (int i = 1; i < playerCount; i++) {
            if (players[i].totalGuesses > players[maxIdx].totalGuesses) {
                maxIdx = i;
            }
        }
        if (totalGuesses < players[maxIdx].totalGuesses) {
            strcpy(players[maxIdx].name, playerName);
            players[maxIdx].totalGuesses = totalGuesses;
            players[maxIdx].correctGuesses = correctGuesses;
        }
    }
}

// Comparator function for qsort to sort players by total guesses
int comparePlayers(const void *a, const void *b) {
    return ((Player *)a)->totalGuesses - ((Player *)b)->totalGuesses;
}

// Function to save player history to a file
void savePlayerHistoryToFile() {
    // Sort players by total guesses
    qsort(players, playerCount, sizeof(Player), comparePlayers);

    FILE *file = fopen("Scoreboard.txt", "w");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    int writtenPlayers = 0;
    for (int i = 0; i < playerCount && writtenPlayers < 3; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(players[i].name, players[j].name) == 0) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            double luckyRatio = (double)players[i].correctGuesses / players[i].totalGuesses;
            fprintf(file, "Player: %s, Total Guesses: %d, Lucky Ratio: %.2f\n",
                    players[i].name, players[i].totalGuesses, luckyRatio);
            writtenPlayers++;
        }
    }
    fclose(file);
}

// Function to display the scoreboard from the file
void displayScoreboard() {
    FILE *file = fopen("Scoreboard.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }
    char line[256];
    printf("\n--- Scoreboard ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Main game function
void playGame() {
    char playerName[NAME_LENGTH];
    printf("Enter your name: ");
    scanf("%s", playerName);

    char magicNumber[5];
    char guess[5];
    int totalGuesses = 0;
    int correctGuesses = 0;
    int revealed[4] = {0, 0, 0, 0};

    generateMagicNumber(magicNumber);

    printf("Start guessing the 4-digit magic number!\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%s", guess);

        if (strlen(guess) != 4) {
            printf("Guess must be exactly 4 digits. Please try again.\n");
            continue;
        }

        totalGuesses++;

        if (strcmp(magicNumber, guess) == 0) {
            printf("Congratulations! You guessed the magic number: %s\n", magicNumber);
            correctGuesses++;
            break;
        } else {
            printf("Result: ");
            displayMagicNumber(magicNumber, guess, revealed);
        }
    }

    updatePlayerHistory(playerName, totalGuesses, correctGuesses);
    printLuckyRatios();
    savePlayerHistoryToFile();
}

// Main function to handle user choices
int main() {
    srand(time(0)); // Seed the random number generator
    char choice;

    while (1) {
        printf("\nEnter 'r' to start a new game or 'd' to display the scoreboard (or 'q' to quit): ");
        scanf(" %c", &choice);

        if (choice == 'r') {
            playGame();
        } else if (choice == 'd') {
            displayScoreboard();
        } else if (choice == 'q') {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
