template<typename T>
class MyCollection
{
	typename ... const_iterator;

	const_iterator first() const{}

	const_iterator next() const{}

	const_iterator hasNext() const{}

	const_iterator& currentItem() const{}

}

template<typename T>
class Mycollection2
{
	typename ... const_iterator;

	const_iterator first() const{}

	const_iterator next() const{}

	const_iterator hasNext() const{}

	const_iterator currentItem() const{}
}

template<typename T>
void MyAlgorithm(T const & coll)
{
	T::const_iterator iter;
	for(iter=coll.first(); iter!=coll.hasNext; iter=coll.hasNext())
	{
		
	}
}