#ifndef PRIORITY_Q
#define PRIORITY_Q

#include <vector>
#include <unordered_map>
#include <cstddef>
#include <string>

template <class t1, class t2>
class priorityQ
{
private:
    struct priorityType {
        t1 key;
        t2 priority;
    };

    std::vector<priorityType> binMinHeap;
    std::unordered_map<t1, std::size_t> keyToIndex;

    void bubbleUp(std::size_t index);
    void bubbleDown(std::size_t index);

public:
    priorityQ();

    void push_back(const t1& key, const t2& priority);
    void pop_front();

    t1 getRootKey() const;
    t2 getRootPriority() const;

    void update(const t1& key, const t2& newPriority);

    bool isEmpty() const;
    std::size_t getSize() const;
};

#endif
