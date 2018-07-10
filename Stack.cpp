#include "Stack.h"


Stack::Stack()
{
	count = 0;
}

bool Stack::empty() const
{
	bool outcome = true;
	if(count > 0) outcome = false;
	return outcome;
}

Error_code Stack::pop()
{
	Error_code outcome = success;
	if(count == 0)
		outcome = overflow;
	else
		--count;
	return outcome;
}

Error_code Stack::top(Stack_entry &item) const
{
	Error_code outcome = success;
	if(count == 0)
		outcome = overflow;
	else
		item = entry[count-1];
	return outcome;
}

Error_code Stack::push(const Stack_entry &item)
{
	Error_code outcome = success;
	if(count >= maxstack)
		outcome = overflow;
	else
		entry[count++] = item;
	return outcome;
}
