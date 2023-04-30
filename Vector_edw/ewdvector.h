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
		vector(const vector& other);//copiere
		vector(vector&& other) noexcept; // greu
		~vector();

		vector& operator=(const vector& other);//copiere
		vector& operator=(vector&& other) noexcept; // greu

		unsigned int size() const;
		pointer data();
		unsigned int capacity();

		void push_back(const value_type& element);
		void insert(const value_type& element, unsigned int pos);

		value_type& operator[](unsigned int offset);
		const value_type& operator[](unsigned int offset) const;
		value_type& at(unsigned int offset);
		const value_type& at(unsigned int offset) const;

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

	template<typename T>
	vector<T>::~vector()
	{
		delete[] m_data;
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