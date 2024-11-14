// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>   // Для роботи з файлами
#include <string>

using namespace std;

// Оголошуємо структуру Student з полями для інформації про студентів
struct Student {
    string lastName;     // Прізвище
    string firstName;    // Ім'я
    int course;          // Курс
    string group;        // Група
    string residence;    // Місце проживання ("гуртожиток" або "квартира")
};

int main() {
    // Кількість студентів
    const int numStudents = 5;

    // Масив студентів
    Student students[numStudents] = {
        {"Фурман", "Наталія", 3, "3СОМ", "гуртожиток"},
        {"Тимошенко", "Ірина", 3, "3СОМ", "квартира"},
        {"Кирильчук", "Анастасія", 1, "1СОМ", "гуртожиток"},
        {"Рабоченко", "Денис", 4, "4СОМ", "квартира"},
        {"Мерчук", "Анастасія", 2, "2СОМ", "квартира"}
    };

    // Відкриваємо файл для запису
    ofstream outFile("results.txt");
    if (!outFile) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        return 1; // Код помилки
    }

    // Лічильник студентів, які проживають на квартирі
    int apartmentCount = 0;

    outFile << "Студенти, які проживають на квартирі:" << endl;

    // Проходимо через усіх студентів
    for (int i = 0; i < numStudents; ++i) {
        // Перевіряємо, чи студент проживає на квартирі
        if (students[i].residence == "квартира") {
            // Записуємо дані про студента у файл
            outFile << "Прізвище: " << students[i].lastName << endl
                << "Ім'я: " << students[i].firstName << endl
                << "Курс: " << students[i].course << endl
                << "Група: " << students[i].group << endl
                << "Місце проживання: " << students[i].residence << endl
                << endl;

            // Збільшуємо лічильник студентів, які проживають на квартирі
            apartmentCount++;
        }
    }

    // Записуємо кількість студентів у файл
    outFile << "Кількість студентів, які проживають на квартирі: " << apartmentCount << endl;

    // Закриваємо файл
    outFile.close();

    cout << "Результати записано у файл results.txt" << endl;

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
