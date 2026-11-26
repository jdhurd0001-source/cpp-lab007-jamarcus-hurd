
#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>

// Recursive factorial
int factorial(int n) {
    if (n < 0)
        throw std::invalid_argument("Negative input");

    // Base case
    if (n == 0 || n == 1)
        return 1;

    // Recursive case
    return n * factorial(n - 1);
}

// Iterative factorial
int factorialIterative(int n) {
    if (n < 0)
        throw std::invalid_argument("Negative input");

    int result = 1;

    for (int i = 2; i <= n; i++)
        result *= i;

    return result;
}

// Recursive Fibonacci
int fibonacci(int n) {
    if (n < 0)
        throw std::invalid_argument("Negative input");

    // Base case
    if (n == 0 || n == 1)
        return n;

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Iterative Fibonacci
int fibonacciIterative(int n) {
    if (n < 0)
        throw std::invalid_argument("Negative input");

    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 2; i <= n; i++) {
        int next = previous + current;
        previous = current;
        current = next;
    }

    return current;
}

// Recursive binary search helper
static int binarySearchHelper(
    const std::vector<int>& array,
    int target, int left, int right) {

    // Base case: target not found
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    // Base case: target found
    if (array[mid] == target)
        return mid;

    // Recursive case: search the appropriate half
    if (target < array[mid])
        return binarySearchHelper(
            array, target, left, mid - 1);

    return binarySearchHelper(
        array, target, mid + 1, right);
}

// Recursive binary search
int binarySearch(const std::vector<int>& array,
                 int target) {
    return binarySearchHelper(
        array, target, 0,
        static_cast<int>(array.size()) - 1);
}

// Iterative binary search
int binarySearchIterative(
    const std::vector<int>& array, int target) {

    int left = 0;
    int right = static_cast<int>(array.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target)
            return mid;

        if (target < array[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

// Recursive array sum helper
static int arraySumHelper(
    const std::vector<int>& array,
    std::size_t index) {

    // Base case
    if (index == array.size())
        return 0;

    // Recursive case
    return array[index] +
           arraySumHelper(array, index + 1);
}

// Recursive array sum
int arraySum(const std::vector<int>& array) {
    return arraySumHelper(array, 0);
}

// Iterative array sum
int arraySumIterative(const std::vector<int>& array) {
    int sum = 0;

    for (int value : array)
        sum += value;

    return sum;
}

// Recursive reversal helper
static void reverseArrayHelper(
    std::vector<int>& array,
    int left, int right) {

    // Base case
    if (left >= right)
        return;

    // Recursive case
    std::swap(array[left], array[right]);

    reverseArrayHelper(array, left + 1, right - 1);
}

// Recursive in-place reversal
void reverseArray(std::vector<int>& array) {
    reverseArrayHelper(
        array, 0,
        static_cast<int>(array.size()) - 1);
}

// Iterative in-place reversal
void reverseArrayIterative(std::vector<int>& array) {
    int left = 0;
    int right = static_cast<int>(array.size()) - 1;

    while (left < right) {
        std::swap(array[left], array[right]);
        left++;
        right--;
    }
}
