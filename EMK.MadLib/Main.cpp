#include <iostream>
#include <conio.h>
using namespace std;

struct Entry {
    string type;
    string input;
};

const int NUM_ENTRIES = 10;
Entry entries[NUM_ENTRIES] = {
    {"place", ""},
    {"adjective", ""},
    {"noun", ""},
    {"famous person", ""},
    {"verb", ""},
    {"animal", ""},
    {"food", ""},
    {"color", ""},
    {"crime", ""},
    {"country", ""}
};

bool fixMistake() {
    string fixMistakeInput;
    while (true) {
        cout << "\nDo you want to fix any mistakes? (y/n): ";
        cin >> fixMistakeInput;
        if (fixMistakeInput == "y") {
            return true;
        }
        if (fixMistakeInput == "n") {
            return false;
        }
        cout << "Invalid input. ";
    }
}

void PlayMadLib() {
    for (int i = 0; i < NUM_ENTRIES; i++) {
        string entryInput;
        cout << (i + 1) << ". Enter a " << entries[i].type << ": ";
        cin >> entryInput;
        entries[i].input = entryInput;
    }

    while (fixMistake()) {
        int fixEntryInput;
        cout << "Which entry would you like to fix? (1-10): ";
        cin >> fixEntryInput;
        while (fixEntryInput < 1 || fixEntryInput > NUM_ENTRIES) {
            cout << "Invalid input. Which entry would you like to fix? (1-10): ";
            cin >> fixEntryInput;
        }
        cout << "Enter a " << entries[fixEntryInput - 1].type << ": ";
        cin >> entries[fixEntryInput - 1].input;
    }

    cout << "Your Mad Lib:\n"
        << "Yesterday, I went to " << entries[0].input
        << " and saw a " << entries[1].input << " " << entries[2].input
        << " I asked " << entries[3].input
        << " if he wanted to commit " << entries[8].input << " with me, "
        << " but he said he was busy " << entries[4].input << " the " << entries[5].input
        << " and eating " << entries[7].input << entries[6].input << " in " << entries[9].input << "." << endl;
}

int main() {
    PlayMadLib();
    (void)_getch();
    return 0;
}