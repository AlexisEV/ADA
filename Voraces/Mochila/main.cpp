#include <iostream>
#include <vector>

template<class T>
void merge(std::vector<T> &arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<T> L(n1);
  std::vector<T> R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  int i = 0;
  int j = 0;
  int k = left;
  while (i < n1 && j < n2) {
    if (L[i] >= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

template<class T>
void mergeSort(std::vector<T> &arr, int left, int right) {
  if (left >= right) return; 
  int mid = left + (right - left) / 2; 
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

struct objeto {
  float peso;
  float beneficio;
  float razon;
  objeto(int p, int b) {
    peso = p;
    beneficio = b;
    if(peso != 0) razon = beneficio / peso;
    else razon = 0;
  }
  objeto(){
    peso = 0;
    beneficio = 0;
    razon = 0;
  }
  bool operator>=(const objeto &otro) const { 
    return razon >= otro.razon; 
  }
  bool operator<=(const objeto &otro) const { 
    return razon <= otro.razon; 
  }
  objeto& operator=(const objeto& otro){
    if(this != &otro){
      peso = otro.peso;
      beneficio = otro.beneficio;
      razon = otro.razon;
    }
    return *this;
  }
};

void mochila(int &capacidad, std::vector<objeto>& objetos, std::vector<float>& solucion) {
  mergeSort(objetos, 0, objetos.size()-1);
  int pesoActual = 0;
  int i = 0;
  while(pesoActual<capacidad&&i<objetos.size()){
    if (pesoActual+objetos[i].peso <= capacidad){
      solucion[i] = 1;
      pesoActual = pesoActual+objetos[i].peso;
      i++;
    }
    else{
      solucion[i] = (capacidad - pesoActual)/static_cast<float>(objetos[i].peso);
      pesoActual = capacidad;
      i++;
    }
  }
}

int main() {
  int capacidad = 10;
  std::vector<objeto> objetos;
  float beneficio_max = 0;
 
  objetos.push_back(objeto(10, 10));
  objetos.push_back(objeto(3, 9));
  objetos.push_back(objeto(3, 9));
  objetos.push_back(objeto(4, 9));
  std::vector<float> solucion(objetos.size(),0);
  
  mochila(capacidad,objetos,solucion);
  
  std::cout << "Solución:\nSe deben incluir en la mochila los siguientes objetos para maximizar el beneficio\n\n";
  for(int i = 0; i < objetos.size(); i++){
    std::cout << solucion[i] << " del objeto con peso " << objetos[i].peso << " y beneficio " << objetos[i].beneficio << '\n';
    beneficio_max += objetos[i].beneficio*solucion[i];
  }
  std::cout << "Beneficio maximizado = " << beneficio_max;
}