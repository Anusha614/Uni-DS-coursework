
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct students {
    char name[30];
    int rolln;
};

char filename[50];

void createFile() {
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        cout << "Failed to create file";
        return;
    }

    fclose(file);
    cout << "File created successfully";
}

void addRecord() {
    students s;
    FILE *file = fopen(filename, "ab");

    if (file == NULL) {
        cout << "File cannot be opened";
        return;
    }

    cout << "Enter name of student: ";
    cin >> s.name;

    cout << "Enter roll number of student: ";
    cin >> s.rolln;

    fwrite(&s, sizeof(s), 1, file);

    fclose(file);
    cout << "Record added successfully";
}

void displayRecords() {
    students s;
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        cout << "File doesn't exist";
        return;
    }

    while (fread(&s, sizeof(s), 1, file)) {
        cout << "\nName: " << s.name;
        cout << "\nRoll number: " << s.rolln << endl;
    }

    fclose(file);
}

void deleteRecord() {
    students s;

    FILE *file = fopen(filename, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (file == NULL || temp == NULL) {
        cout << "File issue";

        if (file != NULL) fclose(file);
        if (temp != NULL) fclose(temp);

        return;
    }

    int deleteId;
    bool found = false;

    cout << "Enter roll number to delete: ";
    cin >> deleteId;

    while (fread(&s, sizeof(s), 1, file)) {
        if (s.rolln == deleteId) {
            found = true;
        }
        else {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    if (!found) {
        remove("temp.dat");
        cout << "Student not found";
    }
    else {
        remove(filename);
        rename("temp.dat", filename);
        cout << "Student deleted successfully";
    }
}

int main() {
    int choice;

    cout << "Enter name of the file: ";
    cin >> filename;

    do {
        cout << "\n\n1. Create file";
        cout << "\n2. Add record";
        cout << "\n3. Display records";
        cout << "\n4. Delete record";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createFile();
                break;

            case 2:
                addRecord();
                break;

            case 3:
                displayRecords();
                break;

            case 4:
                deleteRecord();
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 5);

    return 0;
}
