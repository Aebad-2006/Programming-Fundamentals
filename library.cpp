#include <iostream>
#include <string>
using namespace std;

// ============================================
// PROJECT: Library Management System
// COURSE: Programming Fundamentals
// ============================================
// GROUP MEMBERS:
// 1. NAME: Aebad Humair              | CMS ID: 1412-2026
// 2. NAME: Saad Alam                 | CMS ID: 1020-2026  
// 3. NAME: Ali Irtiza                | CMS ID: 277-2026
// ============================================

// Arrays for storing book data
int bookID[100];
string bookTitle[100];
string bookAuthor[100];
int bookCopies[100];
int totalBooks = 0;

// Function prototypes
void showMenu();
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void deleteBook();
void showGroupInfo();

int main() {
    int choice;
    
    // Initial sample data (so library empty na lage)
    bookID[0] = 101;
    bookTitle[0] = "Programming Fundamentals";
    bookAuthor[0] = "Robert Lafore";
    bookCopies[0] = 5;
    
    bookID[1] = 102;
    bookTitle[1] = "C++ Complete Reference";
    bookAuthor[1] = "Herbert Schildt";
    bookCopies[1] = 3;
    
    bookID[2] = 103;
    bookTitle[2] = "Data Structures";
    bookAuthor[2] = "Seymour Lipschutz";
    bookCopies[2] = 4;
    
    totalBooks = 3;
    
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                deleteBook();
                break;
            case 7:
                showGroupInfo();
                break;
            case 8:
                cout << "\n========================================\n";
                cout << "Thanks for using Library System!\n";
                cout << "========================================\n";
                break;
            default:
                cout << "\nInvalid choice! Please enter 1-8\n";
        }
    } while(choice != 8);
    
    return 0;
}

void showMenu() {
    cout << "\n========================================\n";
    cout << "     WELCOME TO LIBRARY SYSTEM\n";
    cout << "========================================\n";
    cout << "1. Add New Book\n";
    cout << "2. Display All Books\n";
    cout << "3. Search Book by ID\n";
    cout << "4. Issue Book\n";
    cout << "5. Return Book\n";
    cout << "6. Delete Book\n";
    cout << "7. Show Group Members\n";
    cout << "8. Exit\n";
    cout << "========================================\n";
}

void showGroupInfo() {
    cout << "\n========================================\n";
    cout << "         GROUP MEMBERS INFO\n";
    cout << "========================================\n";
    cout << "Member 1:\n";
    cout << "  Name    : Aebad Humair\n";
    cout << "  CMS ID  : 1412-2026\n";
    cout << "  Course  : Programming Fundamentals\n";
    cout << "----------------------------------------\n";
    cout << "Member 2:\n";
    cout << "  Name    : Saad Alam\n";
    cout << "  CMS ID  : 1020-2026\n";
    cout << "  Course  : Programming Fundamentals\n";
    cout << "----------------------------------------\n";
    cout << "Member 3:\n";
    cout << "  Name    : Ali Irtiza\n";
    cout << "  CMS ID  : 277-2026\n";
    cout << "  Course  : Programming Fundamentals\n";
    cout << "========================================\n";
}

void addBook() {
    cout << "\n--- ADD NEW BOOK ---\n";
    
    if(totalBooks >= 100) {
        cout << "Library is full! Cannot add more books.\n";
        return;
    }
    
    cout << "Enter Book ID: ";
    cin >> bookID[totalBooks];
    
    // Check if ID already exists
    for(int i = 0; i < totalBooks; i++) {
        if(bookID[i] == bookID[totalBooks]) {
            cout << "Book ID already exists! Try different ID.\n";
            return;
        }
    }
    
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, bookTitle[totalBooks]);
    
    cout << "Enter Author Name: ";
    getline(cin, bookAuthor[totalBooks]);
    
    cout << "Enter Number of Copies: ";
    cin >> bookCopies[totalBooks];
    
    while(bookCopies[totalBooks] < 1) {
        cout << "Copies must be at least 1. Enter again: ";
        cin >> bookCopies[totalBooks];
    }
    
    totalBooks++;
    cout << "\n? Book Added Successfully!\n";
    cout << "Total books in library: " << totalBooks << endl;
}

void displayBooks() {
    if(totalBooks == 0) {
        cout << "\nNo books in library yet! Add some books first.\n";
        return;
    }
    
    cout << "\n--- ALL BOOKS IN LIBRARY ---\n";
    cout << "========================================================\n";
    
    for(int i = 0; i < totalBooks; i++) {
        cout << "Book #" << (i+1) << endl;
        cout << "  ID      : " << bookID[i] << endl;
        cout << "  Title   : " << bookTitle[i] << endl;
        cout << "  Author  : " << bookAuthor[i] << endl;
        cout << "  Copies  : " << bookCopies[i] << endl;
        cout << "--------------------------------------------------------\n";
    }
    
    cout << "Total Books: " << totalBooks << endl;
}

