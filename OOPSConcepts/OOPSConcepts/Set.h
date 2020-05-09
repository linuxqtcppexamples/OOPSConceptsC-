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

	//Member functions

	/** Function Name: addElement
	* Usage: //Add an element to the set object. If the element is already in the set object, then DO NOT add it.
	*/
	

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

	/*Function : removeElement
	* Usage    : Return false only if the element is not in the set object. Otherwise, remove that element from the set
     object and then return true.
	*/
    bool removeElement(T data)
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

	//Opearator Overloading
	/*Functioname : operator +
	 *Usage: Return the union of the left set and the right set
	 */
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

	/*Functioname : operator -
	 *Usage: Return the difference of the left set from the right set
	 */
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

	/*Functioname : operator==
	 *Usage: Compare the two sets and return true if they are the same. Otherwise, return false. Note that two sets
			 are equal if every element of one set is also the element of the other regardless of the internal order
			 of elements in their representation.
	 */
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

	/*Functioname : operator!=
	 *Usage: Compare the two sets and return true if they are not the same. Otherwise, return false
	 */
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
	/*Functioname : operator= (or) assignment operator
	 *Usage: Copy the contents of the right set to the left set. After this operation, both sets should have only the
			  elements of the right set.
	 */
	void operator = (const Set const& obj) {
		
		std::copy(std::begin(obj.aSetsArray), std::end(obj.aSetsArray), std::begin(this->aSetsArray));
		this->nNoOfItemsInArray = obj.nNoOfItemsInArray;
	}

	/*Functioname : operator +=
	 *Usage: Perform the union of two sets and store the result in set which is at the left hand side of the equality.
			 Also return the union of the two sets.
	 */
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


	/*Functioname : operator <
	 *Usage:Return true only if the set on the left is a subset of the set on the right. Otherwise, return false
	 */
	friend bool operator < (Set const& obj1, Set const& obj2) 
	{

		bool bState = false;

		if (obj1.nNoOfItemsInArray < obj2.nNoOfItemsInArray)
		{
			return true;
		}

		return false;

	}

	/*Functioname : operator << (or) insertion
	 *Usage:Output the contents of the set
	 */

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

	/*Functioname : operator >> (or) extraction
	 *Usage:Output the contents of the set
	 */
	friend istream& operator>>(istream& input, Set& obj) {

		for (int nCount = obj.nNoOfItemsInArray; nCount < obj.aSetsArray.size(); nCount++)
		{
			cout << nCount << "." << " Element :" ;
			input >> obj.element;

			obj.addElement(obj.element);

		}
		
		return input;
	}

// Private Acess specifier member variables

private:

	// Array with defailt 10 element size
	array<T, 10> aSetsArray;
	//Number items filled in the array
	int nNoOfItemsInArray=0;
	//Element type  and T is datatype
	T element;
};

#endif