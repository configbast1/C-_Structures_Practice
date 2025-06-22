#include <iostream>
#include <Windows.h>
using namespace std;
//5 задание

struct Student {
    char surname[30];
    char group[10];
    int marks[5];
};

void inputStudent(Student& st) {
    cout << "\nВведите фамилию: ";
    cin.getline(st.surname, 30);
    cout << "Введите группу: ";
    cin.getline(st.group, 10);

    cout << "Введите 5 оценок (через пробел): ";
    for (int i = 0; i < 5; i++) {
        cin >> st.marks[i];
    }
    cin.ignore();
}

void printStudent(const Student& st) {
    cout << "\nФамилия: " << st.surname << endl;
    cout << "Группа: " << st.group << endl;
    cout << "Оценки: ";
    for (int i = 0; i < 5; i++) {
        cout << st.marks[i] << " ";
    }
    cout << endl;
}

bool isExcellent(const Student& st) {
    int count5 = 0;
    for (int i = 0; i < 5; i++) {
        if (st.marks[i] == 5)
            count5++;
    }
    return (count5 >= 4); 
}

bool isFailing(const Student& st) {
    int badMarks = 0;
    for (int i = 0; i < 5; i++) {
        if (st.marks[i] == 2 || st.marks[i] == 3)
            badMarks++;
    }
    return (badMarks >= 3); 
}

void printExcellentStudents(Student* arr, int size) {
    cout << "\n--- Отличники ---\n";
    for (int i = 0; i < size; i++) {
        if (isExcellent(arr[i]))
            printStudent(arr[i]);
    }
}

void printFailingStudents(Student* arr, int size) {
    cout << "\n--- Двоечники ---\n";
    for (int i = 0; i < size; i++) {
        if (isFailing(arr[i]))
            printStudent(arr[i]);
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int count;
    cout << "Сколько студентов вы хотите ввести? ";
    cin >> count;
    cin.ignore();

    Student* students = new Student[count];

    for (int i = 0; i < count; i++) {
        cout << "\nСтудент #" << i + 1 << ":\n";
        inputStudent(students[i]);
    }

    cout << "\n--- Все студенты ---\n";
    for (int i = 0; i < count; i++) {
        printStudent(students[i]);
    }

    printExcellentStudents(students, count);
    printFailingStudents(students, count);

    delete[] students;

    return 0;
}
