#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i, bool isMaxHeap) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && ((isMaxHeap && arr[left] > arr[largest]) || (!isMaxHeap && arr[left] < arr[largest])))
        largest = left;

    // If right child is larger than largest so far
    if (right < n && ((isMaxHeap && arr[right] > arr[largest]) || (!isMaxHeap && arr[right] < arr[largest])))
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, isMaxHeap);
    }
}

void buildHeap(vector<int>& arr, bool isMaxHeap) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    buildHeap(arr, false); // For max heap pass true as second argument
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}