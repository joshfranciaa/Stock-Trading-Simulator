#include <vector>
#include <unordered_map>

#ifndef PRIORITY_Q
#define PRIORITY_Q

template <class t1, class t2>
class priorityQ
{
private:
	struct priorityType
	{
		t1 key;
		t2 priority;
	};

	std::vector<priorityType> binMinHeap;
	std::unordered_map<t1, std::size_t> keyToIndex;

	void bubbleUp(std::size_t);
	void bubbleDown(std::size_t);

public:
	priorityQ();

	void push_back(const t1&, const t2&);
	void pop_front();
	
	t1 getRootKey() const;
	t2 getRootPriority() const;
	
	void update(const t1&, const t2&);

	bool isEmpty() const;
	std::size_t getSize() const;
	
};

#include "priorityQ.cpp"

#endif


