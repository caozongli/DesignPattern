#include <iostream>
#include <vector>
#include <list>
#include <time.h>
#include <typeinfo>
using namespace std;


typedef struct iterator_tag {} iterator_tag;
typedef struct vector_iterator_tag : public iterator_tag {} vector_iterator_tag;
typedef struct list_iterator_tag : public iterator_tag {} list_iterator_tag;


template <typename T>
class iterator_traitsmy
{
public:
	typedef typename T::iterator_category iterator_category;
};



template<typename T, typename category>
class Iterator
{
public:
	typedef category iterator_category;
	virtual T begin() = 0;
	virtual T next() = 0;
	virtual bool isEnd() const = 0;
	virtual T currentItem() const = 0;
};


template<typename T, typename category>
class VectorCollectionIterator:public Iterator<T, category>
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


template<typename T, typename category>
class VectorCollection
{
private:
	vector<T> mc;
public:

	VectorCollection(vector<T> c): mc(c){}

	VectorCollectionIterator<T, category>* GetIterator()
	{
		return new VectorCollectionIterator<T, category>(mc);
	}
};


template<typename T, typename category>
class ListCollectionIterator:public Iterator<T, category>
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



template<typename T, typename category>
class ListCollection
{
private:
	list<T> mc;
public:

	ListCollection(list<T> mc): mc(mc){}

	ListCollectionIterator<T, category>* GetIterator()
	{
		return new ListCollectionIterator<T, category>(mc);
	}
};


template<class Iterator>
void __scan(Iterator* iter, iterator_tag p)
{
	for(iter->begin(); !iter->isEnd(); iter->next())
	{
		auto a = iter->currentItem();
	}
}


template<class VectorCollectionIterator>
void __scan(VectorCollectionIterator* iter, vector_iterator_tag p)
{
	for(iter->begin(); !iter->isEnd(); iter->next())
	{
		auto a = iter->currentItem();
	}
}


template<class ListCollectionIterator>
void __scan(ListCollectionIterator* iter, list_iterator_tag p)
{
	for(iter->begin(); !iter->isEnd(); iter->next())
	{
		auto a = iter->currentItem();
	}
}


template<class iterator>
void scan(iterator* iter)
{
	typedef typename iterator_traitsmy<iterator>::iterator_category c;
	__scan(iter, c());
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


	VectorCollection<int, vector_iterator_tag> mcV(vectorcollect);
	VectorCollectionIterator<int, vector_iterator_tag> *iterV = mcV.GetIterator();

	ListCollection<int, list_iterator_tag> mcL(listcollect);
	ListCollectionIterator<int, list_iterator_tag> *iterL = mcL.GetIterator();

	clock_t startTime, endTime;
	startTime = clock(); //计时开始

	scan(iterV);
	scan(iterL);	

	endTime = clock(); //计时结束
	cout << "The run time is:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

int main()
{
	myAlgorithm();
	
	return 0;
}