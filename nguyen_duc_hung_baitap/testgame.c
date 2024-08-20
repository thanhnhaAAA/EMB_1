


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_COUNT 20
#define WORD_LENGTH 5
#define MAX_PLAYERS 100
#define TOP_PLAYERS_FILE "hung.txt"

// Structure to store player information
typedef struct {
    char name[50];
    int score;
} Player;

// Function to display the word with guessed letters
void display_word(char *word, char *guesses) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (guesses[i] == word[i]) {
            printf("%c ", guesses[i]); // Display guessed letter if it matches
        } else {
            printf("- "); // Display '-' for unguessed letters
        }
    }
    printf("\n");
}

// Function to save player score to file
void save_score(Player player) {
    FILE *file = fopen(TOP_PLAYERS_FILE, "a"); // Open file in append mode
    if (file == NULL) {
        perror("Error opening file for appending");
        return;
    }
    
    fprintf(file, "%s %d\n", player.name, player.score); // Write player name and score
    fclose(file);
}

// Function to update the top players list
void update_top_players() {
    Player players[MAX_PLAYERS];
    int count = 0;

    // Read existing scores from file
    FILE *file = fopen(TOP_PLAYERS_FILE, "r");
    if (file != NULL) {
        while (fscanf(file, "%s %d", players[count].name, &players[count].score) != EOF) {
            count++;
        }
        fclose(file);
    } else {
        perror("Error opening file for reading");
        return;
    }

    // Sort players by score in descending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (players[j].score > players[i].score) {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    // Write top 3 players to file
    file = fopen(TOP_PLAYERS_FILE, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }
    for (int i = 0; i < count && i < 3; i++) {
        fprintf(file, "%s %d\n", players[i].name, players[i].score); // Write top 3 players
    }
    fclose(file);
}

// Function to print the top 3 players
void print_top_players() {
    printf("Top 3 Players:\n");
    FILE *file = fopen(TOP_PLAYERS_FILE, "r");
    if (file != NULL) {
        char name[50];
        int top_score;
        int rank = 1;
        while (fscanf(file, "%s %d", name, &top_score) != EOF && rank <= 3) {
            printf("%d. %s - %d\n", rank, name, top_score); // Print rank, name, and score
            rank++;
        }
        fclose(file);
    } else {
        perror("Error opening file for reading");
    }
}

int main() {
    // List of words for the game
    char *word_list[WORD_COUNT] = {
        "apple", "grape", "mango", "peach", "berry",
        "lemon", "plumb", "pearl", "olive", "guava",
        "dates", "figs", "cocoa", "kiwii", "pearr",
        "beach", "candy", "crane", "dance", "eagle"
    };

    // Seed the random number generator
    srand(time(0));
    int random_index = rand() % WORD_COUNT; // Select a random word
    char *chosen_word = word_list[random_index];

    char guesses[WORD_LENGTH + 1] = "-----"; // Initialize guesses
    int attempts = 0;
    int correct = 0;
    int score = 20;
    char player_name[50];

    printf("Welcome to the Word Guessing Game!\n");
    printf("Enter your name: ");
    scanf("%s", player_name); // Get player's name
    printf("Guess the %d-letter word:\n", WORD_LENGTH);

    // Game loop
    while (correct < WORD_LENGTH && score > 0) {
        char guess[WORD_LENGTH + 1];
        printf("Enter a %d-letter word: ", WORD_LENGTH);
        scanf("%s", guess);

        if (attempts == 0 && strcmp(guess, chosen_word) == 0) { // If correct guess in the first attempt
            score = 20;
            correct = WORD_LENGTH;
            break;
        }

        for (int i = 0; i < WORD_LENGTH; i++) {
            if (guess[i] == chosen_word[i]) {
                guesses[i] = guess[i]; // Update guessed letters
            }
        }

        display_word(chosen_word, guesses); // Display current state of guessed word

        correct = 0;
        for (int i = 0; i < WORD_LENGTH; i++) {
            if (guesses[i] == chosen_word[i]) {
                correct++; // Count correct guesses
            }
        }

        if (correct < WORD_LENGTH) {
            score--; // Decrease score for incorrect guess
        }

        attempts++;
    }

    if (score > 0) {
        printf("Congratulations %s! You guessed the word '%s' in %d attempts with a score of %d.\n", player_name, chosen_word, attempts, score);
    } else {
        printf("You ran out of points, %s. The word was '%s'. Better luck next time!\n", player_name, chosen_word);
    }

    Player player;
    strcpy(player.name, player_name);
    player.score = score;
    save_score(player); // Save the player's score
    update_top_players(); // Update the top players list
    print_top_players(); // Print the top 3 players

    return 0;
}








