#include <iostream>
#include <algorithm>


int task(double* arr, int n) {
    if (n <= 0) {
        std::cout << "Размер массива должен быть положительным числом" << std::endl;
        return 0.;
    }

    int positiveFirstIndex = -1;
    int positiveLastIndex = -1;

    for (int i = 0; i < n; i++) {
        double target = arr[i];
        if (target <= 0) continue;
        if (positiveFirstIndex == -1) {
            positiveFirstIndex = i;
            continue;
        }
        positiveLastIndex = i;
    }

    if (positiveFirstIndex == -1) {
        std::cout << "Отсутствуют положительные числа" << std::endl;
        return 0.;
    }

    if (positiveLastIndex == -1) {
        std::cout << "Отсутствует 2 положительное число" << std::endl;
        return 0.;
    }

    if (positiveFirstIndex == positiveLastIndex) {
        std::cout << "Максимальный и минимальный элемент - один и тот же элемент" << std::endl;
        return 0.;
    }

    double sum = 0;

    for (int i = positiveFirstIndex + 1; i < positiveLastIndex; i++) {
        double target = arr[i];
        sum += target;
    }

    return sum;
}

void empty_array() {
    int n = 0;
    double arr[1] = {};
    double result = task(arr, n);

    if (result == 0.) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

void single_positive_number() {
    const int n = 5;
    double arr[n] = {1, -1,-1,-1,-1};
    double result = task(arr, n);

    if (result == 0.) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

void only_negative() {
    const int n = 5;
    double arr[n] = { -1, -1,-1,-1,-1 };
    double result = task(arr, n);

    if (result == 0.) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

void two_positive() {
    const int n = 5;
    double arr[n] = { 1, -1,-1,-1, 1 };
    double result = task(arr, n);

    if (result == -3.) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

void several_positive() {
    const int n = 5;
    double arr[n] = { 1, 1,-1,-1, 1 };
    double result = task(arr, n);

    if (result == -1.) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    empty_array();
    single_positive_number();
    only_negative();
    two_positive();
    several_positive();
    return 0;
}
