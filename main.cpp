/*
 * Вариант 6. «Сортировщик оценок»
 * В университете хранится список оценок студентов. Нужно его обработать:
 *   - Сгенерировать массив из N оценок (от 1 до 10).
 *   - Реализовать функцию сортировки массива по возрастанию (любым алгоритмом).
 *   - Найти средний балл.
 *   - Вывести все оценки в виде отсортированной таблицы.
 *
 * ! Важно: реализовать сортировку самим, а не использовать готовые функции.
*/

#include <iostream>  // для вывода текста в консоль

#include <cstdlib>  // для генерации псевдо-случайных чисел
#include <ctime>

using namespace std;

const int MIN_RANGE = 1;
const int MAX_RANGE = 10;
const int ARR_SIZE = 100;

void fillUpArray(int[], int);
void sortArray(int[], int);
void printArray(int[], int);
double calculateAverageValue(int[], int);
void printTabled(int[], int);

int main() {
    srand(time(0));
    int numbers[ARR_SIZE] = {0};

    cout << "Изначальный массив из " << ARR_SIZE << " случайных чисел:" << endl;
    fillUpArray(numbers, ARR_SIZE);
    printArray(numbers, ARR_SIZE);

    cout << endl << endl << "---------------------------------------------" << endl << endl;

    cout << "Отсортированный по возрастанию массив (метод сортировки: Чёт-Нечёт):" << endl;
    sortArray(numbers, ARR_SIZE);
    printArray(numbers, ARR_SIZE);

    cout << endl << endl << "---------------------------------------------" << endl << endl;

    cout << "Среднее значение элементов массива:" << endl << calculateAverageValue(numbers, ARR_SIZE);

    cout << endl << endl << "---------------------------------------------" << endl << endl;

    cout << "Элементы массива в табличном виде:" << endl;
    printTabled(numbers, ARR_SIZE);

    return 0;
}


/*
 * Заполняет заданный массив псевдо-случайными числами в диапазоне [MIN_RANGE, MAX_RANGE]
 * @param array массив целых чисел
 * @param size количество элементов заполняемого массива
*/
void fillUpArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = MIN_RANGE + rand() % (MAX_RANGE - MIN_RANGE + 1);
    }
}


/*
 * Сортирует заданный массив по возрастанию методом Чёт-Нечёт
 * @param array массив целых чисел
 * @param size количество элементов сортируемого массива
*/
void sortArray(int array[], int size) {
    int temp = 0;

    for (int i = 0; i < size; i++) {
        // k поочерёдно принимает начальные значения 0 и 1, таким образом осуществляем проход по разным парам элементов
        // Чётная итерация      (сравниваем пары элементов с индексами: [0-1], [2-3], [4-5], ...)
        // Нечётная итерация    (сравниваем пары элементов с индексами: [1-2], [3-4], [5-6], ...)
        for (int k = (i % 2 == 0) ? 0 : 1; k < size - 1; k += 2) {  // (прибавляем к счётчику по 2, а не по 1, чтобы оставлять число чётным/нечётным)
            if (array[k] > array[k + 1]) {
                temp = array[k];
                array[k] = array[k + 1];
                array[k + 1] = temp;
            }
        }
    }
}


/*
 * Выводит на экран элементы заданного массива, разделённые пробелами (array[0] array[1] array[2] ...)
 * @param array массив целых чисел
 * @param size количество элементов выводимого массива
*/
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}


/*
 * Находит среднее значение всех элементов массива путём сложения всех элементов и последующего деления на размер массива
 * @param array массив целых чисел
 * @param size количество элементов анализируемого массива
 * @return среднее значение элементов массива
*/
double calculateAverageValue(int array[], int size) {
    double arr_sum = 0.0;
    for (int i = 0; i < size; i++) {
        arr_sum += array[i];
    }
    return arr_sum / size;
}


/*
 * Выводит на экран элементы заданного массива в табличном виде (элементы с разными значениями на разных строках)
 * @param array массив целых чисел
 * @param size количество элементов выводимого массива
*/
void printTabled(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        cout << array[i] << "\t";
        if (array[i] != array[i + 1]) {
            cout << endl;
        }
    }
    cout << array[size - 1];
}