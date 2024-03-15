#include <iostream>

// Class CVector definition
class CVector
{
private:
    int* m_pVect, // Pointer to the buffer
        m_nCount, // Control how many elements are actually used
        m_nMax, // Control how many are allocated as maximum
        m_nDelta; // To control the growing
    void Init(int delta, int max); // Init our private variables, etc
    void Resize(); // Resize the vector when occurs an overflow
public:
    CVector(int delta = 5, int max = 10); // Constructor
    void Insert(int elem); // Insert a new element
    void Print_vector();
    // More methods go here
};

CVector::CVector(int delta, int max) {
    Init(delta, max);
}

void CVector::Init(int delta, int max) {
    m_nCount = 0;
    m_nMax = max;
    m_nDelta = delta;
    m_pVect = (int*)malloc(m_nMax * sizeof(int));
}

void CVector::Resize() {
    m_pVect = (int*)realloc(m_pVect, sizeof(int) * (m_nMax + m_nDelta));
    m_nMax += m_nDelta;
}

void CVector::Insert(int elem) {
    if (m_nCount == m_nMax) // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

void CVector::Print_vector() {
    for (int* i = m_pVect; i < m_pVect + m_nCount; i++) {
        std::cout << *i << " ";
    }
}

int main()
{
    CVector vec;
    for (int i = 0; i < 20; i++) {
        vec.Insert(i);
    }
    vec.Print_vector();
}
