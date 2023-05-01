#ifndef EWDVECTOR
#define EWDVECTOR

#include <iostream>
#include <vector>

namespace ewd
{
	template<typename T>
	class vector
	{
	public:

		using value_type = T;
		using pointer = T*;

		vector();
		vector(const vector& other);
		vector(vector&& other) noexcept; // greu
		~vector();

		vector& operator=(const vector& other);
		vector& operator=(vector&& other) noexcept; // greu

		unsigned int size() const;
		pointer data();
		unsigned int capacity();

		void clear();
		void push_back(const value_type& element);
		void insert(const value_type& element, unsigned int pos);

		value_type& operator[](unsigned int offset);
		const value_type& operator[](unsigned int offset) const;
		value_type& at(unsigned int offset);
		const value_type& at(unsigned int offset) const;
		//next:
		value_type& front();
		value_type& back();
		bool empty();
		value_type& pop_back();
		void erase(unsigned int offset);
		void erase(unsigned int start, unsigned int finish);

	private:
		pointer m_data;
		unsigned int m_size;
		unsigned int m_capacity;

		void realloc(unsigned int newCapacity);
	};

	template<typename T>
	vector<T>::vector()
		: m_data(nullptr), m_size(0), m_capacity(0)
	{}

	//template<typename T>
	//vector<T>::vector(vector&& other)//mutare
	//{



	//}

	template<typename T>
	vector<T>::vector(const vector& other)
	{
		pointer newBlock = new value_type[other.m_size];
		if (newBlock != nullptr && other.m_data != nullptr)
		{
			for (unsigned int i = 0; i < other.m_size; ++i)
			{
				newBlock[i] = other[i];
			}
		}
		clear();
		m_data = newBlock;
		m_capacity = other.m_capacity;
		m_size = other.m_size;
	}

	template<typename T>
	typename vector<T>::vector& vector<T>::operator=(const vector& other)
	{
		pointer newBlock = new value_type[other.m_size];
		if (newBlock != nullptr && other.m_data != nullptr)
		{
			for (unsigned int i = 0; i < other.m_size; ++i)
			{
				newBlock[i] = other[i];
			}
		}
		clear();
		m_data = newBlock;
		m_capacity = other.m_capacity;
		m_size = other.m_size;
		return *this;
	}

	//template<typename T>
	//typename vector<T>::vector& vector<T>::operator=(vector&& other)//mutare
	//{
	//	/*pointer newBlock = new value_type[other.m_size];
	//	if (newBlock != nullptr && other.m_data != nullptr)
	//	{
	//		for (unsigned int i = 0; i < other.m_size; ++i)
	//		{
	//			newBlock[i] = other[i];
	//		}
	//	}
	//	clear();
	//	m_data = newBlock;
	//	m_capacity = other.m_capacity;
	//	return m_data;*/
	//}

	template<typename T>
	vector<T>::~vector()
	{
		delete[] m_data;
		//m_size = 0;
		//m_capacity = 0;
	}

	template<typename T>
	unsigned int vector<T>::size() const
	{
		return m_size;
	}

	template<typename T>
	typename vector<T>::pointer vector<T>::data()//return pointer
	{
		return m_data;
	}

	template<typename T>
	unsigned int vector<T>::capacity()//return capacity
	{
		return m_capacity;
	}

	template<typename T>
	void vector<T>::clear()
	{
		delete[] m_data;
		//m_size = 0;
		//m_capacity = 0;
	}

	template<typename T>
	void vector<T>::push_back(const value_type& element)
	{
		if (m_size >= m_capacity)
		{
			realloc(m_capacity + m_capacity / 2);
		}
		m_data[m_size] = element;
		++m_size;
	}

	template<typename T>
	typename vector<T>::value_type& vector<T>::pop_back()
	{
		if (m_size == 0) std::cout << "ESTE GOL!";
		else
		{
			value_type aux = m_data[m_size - 1];
			erase(m_size);
			return aux;
			
		}
	}

	template<typename T>
	void vector<T>::erase(unsigned int offset)
	{
		if(offset>m_size) throw std::out_of_range("Out of bounds acces!");
		else
		{
			--m_size;
			for (int i = offset; i < m_size; i++)
			{
				m_data[i] = m_data[i + 1];
			}
		}
	}

	template<typename T>
	void vector<T>::erase(unsigned int start, unsigned int finish)
	{
		if (finish > m_size) throw std::out_of_range("Out of bounds acces!");
		else
		{
			unsigned int diff = finish - start + 1;//se vor sterge atatea el. si diff de pozitie dintre ele
			m_size = m_size - diff;
			for (int i = start; i < m_size; i++)
			{
				m_data[i] = m_data[i + diff];
			}
		}
	}

	template<typename T>
	typename vector<T>::value_type& vector<T>::front()
	{
		return m_data[0];
	}

	template<typename T>
	typename vector<T>::value_type& vector<T>::back()
	{
		return m_data[m_size-1];
	}

	template<typename T>
	bool vector<T>::empty()
	{
		if (m_size == 0) return true;
		else return false;
	}

	template<typename T>
	typename vector<T>::value_type& vector<T>::operator[](unsigned int offset)
	{
		return m_data[offset];
	}

	template<typename T>
	typename const vector<T>::value_type& vector<T>::operator[](unsigned int offset) const
	{
		return m_data[offset];
	}

	template<typename T>
	typename vector<T>::value_type& vector<T>::at(unsigned int offset)
	{
		if (offset > m_size)
			throw std::out_of_range("Out of bounds acces!");
		return m_data[offset];
	}

	template<typename T>
	const typename vector<T>::value_type& vector<T>::at(unsigned int offset) const
	{
		if (offset > m_size)
			throw std::out_of_range("Out of bounds acces!");
		return m_data[offset];
	}

	template<typename T>
	void vector<T>::realloc(unsigned int newCapacity)
	{
		if (newCapacity < 10)
			newCapacity = 10;
		pointer newBlock = new value_type[newCapacity];
		if (newBlock != nullptr && m_data != nullptr)
		{
			for (unsigned int i = 0; i < m_size; ++i)
			{
				newBlock[i] = m_data[i];
			}
		}
		delete[] m_data;
		m_data = newBlock;
		m_capacity = newCapacity;
	}


};

#endif