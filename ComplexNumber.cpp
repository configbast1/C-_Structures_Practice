#include <iostream>
#include <Windows.h> 
using namespace std; 
//1 задание 

struct Complex {
    double real; 
    double imag;
};
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}
Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}
Complex divide(Complex a, Complex b) {
    Complex result;
    double denominator = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}
void printComplex(Complex c) {
    cout << c.real;
    if (c.imag >= 0)
        cout << " + " << c.imag << "i" << endl;
    else
        cout << " - " << -c.imag << "i" << endl;
}

int main() {
    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Complex c1 = { 4, 3 };    
    Complex c2 = { 2, -1 };   

    cout << "Первое число: ";
    printComplex(c1);

    cout << "Второе число: ";
    printComplex(c2);

    Complex sum = add(c1, c2);
    cout << "Сумма: ";
    printComplex(sum);

    Complex diff = subtract(c1, c2);
    cout << "Разность: ";
    printComplex(diff);

    Complex prod = multiply(c1, c2);
    cout << "Произведение: ";
    printComplex(prod);

    Complex quot = divide(c1, c2);
    cout << "Частное: ";
    printComplex(quot);

    return 0;
}

