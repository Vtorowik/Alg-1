#include <iostream>
#include <vector>
#include <>
using namespace std;

class BinaryHeap {
private:
    vector<int> heap;
    int getParentIndex(int i) { return (i - 1) / 2; }
    int getLeftChildIndex(int i) { return 2 * i + 1; }
    int getRightChildIndex(int i) { return 2 * i + 2; }
    void heapifyUp(int i) {
        if (i && heap[i] > heap[getParentIndex(i)]) {
            swap(heap[i], heap[getParentIndex(i)]);
            heapifyUp(getParentIndex(i));
        }
    }
    void heapifyDown(int i) {
        int left = getLeftChildIndex(i);
        int right = getRightChildIndex(i);
        int largest = i;
        if (left < size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    BinaryHeap() {}
    BinaryHeap(vector<int> arr) {
        for (int i = 0; i < arr.size(); i++) {
            insert(arr[i]);
        }
    }
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(size() - 1);
    }
    int getMax() {
        if (size() == 0) {
            throw "Heap is empty";
        }
        return heap[0];
    }
    int extractMax() {
        if (size() == 0) {
            throw "Heap is empty";
        }
        int max = heap[0];
        heap[0] = heap[size() - 1];
        heap.pop_back();
        heapifyDown(0);
        return max;
    }
    void merge(BinaryHeap& otherHeap) {
        for (int i = 0; i < otherHeap.size(); i++) {
            insert(otherHeap.heap[i]);
        }
    }
    int size() {
        return heap.size();
    }
};

int main() {
    BinaryHeap heap;
    heap.insert(5);
    heap.insert(10);
    heap.insert(3);
    heap.insert(8);
    cout << heap.getMax() << endl; // Output: 10
    cout << heap.extractMax() << endl; // Output: 10
    cout << heap.getMax() << endl; // Output: 8
    BinaryHeap otherHeap({1, 7, 2, 9});
    heap.merge(otherHeap);
    cout << heap.extractMax() << endl; // Output: 9
    return 0;
}