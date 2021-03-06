#include "DynArray.hh"
#include <ostream>

//Constructor
DynArray::DynArray(void)
{
	m_capacity = DYN_ARRAY_DEFAULT_SIZE;	// Capacity	--> espacio total de la array
	m_size = 0;								// Size		--> numero de elementos usados
	m_data = new int[m_capacity];
}

DynArray::DynArray(size_t size, const int &value)
{
	m_capacity = size;
	m_size = size;
	m_data = new int[size];
}

//Destructor
DynArray::~DynArray(void)
{
	delete m_data;
}

//Iterators
int * DynArray::begin(void) const
{
	return m_data;
}

int * DynArray::end(void) const
{
	return m_data + m_size - 1;
}

//Capacity
void DynArray::resize(size_t n)
{
	m_data[m_capacity] = m_data[n];
}


//Modifier
void DynArray::assign(size_t n, const int & val)
{
	m_data[n] = val;
}

void DynArray::push(const int & val)
{
	
	if (m_size == m_capacity)
	{
		// Se redimensiona la array
		m_capacity += m_size / 2;
		int *tmp = new int[m_capacity];

		//Pasar los valores a la nueva array
		for (int i = 0; i < m_size; i++)
		{
			tmp[i] = m_data[i];
		}
		delete[] m_data;
		m_data = tmp;
		
	}
	m_data[m_size] = val;
	m_size++;
}

void DynArray::pop(void)
{

}

//Rational operator
bool operator==(const DynArray & lhs, const DynArray & rhs)
{
	return false;
}
