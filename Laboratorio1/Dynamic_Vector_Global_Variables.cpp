#include <iostream>

int* gpVect = NULL; // Dynamic buffer to save the elements int
int gnCount = 0; // Counter to know the number of used elements int
int gnMax = 0; // Variable containing the size of the allocated memory
int delta = 5;

void Resize()
{
    int* pTemp, i;
    pTemp = new int[gnMax + delta]; // Alloc a new vector
    for (i = 0; i < gnMax; i++) // Transfer the elements
        pTemp[i] = gpVect[i]; // we can also use the function memcpy
    delete[] gpVect; // delete the old vector
    gpVect = pTemp; // Update the pointer
    gnMax += delta; // The Max has to be increased by delta
}

void Insert(int elem)
{
    if (gnCount == gnMax) // There is no space at this moment for elem
        Resize(); // Resize the vector before inserting elem
    gpVect[gnCount++] = elem; // Insert the element at the end of the sequence
}


int main() {
    gnMax = 10;
    gpVect = new int[gnMax];
    for (int i = 0; i < 20; i++) {
        Insert(i);
        std::cout << gpVect[gnCount-1] << " ";
    }
    delete[]gpVect;
}