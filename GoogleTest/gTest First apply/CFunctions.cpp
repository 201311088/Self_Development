
#include "CFunctions.h"
#include <iostream>

CFunctions::CFunctions() {
    m_nIndex_pointer = 0;
}

CFunctions::CFunctions(int num_of_index) {
    m_nIndex_pointer = 0;

    for (int i = 0; i < num_of_index; i++)
    {
        m_nArr[i] = -1;
        m_nIndex_pointer++;
    }

    std::cout << "JMLEE 0000] m_nIndex_pointer: " << m_nIndex_pointer << std::endl;
}

int CFunctions::Insert(int value) {
    std::cout << "JMLEE 2] value: " << value << std::endl;
    std::cout << "JMLEE 2] m_nIndex_pointer: " << m_nIndex_pointer << std::endl;
    std::cout << "JMLEE 3] m_nIndex_pointer: " << m_nIndex_pointer << std::endl;
    m_nArr[m_nIndex_pointer] = value;
    if (m_nArr[m_nIndex_pointer] == value)
    {
        std::cout << "JMLEE ---- SUCCESS" << std::endl;
    }
    std::cout << "JMLEE 4] m_nIndex_pointer: " << m_nIndex_pointer << std::endl;
    m_nIndex_pointer++;

    return m_nIndex_pointer; // retrun pointer for the next value
}

// fuxxcking linux
void CFunctions::Delete(int index) 
{
    m_nArr[index] = -1;
}

void CFunctions::Update(int index, int value) {
    m_nArr[index] = value;
}

int CFunctions::Search(int index)
{
    return m_nArr[index];
}

int CFunctions::getValue(int index)
{
    return m_nArr[index];
}

int CFunctions::getIndex()
{
    return m_nIndex_pointer;
}