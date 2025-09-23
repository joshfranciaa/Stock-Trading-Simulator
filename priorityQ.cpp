#include "priorityQ.h"
#include <cstdlib>
using namespace std;

template <class t1, class t2>
priorityQ<t1, t2>::priorityQ(){
    binMinHeap.resize(1); // initialize the heap with one unused element at index 0
}

template <class t1, class t2>
void priorityQ<t1, t2>::push_back(const t1& key, const t2& priority){
    priorityType newElement; // create a new heap element
    newElement.key = key;      // assign the key
    newElement.priority = priority; // assign the priority
    binMinHeap.push_back(newElement); // insert into heap
    keyToIndex[key] = binMinHeap.size() - 1; // track index of key
    bubbleUp(binMinHeap.size() - 1); // restore heap order
}

template <class t1, class t2>
void priorityQ<t1, t2>::pop_front(){
    if (binMinHeap.size() <= 1) return; // if heap is empty, do nothing
    keyToIndex.erase(binMinHeap[1].key); // remove root key from index map
    binMinHeap[1] = binMinHeap.back(); // replace root with last element
    binMinHeap.pop_back(); // remove last element
    if (binMinHeap.size() > 1) {
        keyToIndex[binMinHeap[1].key] = 1; // update index map
        bubbleDown(1); // restore heap order from root
    }
}

template <class t1, class t2>
t1 priorityQ<t1, t2>::getRootKey() const{
    return binMinHeap[1].key; // return root key
}

template <class t1, class t2>
t2 priorityQ<t1, t2>::getRootPriority() const{
    return binMinHeap[1].priority; // return root priority
}

template <class t1, class t2>
void priorityQ<t1, t2>::update(const t1& key, const t2& newPriority) {
    if (!keyToIndex.count(key)) return; // exit if key not found

    size_t pos = keyToIndex[key]; // get position in heap
    t2 oldPriority = binMinHeap[pos].priority; // store old priority
    binMinHeap[pos].priority = newPriority; // update to new
    if (newPriority < oldPriority) {
        bubbleUp(pos); // bubble up if new is smaller
    }
    else {
        bubbleDown(pos); // otherwise bubble down
    }
}

template <class t1, class t2>
bool priorityQ<t1, t2>::isEmpty() const {
    return binMinHeap.size() <= 1; // check if heap only has dummy node
}

template <class t1, class t2>
size_t priorityQ<t1, t2>::getSize() const {
    return binMinHeap.size() - 1; // return number of actual elements
}

template <class t1, class t2>
void priorityQ<t1, t2>::bubbleUp(size_t index){
   while (index > 1) { // loop until root
       size_t parentIdx = index / 2; // get parent index

       if (binMinHeap[index].priority < binMinHeap[parentIdx].priority) {
           swap(binMinHeap[index], binMinHeap[parentIdx]); // swap with parent
           keyToIndex[binMinHeap[index].key] = index; // update index map
           keyToIndex[binMinHeap[parentIdx].key] = parentIdx; // update index map
           index = parentIdx; // move up
       } 
        else {
            break; // done if order is correct
        }

   }
}

template <class t1, class t2>
void priorityQ<t1, t2>::bubbleDown(size_t index){
   size_t heapSize = binMinHeap.size();

   while (true) {
       size_t leftChild = 2 * index;
       size_t rightChild = 2 * index + 1;
       size_t smallest = index;

       if (leftChild < heapSize && binMinHeap[leftChild].priority < binMinHeap[smallest].priority) {
           smallest = leftChild;
        }
       if (rightChild < heapSize && binMinHeap[rightChild].priority < binMinHeap[smallest].priority) {
           smallest = rightChild;
        }
       if (smallest != index) {
           swap(binMinHeap[index], binMinHeap[smallest]); // swap with smaller child

           keyToIndex[binMinHeap[index].key] = index; // update map

           keyToIndex[binMinHeap[smallest].key] = smallest; // update map
           
           index = smallest; // move down
       } 
        else {
            break; // done if in correct position
        }
   }
}


