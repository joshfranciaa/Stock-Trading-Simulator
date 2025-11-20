#include "priorityQ.h"
#include <algorithm>
#include <iostream>

// ----------------------------------------------------
// TEMPLATE IMPLEMENTATIONS (definitions go here)
// ----------------------------------------------------

template <class t1, class t2>
priorityQ<t1, t2>::priorityQ() {
    binMinHeap.resize(1);  // dummy element at index 0
}

template <class t1, class t2>
void priorityQ<t1, t2>::push_back(const t1& key, const t2& priority) {
    priorityType newElement{key, priority};
    binMinHeap.push_back(newElement);

    std::size_t index = binMinHeap.size() - 1;
    keyToIndex[key] = index;

    bubbleUp(index);
}

template <class t1, class t2>
void priorityQ<t1, t2>::pop_front() {
    if (binMinHeap.size() <= 1)
        return;

    keyToIndex.erase(binMinHeap[1].key);

    // Move last element to root
    binMinHeap[1] = binMinHeap.back();
    binMinHeap.pop_back();

    if (binMinHeap.size() > 1) {
        keyToIndex[binMinHeap[1].key] = 1;
        bubbleDown(1);
    }
}

template <class t1, class t2>
t1 priorityQ<t1, t2>::getRootKey() const {
    return binMinHeap[1].key;
}

template <class t1, class t2>
t2 priorityQ<t1, t2>::getRootPriority() const {
    return binMinHeap[1].priority;
}

template <class t1, class t2>
void priorityQ<t1, t2>::update(const t1& key, const t2& newPriority) {
    if (!keyToIndex.count(key))
        return;

    std::size_t index = keyToIndex[key];
    t2 oldPriority = binMinHeap[index].priority;

    binMinHeap[index].priority = newPriority;

    if (newPriority < oldPriority)
        bubbleUp(index);
    else
        bubbleDown(index);
}

template <class t1, class t2>
bool priorityQ<t1, t2>::isEmpty() const {
    return binMinHeap.size() <= 1;
}

template <class t1, class t2>
std::size_t priorityQ<t1, t2>::getSize() const {
    return binMinHeap.size() - 1;
}

template <class t1, class t2>
void priorityQ<t1, t2>::bubbleUp(std::size_t index) {
    while (index > 1) {
        std::size_t parent = index / 2;
        if (binMinHeap[index].priority < binMinHeap[parent].priority) {
            std::swap(binMinHeap[index], binMinHeap[parent]);

            keyToIndex[binMinHeap[index].key] = index;
            keyToIndex[binMinHeap[parent].key] = parent;

            index = parent;
        } else {
            break;
        }
    }
}

template <class t1, class t2>
void priorityQ<t1, t2>::bubbleDown(std::size_t index) {
    std::size_t size = binMinHeap.size();

    while (true) {
        std::size_t left = 2 * index;
        std::size_t right = 2 * index + 1;
        std::size_t smallest = index;

        if (left < size && binMinHeap[left].priority < binMinHeap[smallest].priority)
            smallest = left;

        if (right < size && binMinHeap[right].priority < binMinHeap[smallest].priority)
            smallest = right;

        if (smallest != index) {
            std::swap(binMinHeap[index], binMinHeap[smallest]);

            keyToIndex[binMinHeap[index].key] = index;
            keyToIndex[binMinHeap[smallest].key] = smallest;

            index = smallest;
        } else {
            break;
        }
    }
}

// ----------------------------------------------------
// EXPLICIT TEMPLATE INSTANTIATIONS
// ----------------------------------------------------

// Used in main.cpp
template class priorityQ<std::string, double>;

// Used in priorityQTest.cpp
template class priorityQ<std::string, int>;
