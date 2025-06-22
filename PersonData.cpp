#include <iostream>
#include <Windows.h>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Man {
    char surname[30];
    char name[30];
    int age;
    Date birth;
};

void inputMan(Man& man) {
    cout << "\nВведите фамилию: ";
    cin.getline(man.surname, 30);
    cout << "Введите имя: ";
    cin.getline(man.name, 30);
    cout << "Введите возраст: ";
    cin >> man.age;
    cout << "Введите дату рождения (день месяц год): ";
    cin >> man.birth.day >> man.birth.month >> man.birth.year;
    cin.ignore();
}

void printMan(const Man& man) {
    cout << "\nФамилия: " << man.surname << endl;
    cout << "Имя: " << man.name << endl;
    cout << "Возраст: " << man.age << endl;
    cout << "Дата рождения: " << man.birth.day << "." << man.birth.month << "." << man.birth.year << endl;
}

void printAll(Man* arr, int size) {
    for (int i = 0; i < size; i++) {
        printMan(arr[i]);
    }
}

void sortByField(Man* arr, int size, int field) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            const char* a = (field == 1) ? arr[i].surname : arr[i].name;
            const char* b = (field == 1) ? arr[j].surname : arr[j].name;

            for (int k = 0; k < 30; k++) {
                if (a[k] < b[k]) break;
                if (a[k] > b[k]) {
                    Man temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    break;
                }
                if (a[k] == '\0') break;
            }
        }
    }
}

void searchByMonth(Man* arr, int size, int month) {
    cout << "\n--- Именинники месяца #" << month << " ---\n";
    for (int i = 0; i < size; i++) {
        if (arr[i].birth.month == month) {
            printMan(arr[i]);
        }
    }
}

void searchByName(Man* arr, int size, const char* surname, const char* name) {
    for (int i = 0; i < size; i++) {
        bool found = true;
        for (int j = 0; j < 30; j++) {
            if (arr[i].surname[j] != surname[j]) {
                found = false;
                break;
            }
            if (arr[i].surname[j] == '\0') break;
        }
        if (found) {
            for (int j = 0; j < 30; j++) {
                if (arr[i].name[j] != name[j]) {
                    found = false;
                    break;
                }
                if (arr[i].name[j] == '\0') break;
            }
        }
        if (found) {
            cout << "\nНайдено:\n";
            printMan(arr[i]);
            return;
        }
    }
    cout << "Человек не найден.\n";
}

void editMan(Man& man) {
    cout << "\nРедактирование записи:\n";
    inputMan(man);
}

Man* addMan(Man* arr, int& size) {
    Man* newArr = new Man[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    inputMan(newArr[size]);
    delete[] arr;
    size++;
    return newArr;
}

Man* removeLast(Man* arr, int& size) {
    if (size <= 0) return arr;
    Man* newArr = new Man[size - 1];
    for (int i = 0; i < size - 1; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    size--;
    return newArr;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int size;
    cout << "Сколько людей ввести: ";
    cin >> size;
    cin.ignore();

    Man* people = new Man[size];
    for (int i = 0; i < size; i++) {
        inputMan(people[i]);
    }

    printAll(people, size);

    cout << "\nСортировка по фамилии:\n";
    sortByField(people, size, 1);
    printAll(people, size);

    int month;
    cout << "\nВведите номер месяца для именинников: ";
    cin >> month;
    cin.ignore();
    searchByMonth(people, size, month);

    char searchSurname[30], searchName[30];
    cout << "\nВведите фамилию для поиска: ";
    cin.getline(searchSurname, 30);
    cout << "Введите имя: ";
    cin.getline(searchName, 30);
    searchByName(people, size, searchSurname, searchName);

    int editIndex;
    cout << "\nВведите номер человека для редактирования (от 1): ";
    cin >> editIndex;
    cin.ignore();
    if (editIndex > 0 && editIndex <= size)
        editMan(people[editIndex - 1]);

    people = addMan(people, size);
    people = removeLast(people, size);

    cout << "\n--- Итоговый список ---\n";
    printAll(people, size);

    delete[] people;

    return 0;
}
