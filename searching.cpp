#include <iostream> 
#include <string> 
#include <algorithm> 
 
using namespace std; 
 
class Book { 
 
    private: 
    string ISBN; 
    string bookName; 
    string authorName; 
    string publisherName; 
    float cost; 
 
    public: 
 
    void acceptDetails () { 
 
        cout << "Enter ISBN: "; 
        cin >> ISBN; 
 
        cout << "Enter book name: "; 
        cin >> bookName; 
 
        cout << "Enter author name: "; 
        cin >> authorName; 
 
        cout << "Enter publisher name: "; 
        cin >> publisherName; 
 
        cout << "Enter price: "; 
        cin >> cost; 
    } 
 
    string getISBN() { 
        return ISBN; 
    } 
 
    string getName() { 
        return bookName; 
    } 
 
    string getAuthor() { 
        return authorName; 
    } 
 
    string getPublisher() { 
        return publisherName; 
    } 
 
    float getPrice() { 
        return cost; 
    } 
 
    void display() { 
 
    cout << "\nISBN: " << ISBN; 
    cout << "\nBook Name: " << bookName; 
    cout << "\nAuthor Name: " << authorName; 
    cout << "\nPublisher Name: " << publisherName; 
    cout << "\nCost: " << cost << endl; 
 
   } 
}; 
 
void linearSearchBook ( Book books[], int n ) { 
 
        int choice; 
 
        cout << "\nSearch Book By:"; 
        cout << "\n1. ISBN"; 
        cout << "\n2. Book Name"; 
        cout << "\n3. Author Name"; 
        cout << "\n4. Publisher Name"; 
        cout << "\nEnter choice: "; 
        cin >> choice; 
         
        string searchValue; 
 
        cout << "Enter your search value: "; 
        cin >> searchValue; 
 
        bool found = false; 
 
        switch(choice) { 
 
            case 1: 
            for (int i = 0; i<n; i++) { 
            if (books[i].getISBN() == searchValue) { 
                found = true; 
                books[i].display(); 
            } 
        } 
        break; 
        case 2: 
        for (int i = 0; i<n; i++) { 
            if (books[i].getName() == searchValue) { 
                found = true; 
                books[i].display(); 
            } 
        } 
        break; 
         
        case 3: 
        for (int i = 0; i<n; i++) { 
            if (books[i].getAuthor() == searchValue) { 
                found = true; 
                books[i].display(); 
            } 
        } 
        break; 
 
        case 4: 
        for (int i = 0; i<n; i++) { 
            if (books[i].getPublisher() == searchValue) { 
                found = true; 
                books[i].display(); 
            } 
        } 
        break; 
        } 
         
 
        if (!found) { 
            cout << "Book not found!\n"; 
        } 
 
    } 
 
    void heighestAndLowestCost(Book books[], int n) { 
        float highest = books[0].getPrice(); 
        float lowest = books[0].getPrice(); 
 
        for (int i = 1; i < n; i++) { 
            float price = books[i].getPrice(); 
 
            if (price > highest) { 
                highest = price; 
            } 
 
            if (price < lowest) { 
                lowest = price; 
            } 
        } 
 
        cout << "\nHighest price of book in library: " << highest; 
        cout << "\nLowest price of book in library: " << lowest << "\n"; 
} 
 
    //compare author for sort funtiion 
    bool compareAuthor(Book a, Book b) { 
            return a.getAuthor() < b.getAuthor(); 
        } 
 
    void numberBookBySameAuthor (Book books[], int n) { 
        //sort the authors alphabetically 
        //get the giveAuth from user 
        //use bs to find the number number of books by author 
        //once found the author count the number of their books 
        //prijnt number 
 
        sort(books, books + n, compareAuthor); 
 
        string givenAuthor; 
 
        cout << "\nNUMBER OF BOOKS BY GIVEN AUTHOR:\n"; 
        cout << "Enter the name of author: "; 
        cin >> givenAuthor; 
         
        //binary search 
        int left = 0; 
        int right = n - 1; 
        int requiredAuthor = -1; 
 
        while (left <= right) { 
 
            int mid = left + (left - right) / 2; 
 
            if (givenAuthor == books[mid].getAuthor()) { 
                requiredAuthor = mid; 
                break; 
            } 
            else if (givenAuthor < books[mid].getAuthor()) { 
                right = mid - 1; 
            } 
            else { 
                left = mid + 1; 
            } 
        } 
 
        if (requiredAuthor == -1) { 
            cout << "Author not found\n"; 
            return; 
        } 
 
        //count number of times the author occurs from the original index toward left and right 
        int count = 1; 
        int i = requiredAuthor - 1; 
         
        //towards left 
        while (i >=0 && books[i].getAuthor() == givenAuthor) { 
            count ++; 
            i--; 
        } 
 
        i = requiredAuthor + 1; 
        //toward right 
        while (i < n && books[i].getAuthor() == givenAuthor) { 
            count ++; 
            i++; 
        } 
 
        cout << "Number of books by the author: " << count << "\n"; 
 
    } 
 
 
int main () { 
 
    Book books[5]; 
 
    int n; 
 
    cout << "Enter the number of books: "; 
    cin >> n; 
 
    for (int i = 0; i < n; i++) { 
        cout << "Enter the details of the book: "; 
        books[i].acceptDetails(); 
    } 
 
    linearSearchBook(books, n); 
    heighestAndLowestCost(books, n); 
    numberBookBySameAuthor(books, n); 
}