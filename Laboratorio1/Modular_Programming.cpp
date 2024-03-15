
#include <iostream>

struct Vector
{
    int* m_pVect, // Pointer to the buffer
        m_nCount, // Control how many elements are actually used
        m_nMax, // Control how many are allocated as maximum
        m_nDelta; // To control the growing
};

void Resize(Vector* pThis)
{
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
    // The Max has to be increased by delta
    pThis->m_nMax += pThis->m_nDelta;
}


void Insert(Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) // Verify the overflow
        Resize(pThis); // Resize the vector before inserting elem
    // Insert the element at the end of the sequence
    pThis->m_pVect[pThis->m_nCount++] = elem;
}


int main()
{
    Vector vect;
    vect.m_nCount = 0;
    vect.m_nMax = 10;
    vect.m_nDelta = 5;
    vect.m_pVect = (int*)malloc(vect.m_nMax * sizeof(int));

    for (int i = 0; i < 20; i++) {
        Insert(&vect, i);
    }
    for (int* i = vect.m_pVect; i < vect.m_pVect + vect.m_nCount; i++) {
        std::cout << *i << " ";
    }
}
