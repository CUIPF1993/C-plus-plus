#ifndef STACH_H_
#define STACH_H_

typedef unsigned long Item;

class Stack
{
private:
	enum { MAX = 5 };
	Item items[MAX];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item &item);
	bool pop(Item &item);
};

#endif // !1
