


///////////////////////////

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LENGTH 5
#define MAX_PLAYERS 100
#define TOP_PLAYERS_FILE "hung1.txt"

// Structure to store player information
typedef struct {
    char name[50];
    int score;
} Player;

static GtkWidget *entry_guess;
static GtkWidget *label_word;
static GtkWidget *label_message;
static GtkWidget *entry_name;
static GtkWidget *button_guess;
static GtkWidget *button_restart;

static char chosen_word[WORD_LENGTH + 1];
static char guesses[WORD_LENGTH + 1] = "-----";
static int score = 20;
static int correct = 0;
static int attempts = 0;
static Player current_player;

// Function to display the word with guessed letters
void display_word() {
    gchar display[WORD_LENGTH * 2];
    display[0] = '\0';
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (guesses[i] == chosen_word[i]) {
            strncat(display, &guesses[i], 1);
        } else {
            strncat(display, "-", 1);
        }
        strncat(display, " ", 1);
    }
    gtk_label_set_text(GTK_LABEL(label_word), display);
}

// Function to handle guess button click
void on_guess_button_clicked(GtkButton *button, gpointer user_data) {
    const gchar *guess = gtk_entry_get_text(GTK_ENTRY(entry_guess));
    
    if (strlen(guess) != WORD_LENGTH) {
        gtk_label_set_text(GTK_LABEL(label_message), "Guess must be 5 letters.");
        return;
    }

    if (attempts == 0 && strcmp(guess, chosen_word) == 0) {
        score = 20;
        correct = WORD_LENGTH;
    } else {
        for (int i = 0; i < WORD_LENGTH; i++) {
            if (guess[i] == chosen_word[i]) {
                guesses[i] = guess[i];
            }
        }
        
        display_word();
        
        correct = 0;
        for (int i = 0; i < WORD_LENGTH; i++) {
            if (guesses[i] == chosen_word[i]) {
                correct++;
            }
        }

        if (correct < WORD_LENGTH) {
            score--;
        }

        attempts++;
    }

    if (score > 0 && correct == WORD_LENGTH) {
        gchar message[100];
        snprintf(message, sizeof(message), "Congratulations %s! You guessed the word '%s' with a score of %d.", current_player.name, chosen_word, score);
        gtk_label_set_text(GTK_LABEL(label_message), message);
    } else if (score <= 0) {
        gchar message[100];
        snprintf(message, sizeof(message), "You ran out of points. The word was '%s'. Better luck next time!", chosen_word);
        gtk_label_set_text(GTK_LABEL(label_message), message);
    }
}

// Function to handle restart button click
void on_restart_button_clicked(GtkButton *button, gpointer user_data) {
    // Logic to restart the game
    // You should reinitialize chosen_word, guesses, score, attempts, etc.
    // And also update the display and message
}

// Function to initialize the game window
void init_game_window(GtkWidget *window) {
    GtkWidget *box;
    GtkWidget *label_name;
    GtkWidget *hbox;
    GtkWidget *vbox;
    GtkWidget *name_label;
    GtkWidget *entry_name;
    
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    name_label = gtk_label_new("Enter your name:");
    gtk_box_pack_start(GTK_BOX(box), name_label, FALSE, FALSE, 5);
    entry_name = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box), entry_name, FALSE, FALSE, 5);
    button_guess = gtk_button_new_with_label("Guess");
    gtk_box_pack_start(GTK_BOX(box), button_guess, FALSE, FALSE, 5);
    button_restart = gtk_button_new_with_label("Restart");
    gtk_box_pack_start(GTK_BOX(box), button_restart, FALSE, FALSE, 5);

    label_word = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(box), label_word, FALSE, FALSE, 5);
    label_message = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(box), label_message, FALSE, FALSE, 5);

    g_signal_connect(button_guess, "clicked", G_CALLBACK(on_guess_button_clicked), NULL);
    g_signal_connect(button_restart, "clicked", G_CALLBACK(on_restart_button_clicked), NULL);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Word Guessing Game");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    init_game_window(window);

    // Initialize the game state
    // Set a random word, reset guesses, etc.

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