void searchBook() {
    if(totalBooks == 0) {
        cout << "\nNo books in library!\n";
        return;
    }
    
    int searchID;
    cout << "\n--- SEARCH BOOK ---\n";
    cout << "Enter Book ID to search: ";
    cin >> searchID;
    
    bool found = false;
    
    for(int i = 0; i < totalBooks; i++) {
        if(bookID[i] == searchID) {
            cout << "\n-----------------------------------\n";
            cout << "         BOOK FOUND!\n";
            cout << "-----------------------------------\n";
            cout << "Book ID     : " << bookID[i] << endl;
            cout << "Title       : " << bookTitle[i] << endl;
            cout << "Author      : " << bookAuthor[i] << endl;
            cout << "Copies      : " << bookCopies[i] << endl;
            
            if(bookCopies[i] > 0) {
                cout << "Status      : ? Available\n";
            } else {
                cout << "Status      : ? Not Available\n";
            }
            cout << "-----------------------------------\n";
            found = true;
            break;
        }
    }
    
    if(!found) {
        cout << "\n? Book with ID " << searchID << " not found!\n";
    }
}

void issueBook() {
    if(totalBooks == 0) {
        cout << "\nNo books in library!\n";
        return;
    }
    
    int issueID;
    string studentName;
    int days;
    
    cout << "\n--- ISSUE BOOK ---\n";
    cout << "Enter Book ID to issue: ";
    cin >> issueID;
    
    bool found = false;
    
    for(int i = 0; i < totalBooks; i++) {
        if(bookID[i] == issueID) {
            found = true;
            
            if(bookCopies[i] > 0) {
                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, studentName);
                cout << "Enter Days to keep book: ";
                cin >> days;
                
                bookCopies[i]--;
                
                cout << "\n-----------------------------------\n";
                cout << "         ISSUE RECEIPT\n";
                cout << "-----------------------------------\n";
                cout << "Student Name : " << studentName << endl;
                cout << "Book Title   : " << bookTitle[i] << endl;
                cout << "Book ID      : " << bookID[i] << endl;
                cout << "Issue Date   : " << __DATE__ << endl;
                cout << "Return Date  : " << days << " days from today\n";
                cout << "Remaining Copies: " << bookCopies[i] << endl;
                cout << "-----------------------------------\n";
                cout << "? Book Issued Successfully!\n";
            } else {
                cout << "\n? Sorry! No copies available for this book.\n";
            }
            break;
        }
    }
    
    if(!found) {
        cout << "\n? Book with ID " << issueID << " not found!\n";
    }
}

void returnBook() {
    if(totalBooks == 0) {
        cout << "\nNo books in library!\n";
        return;
    }
    
    int returnID;
    cout << "\n--- RETURN BOOK ---\n";
    cout << "Enter Book ID to return: ";
    cin >> returnID;
    
    bool found = false;
    
    for(int i = 0; i < totalBooks; i++) {
        if(bookID[i] == returnID) {
            found = true;
            bookCopies[i]++;
            
            cout << "\n-----------------------------------\n";
            cout << "         RETURN RECEIPT\n";
            cout << "-----------------------------------\n";
            cout << "Book Title   : " << bookTitle[i] << endl;
            cout << "Book ID      : " << bookID[i] << endl;
            cout << "Return Date  : " << __DATE__ << endl;
            cout << "Total Copies Now: " << bookCopies[i] << endl;
            cout << "-----------------------------------\n";
            cout << "? Book Returned Successfully!\n";
            break;
        }
    }
    
    if(!found) {
        cout << "\n? Book with ID " << returnID << " not found!\n";
    }
}

void deleteBook() {
    if(totalBooks == 0) {
        cout << "\nNo books to delete!\n";
        return;
    }
    
    int deleteID;
    cout << "\n--- DELETE BOOK ---\n";
    cout << "Enter Book ID to delete: ";
    cin >> deleteID;
    
    bool found = false;
    
    for(int i = 0; i < totalBooks; i++) {
        if(bookID[i] == deleteID) {
            found = true;
            
            char confirm;
            cout << "Are you sure you want to delete \"" << bookTitle[i] << "\"? (y/n): ";
            cin >> confirm;
            
            if(confirm == 'y' || confirm == 'Y') {
                for(int j = i; j < totalBooks - 1; j++) {
                    bookID[j] = bookID[j+1];
                    bookTitle[j] = bookTitle[j+1];
                    bookAuthor[j] = bookAuthor[j+1];
                    bookCopies[j] = bookCopies[j+1];
                }
                totalBooks--;
                cout << "\n? Book Deleted Successfully!\n";
            } else {
                cout << "\nDeletion cancelled.\n";
            }
            break;
        }
    }
    
    if(!found) {
        cout << "\n? Book with ID " << deleteID << " not found!\n";
    }
}
