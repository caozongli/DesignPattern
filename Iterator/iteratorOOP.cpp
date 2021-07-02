#include <iostream>
using namespace std;

template<typename T>
class Iterator
{
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool hasNext() const = 0;
	virtual T& currentItem() = 0;
};

template<typename T>
class MyCollection
{
	//....
	Iterator<T> GetIterator()
	{

	};
};

template<typename T>
class CollectionIterator:public Iterator<T>
{
	MyCollection<T> mc;
public:
	CollectionIterator(const MyCollection<T>&c):mc(c){}
	void first() override{

	}
	void next() override{

	}
	bool hasNext() const override{

	}
	T& currentItem() override{

	}

}

void myAlgorithm()
{
	MyCollection<int> mc;
	Iterator<int> iter = mc.GetIterator();

	for(iter.first(); !iter.isDone(); iter.next())
	{
		cout << iter.current() << endl;
	}
}



