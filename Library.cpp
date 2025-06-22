#include <iostream>
#include <Windows.h>
using namespace std;

struct Book {
    char title[50];
    char author[50];
    char publisher[50];
    char genre[30];
};

void inputBook(Book& book) {
    cout << "\nВведите название книги: ";
    cin.getline(book.title, 50);
    cout << "Введите автора: ";
    cin.getline(book.author, 50);
    cout << "Введите издательство: ";
    cin.getline(book.publisher, 50);
    cout << "Введите жанр: ";
    cin.getline(book.genre, 30);
}

void printBook(const Book& book) {
    cout << "\n--- Книга ---\n";
    cout << "Название: " << book.title << endl;
    cout << "Автор: " << book.author << endl;
    cout << "Издательство: " << book.publisher << endl;
    cout << "Жанр: " << book.genre << endl;
}

bool stringsEqual(const char* a, const char* b) {
    for (int i = 0; i < 50; i++) {
        if (a[i] != b[i]) return false;
        if (a[i] == '\0') break;
    }
    return true;
}

void searchByAuthor(Book books[], int size, const char* author) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (stringsEqual(books[i].author, author)) {
            printBook(books[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "\nКниг данного автора не найдено.\n";
    }
}

void searchByTitle(Book books[], int size, const char* title) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (stringsEqual(books[i].title, title)) {
            printBook(books[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "\nКнига с таким названием не найдена.\n";
    }
}

void printAllBooks(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        printBook(books[i]);
    }
}

void editBook(Book& book) {
    cout << "\nРедактирование книги:\n";
    inputBook(book);
}

void sortBooks(Book books[], int size, int sortField) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            const char* field1;
            const char* field2;

            if (sortField == 1) {
                field1 = books[i].title;
                field2 = books[j].title;
            } else if (sortField == 2) {
                field1 = books[i].author;
                field2 = books[j].author;
            } else {
                field1 = books[i].publisher;
                field2 = books[j].publisher;
            }

            for (int k = 0; k < 50; k++) {
                if (field1[k] < field2[k]) break;
                if (field1[k] > field2[k]) {
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                    break;
                }
                if (field1[k] == '\0') break;
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    const int SIZE = 3;
    Book books[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "\nВведите данные для книги #" << i + 1 << ":\n";
        inputBook(books[i]);
    }

    cout << "\n--- Все книги ---\n";
    printAllBooks(books, SIZE);

    char search[50];
    cout << "\nВведите имя автора для поиска: ";
    cin.getline(search, 50);
    searchByAuthor(books, SIZE, search);

    cout << "\nВведите название книги для поиска: ";
    cin.getline(search, 50);
    searchByTitle(books, SIZE, search);

    cout << "\nСортировка по названию:\n";
    sortBooks(books, SIZE, 1);
    printAllBooks(books, SIZE);

    return 0;
}

