#include <iostream>
#include <Windows.h>
using namespace std;
//2 задание 
  
struct Car {
    float length;
    float clearance;
    float engineVolume;
    int enginePower;
    float wheelDiameter;
    char color[20];
    char gearbox[20];
};

void inputCar(Car& car) {
    cout << "\nВведите длину (в метрах): ";
    cin >> car.length;
    cout << "Введите клиренс (в метрах): ";
    cin >> car.clearance;
    cout << "Введите объем двигателя (в литрах): ";
    cin >> car.engineVolume;
    cout << "Введите мощность двигателя (в л.с.): ";
    cin >> car.enginePower;
    cout << "Введите диаметр колёс (в дюймах): ";
    cin >> car.wheelDiameter;

    cin.ignore();

    cout << "Введите цвет: ";
    cin.getline(car.color, 20);
    cout << "Введите тип коробки передач: ";
    cin.getline(car.gearbox, 20);
}

void printCar(const Car& car) {
    cout << "\n--- Автомобиль ---\n";
    cout << "Длина: " << car.length << " м\n";
    cout << "Клиренс: " << car.clearance << " м\n";
    cout << "Объем двигателя: " << car.engineVolume << " л\n";
    cout << "Мощность: " << car.enginePower << " л.с.\n";
    cout << "Диаметр колёс: " << car.wheelDiameter << " дюймов\n";
    cout << "Цвет: " << car.color << "\n";
    cout << "Коробка передач: " << car.gearbox << "\n";
}

bool stringsEqual(const char* a, const char* b) {
    for (int i = 0; i < 20; i++) {
        if (a[i] != b[i]) return false;
        if (a[i] == '\0') break;
    }
    return true;
}

void searchByColor(Car cars[], int size, const char* color) {
    cout << "\nРезультаты поиска по цвету \"" << color << "\":\n";
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (stringsEqual(cars[i].color, color)) {
            printCar(cars[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Машины с таким цветом не найдены.\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    const int SIZE = 2;
    Car cars[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "\nВведите данные для машины #" << i + 1 << ":\n";
        inputCar(cars[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        printCar(cars[i]);
    }

    char searchColor[20];
    cout << "\nВведите цвет машины для поиска: ";
    cin.getline(searchColor, 20);

    searchByColor(cars, SIZE, searchColor);

    return 0;
}

