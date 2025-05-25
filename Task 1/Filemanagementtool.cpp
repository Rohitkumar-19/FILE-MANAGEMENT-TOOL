#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename = "mynotes.txt";
    int choice;

    cout << "\n---Welcome to Your Notes---\n";

    do {
        cout << "\n(chose any option),What would you like to do?\n";
        cout << "1. Write new notes\n";
        cout << "2. Append existing notes\n";
        cout << "3. Read my notes\n";
        cout << "4. Exit\n";
        cout << "Enter choice (1-4): ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            ofstream file(filename);
            if (file) {
                string note;
                cout << "Write your note: ";
                getline(cin, note);
                file << note << endl;
                file.close();
                cout << "Save your note.\n";
            } else {
                cout << " while saving your note something wrong.\n";
            }

        } else if (choice == 2) {
            ofstream file(filename, ios::app);
            if (file) {
                string moreNote;
                cout << "Add more to your notes: ";
                getline(cin, moreNote);
                file << moreNote << endl;
                file.close();
                cout << "Append your notes\n";
            } else {
                cout << "Couldn't open your notes to add more.\n";
            }

        } else if (choice == 3) {
            ifstream file(filename);
            if (file) {
                string line;
                cout << "\n--- Your Notes ---\n";
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
                cout << "------------------\n";
            } else {
                cout << "Notes not found. Try writing any nots.\n";
            }

        } else if (choice != 4) {
            cout << "Try again ( pleas choos valide option ).\n";
        }

    } while (choice != 4);

    cout << "Goodbye! Your notes are safe in '" << filename << "'\n";
    return 0;
}