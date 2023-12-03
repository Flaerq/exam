#include <iostream>
#include <cmath>

using namespace std;


double positiveSum(double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
    return sum;
}

double maxAbs(double arr[], int size) {
    double max = abs(arr[0]);
    for (int i = 1; i < size; i++) {
        if (abs(arr[i]) > max) {
            max = abs(arr[i]);
        }
    }
    return max;
}

double minAbs(double arr[], int size) {
    double min = abs(arr[0]);
    for (int i = 1; i < size; i++) {
        if (abs(arr[i]) < min) {
            min = abs(arr[i]);
        }
    }
    return min;
}

double product(double arr[], int size) {
    double max = maxAbs(arr, size);
    double min = minAbs(arr, size);
    double result = 1.0;
    bool isBetween = false;

    for (int i = 0; i < size; ++i) {
        if (isBetween) {
            result *= arr[i];
        }
        if (abs(arr[i]) == max || abs(arr[i]) == min) {
            isBetween = !isBetween;
        }
    }
    return result;
}

void bubbleDesc(double arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(double arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    
    setlocale(LC_ALL, "Ukrainian");
    
    double arr[10] = { -8.5, 4.5, 2.3, -0.5, -7.1, 4.2, 6.8, 5.3, -2.4, 9.5 };
    int size = 10;

    double min = minAbs(arr, size);
    double max = maxAbs(arr,size);
    double sum = positiveSum(arr, size);

    double absProduct = product(arr,size);
    

    cout << "Сума додатніх елементів: " << sum << endl;

    cout << "Добуток елементів масиву, розташованих між максимальним за модулем і мінімальним за модулем елементами: " << absProduct << endl;

    bubbleDesc(arr, size);
    cout << "Відсортований массив за спаданням: ";
    printArray(arr, size);

    return 0;
}
