#include <iostream>
#include <vector>
#include <list>
#include <time.h>
using namespace std;

template<typename T>
class Iterator
{
public:
	virtual T begin() = 0;
	virtual T next() = 0;
	virtual bool isEnd() const = 0;
	virtual T currentItem() const = 0;
};


template<typename T>
class VectorCollectionIterator:public Iterator<T>
{
private:
	vector<T> mc;
	int posi;
public:
	VectorCollectionIterator(vector<T> c):mc(c), posi(-1){}

	T begin(){
		if(mc.empty()) return {};
		posi = 0;
		return mc[posi];
	}

	T next(){
		if(isEnd()) return {};
		return mc[++posi];
	}

	bool isEnd() const {
		if(posi == mc.size()-1) return true;
		return false;
	}

	T currentItem() const {
		if(-1 == posi) return {};
		return mc[posi];
	}

};


template<typename T>
class VectorCollection
{
private:
	vector<T> mc;
public:

	VectorCollection(vector<T> c): mc(c){}

	VectorCollectionIterator<T>* GetIterator()
	{
		return new VectorCollectionIterator<T>(mc);
	}
};


template<typename T>
class ListCollectionIterator:public Iterator<T>
{
private:
	list<T> mc;
	typename list<T>::iterator posi;
public:
	ListCollectionIterator(list<T> &c):mc(c){ posi= mc.begin();}

	T begin(){
		if(mc.empty()) return {};
		posi = mc.begin();
		return *(mc.begin());
	}

	T next(){
		if(isEnd()) return {};
		return *(++posi);
	}

	bool isEnd() const {
		if(posi == mc.end()) return true;
		return false;
	}

	T currentItem() const {
		return *posi;
	}

};



template<typename T>
class ListCollection
{
private:
	list<T> mc;
public:

	ListCollection(list<T> mc): mc(mc){}

	ListCollectionIterator<T>* GetIterator()
	{
		return new ListCollectionIterator<T>(mc);
	}
};

template <typename T>
void scan(Iterator<T>* iter)
{
	for(iter->begin(); !iter->isEnd(); iter->next())
	{
		auto a = iter->currentItem();
	}
}


void myAlgorithm()
{
	vector<int> vectorcollect;
	list<int> listcollect;
	for(int i=1; i<10000000; i++)
	{
		vectorcollect.push_back(i);
		listcollect.push_back(i);
	}


	VectorCollection<int> mcV(vectorcollect);
	VectorCollectionIterator<int> *iterV = mcV.GetIterator();

	ListCollection<int> mcL(listcollect);
	ListCollectionIterator<int> *iterL = mcL.GetIterator();


	clock_t startTime, endTime;
	startTime = clock(); //????????????

	scan(iterV);
	scan(iterL);	

	endTime = clock(); //????????????
	cout << "The run time is:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

int main()
{
	myAlgorithm();
	return 0;
}


