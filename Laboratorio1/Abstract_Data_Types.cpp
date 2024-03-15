// Abstract_Data_Types.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

template <typename Type> 
class CVector
{
private:
    Type* m_pVect; // Pointer to the buffer
    int m_nCount, // Control how many elements are actually used
        m_nMax, // Control the number of allocated elements
        m_nDelta; // To control the growing
    void Init(int delta, int max); // Init our private variables, etc
    void Resize(); // Resize the vector when occurs an overflow
public:
    CVector(int delta = 5, int max = 10); // Constructor
    void Insert(Type& elem); // Insert a new element
    void Print_vector();
};

template <typename Type>
void CVector<Type>::Init(int delta, int max) {
    m_nCount = 0;
    m_nMax = max;
    m_nDelta = delta;
    m_pVect = (Type*)malloc(m_nMax * sizeof(Type));
}

// Class CVector implementation
template <typename Type> 
CVector<Type>::CVector(int delta, int max)
{
    Init(delta, max);
}

template <typename Type>
void CVector<Type>::Resize() {
    m_pVect = (Type*)realloc(m_pVect, sizeof(Type) * (m_nMax + m_nDelta));
    m_nMax += m_nDelta;
}

template <typename Type> 
void CVector<Type>::Insert(Type& elem)
{
    if (m_nCount == m_nMax) // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

template <typename Type>
void CVector<Type>::Print_vector() {
    for (int* i = m_pVect; i < m_pVect + m_nCount; i++) {
        std::cout << *i << " ";
    }
}


int main()
{
    CVector<int> vec;
    for (int i = 0; i < 20; i++) {
        vec.Insert(i);
    }
    vec.Print_vector();
}

