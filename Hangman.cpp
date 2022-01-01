#include <bits/stdc++.h>
using namespace std;

char rawword[100];
string word;
vector<char> lines;
const string manBodyParts[6] = {"  o", "\n-", " |", " -", "\n /", " \\"};
int chances = 6;

void printLines() {
    for (char c : lines) {
        printf("%c", c);
    }
    printf("\n");
}

void printMan() {
    for (int i = 0; i < 6 - chances; i++) {
        printf("%s", manBodyParts[i].data());
    }
    printf("\n");
}

int main() {
    (void)!scanf("%s", rawword);
    word = rawword;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    unsigned long length = word.size();
    lines = vector<char>(length, '_');

    char letter;

    printf("The word has %lu letters.\nFill in the blanks (one letter at a time for better experiences) before the whole Hangman appears on the screen (6 chances: 1 head, 2 arms, 1 body, 2 legs):\n", length);
    
    vector<char> typedLetters;
    while (chances > 0) {
        (void)!scanf("%c", &letter);
        if (letter == '\n') continue;
        bool cheat = false;
        for (char c : typedLetters) {
            if (letter == c) {
                printf("You've tried this letter already. Are you trying to break this program or you literally forgot which letters you've already tried?\nAs a punishment, you lose 2 chances. Have fun hacking... LOL\n");
                chances -= 2;
                printMan();
                cheat = true;
                break;
            }
        }
        if (cheat) continue;
        typedLetters.push_back(letter);
        bool found = false;
        vector<int> idxs;
        for (int i = 0; i < length; i++) {
            if (letter == word[i]) {
                found = true;
                idxs.push_back(i);
            }
        }
        if (found) {
            for (int i : idxs) lines[i] = letter;
            printf("Correct! Current word:\n");
            printLines();
            
            bool win = true;
            for (char c : lines) {
                if (c == '_') {
                    win = false;
                    break;
                }
            }
            if (win) break;
        } else {
            chances--;
            printf("Wrong letter! Hangman:\n");
            printMan();
        }
    }
    
    if (chances <= 0) printf("You lose! Hangman is dead because of you! It's all your fault!\n");
    else printf("You win! You saved Hangman! Did you get lucky or are you too smart?\n");
    
    return 0;
}
