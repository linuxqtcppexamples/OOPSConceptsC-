#ifndef SET_H
#define SET_H

#include <Windows.h>
#include <iostream> 
#include <array>
#include <algorithm>
using namespace std;
template<typename  T> class Set
{
public:
	Set()//Constructor
	{

	}

	Set(T data)//Constructor
	{
		addElement(data);
	}

	Set(const Set& obj)//Copy constuctor
	{
		std::copy(std::begin(obj.aSetsArray), std::end(obj.aSetsArray), std::begin(this->aSetsArray));
		this->nNoOfItemsInArray = obj.nNoOfItemsInArray;
	}

	~Set()//destructor
	{

	}

	void addElement(T data)
	{
		bool isAlreadyExists = false;
		for (int nIndex1 = 0; nIndex1 < this->nNoOfItemsInArray; nIndex1++)
		{
			if (this->aSetsArray[nIndex1] == data)
			{
				isAlreadyExists = true;
				break;
			}
		}

		if (isAlreadyExists)
		{
			return;
		}

		aSetsArray[nNoOfItemsInArray] = data;
		//cout << "value at : " << nNoOfItemsInArray << ":" << aSetsArray[nNoOfItemsInArray] << endl;
		nNoOfItemsInArray++;
	}

	template<typename  T> bool removeElement(T data)
	{
		if (aSetsArray.empty())
		{
			return false;
		}

		bool bState = false;

		int nIndex;
		for (nIndex = 0; nIndex < nNoOfItemsInArray; nIndex++)
		{
			if (aSetsArray[nIndex] == data)
			{
				bState = true;
				break;

			}
		}
			
		if (!bState)
		{
			return false;
		}

		// If x found in array 
		if (nIndex < nNoOfItemsInArray)
		{
			// reduce size of array and move all 
			// elements on space ahead 
			nNoOfItemsInArray = nNoOfItemsInArray - 1;
			for (int j = nIndex; j < nNoOfItemsInArray; j++)
				aSetsArray[j] = aSetsArray[j + 1];
		}

		removeElement(data);
	 
		return bState;
	}

	Set operator + (Set const& obj) {
		Set res;
		/*res.aSetsArray = this.aSetsArray;
		res.nNoOfItemsInArray = this.aSetsArray;*/

		for (int nIndex = res.nNoOfItemsInArray; nIndex < this->nNoOfItemsInArray; nIndex++)
		{
			if (res.nNoOfItemsInArray < res.aSetsArray.size())
			{
				res.aSetsArray[res.nNoOfItemsInArray] = this->aSetsArray[nIndex];
				res.nNoOfItemsInArray++;
			}
		}

		for (int nIndex = obj.nNoOfItemsInArray; nIndex < obj.nNoOfItemsInArray; nIndex++)
		{
			if (res.nNoOfItemsInArray < res.aSetsArray.size())
			{
				res.aSetsArray[res.nNoOfItemsInArray] = obj.aSetsArray[nIndex];
				res.nNoOfItemsInArray++;
			}
		}
		
		return res;
	}

	friend Set operator - (Set const& obj1, Set const& obj2) {
		
		bool bState = false;

		Set res;

		if (obj1.nNoOfItemsInArray < obj2.nNoOfItemsInArray)
		{
			return res;
		}

		bool bState1 = false;

		for (int nIndex1 = 0; nIndex1 < obj1.nNoOfItemsInArray; nIndex1++)
		{
			bState1 = false;
			for (int nIndex2 = 0; nIndex2 < obj2.nNoOfItemsInArray; nIndex2++)
			{
				if (obj1.aSetsArray[nIndex1] == obj2.aSetsArray[nIndex2])
				{
					bState1 = true;
					break;
				}
			}

			if (!bState1)
			{
				res.aSetsArray[res.nNoOfItemsInArray] = obj1.aSetsArray[nIndex1];
				res.nNoOfItemsInArray++;
			}
		}

		return res;
	}

	friend bool operator == (Set const& obj1, Set const& obj2) {

		bool bState = false;

		if (obj1.nNoOfItemsInArray != obj2.nNoOfItemsInArray)
		{
			return bState;
		}

		bool bState1 = false;
		for (int nIndex1 = 0; nIndex1 < obj1.nNoOfItemsInArray; nIndex1++)
		{
			bState1 = false;
			for (int nIndex2 = 0; nIndex2 < obj2.nNoOfItemsInArray; nIndex2++)
			{
				if (obj1.aSetsArray[nIndex1] == obj2.aSetsArray[nIndex2])
				{
					bState1 = true;
				}
			}

			if (!bState1)
			{
				break;
			}
		}

		bState = bState1;

		
		return bState;
	}

	friend bool operator != (Set const& obj1, Set const& obj2) {

		bool bState = false;

		if (obj1.nNoOfItemsInArray != obj2.nNoOfItemsInArray)
		{
			return !bState;
		}

		bool bState1 = false;
		for (int nIndex1 = 0; nIndex1 < obj1.nNoOfItemsInArray; nIndex1++)
		{
			bState1 = false;
			for (int nIndex2 = 0; nIndex2 < obj2.nNoOfItemsInArray; nIndex2++)
			{
				if (obj1.aSetsArray[nIndex1] == obj2.aSetsArray[nIndex2])
				{
					bState1 = true;
				}
			}

			if (!bState1)
			{
				break;
			}
		}

		bState = bState1;


		return !bState;
	}

	void operator = (const Set const& obj) {
		
		std::copy(std::begin(obj.aSetsArray), std::end(obj.aSetsArray), std::begin(this->aSetsArray));
		this->nNoOfItemsInArray = obj.nNoOfItemsInArray;
	}

	friend void operator += (Set &obj1, Set & obj2) {


		bool bState1 = false;
		for (int nIndex1 = 0; nIndex1 < obj2.nNoOfItemsInArray; nIndex1++)
		{
			bState1 = false;

			for (int nIndex2 = 0; nIndex2 < obj1.nNoOfItemsInArray; nIndex2++)
			{

				if (obj2.aSetsArray[nIndex1] == obj1.aSetsArray[nIndex2])
				{
					bState1 = true;
					break;
				}


			}
			if (!bState1)
			{
				obj1.aSetsArray[obj1.nNoOfItemsInArray] = obj2.aSetsArray[nIndex1];
				obj1.nNoOfItemsInArray++;
			}
		}


		
	}

	//Set operator += (Set const& obj) {
	//	Set res;
	//	/*res.aSetsArray = this.aSetsArray;
	//	res.nNoOfItemsInArray = this.aSetsArray;*/

	//	for (int nIndex = res.nNoOfItemsInArray; nIndex < this->nNoOfItemsInArray; nIndex++)
	//	{
	//		if (res.nNoOfItemsInArray < res.aSetsArray.size())
	//		{
	//			res.aSetsArray[res.nNoOfItemsInArray] = this->aSetsArray[nIndex];
	//			res.nNoOfItemsInArray++;
	//		}
	//	}

	//	for (int nIndex = obj.nNoOfItemsInArray; nIndex < obj.nNoOfItemsInArray; nIndex++)
	//	{
	//		if (res.nNoOfItemsInArray < res.aSetsArray.size())
	//		{
	//			res.aSetsArray[res.nNoOfItemsInArray] = obj.aSetsArray[nIndex];
	//			res.nNoOfItemsInArray++;
	//		}
	//	}

	//	return res;
	//}


	friend bool operator < (Set const& obj1, Set const& obj2) 
	{

		bool bState = false;

		if (obj1.nNoOfItemsInArray < obj2.nNoOfItemsInArray)
		{
			return true;
		}

		return false;

	}



	friend ostream& operator<<(ostream& os, const Set& obj)
	{
		os << "{";

		for (int nCount = 0; nCount < obj.nNoOfItemsInArray; nCount++)
		{
			os << obj.aSetsArray.at(nCount);

			if (nCount < obj.nNoOfItemsInArray - 1)
			{
				os << ", ";
			}
		}
		os << "}";
		return os;
	}

	friend istream& operator>>(istream& input, Set& obj) {

		for (int nCount = obj.nNoOfItemsInArray; nCount < obj.aSetsArray.size(); nCount++)
		{
			cout << nCount << "." << " Element :" ;
			input >> obj.element;

			obj.addElement(obj.element);

		}
		
		return input;
	}


private:
	array<T, 10> aSetsArray;
	int nArraySize = 10;
	int nNoOfItemsInArray=0;
	T element;
};

#endif