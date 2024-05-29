#include <iostream>
#include <vector>

template <class T>
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
    if (L[i] <= R[j]) {
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

template <class T> void mergeSort(std::vector<T> &arr, int left, int right) {
  if (left >= right)
    return;
  int mid = left + (right - left) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

struct tarea {
  int beneficio;
  int plazo;
  tarea(int b, int p) {
    beneficio = b;
    plazo = p;
  }
  tarea() {
    beneficio = 0;
    plazo = 0;
  }
  bool operator<=(const tarea &otro) const {
    if (plazo == otro.plazo) {
      return beneficio >= otro.beneficio;
    }
    return plazo <= otro.plazo;
  }
  tarea &operator=(const tarea &otro) {
    if (this != &otro) {
      beneficio = otro.beneficio;
      plazo = otro.plazo;
    }
    return *this;
  }
};

void planificarTareas(std::vector<tarea> &tareas, std::vector<tarea> &plan) {
  mergeSort(tareas, 0, tareas.size() - 1);
  int plazo = 1;
  int plazo_max = tareas.back().plazo;
  for (int i = 0; i < tareas.size() && plazo <= plazo_max; i++) {
    if (tareas[i].plazo >= plazo) {
      plan.push_back(tareas[i]);
      plazo++;
    }
  }
}

int main() {
  std::vector<tarea> tareas;
  std::vector<tarea> plan;

  /*
  //ingreso de datos en consola
  int b = 0;
  int p = 0;
  int n = 0;
  std::cout << "Ingrese numero de tareas: ";
  std::cin >> n;
  std::cout << '\n';
  for (int i = 0; i < n; i++) {
    std::cout << "Ingrese beneficio de la tarea " << i + 1 << ": ";
    std::cin >> b;
    std::cout << '\n';
    std::cout << "Ingrese plazo de la tarea " << i + 1 << ": ";
    std::cin >> p;
    tareas.push_back(tarea(b, p));
    std::cout << "\n\n";
  }
  */
  
  //sin ingresarr datos por consola
  tareas.push_back(tarea(20,3));
  tareas.push_back(tarea(15,1));
  tareas.push_back(tarea(10,1));
  tareas.push_back(tarea(7,3));
  tareas.push_back(tarea(5,1));
  tareas.push_back(tarea(3,3));
  
  
  int beneficio_max = 0;
  planificarTareas(tareas, plan);
  std::cout << "Solución:\nLas tareas deben ir en el siguiente orden para maximizar el beneficio\n\n";
  for (int i = 0; i < plan.size(); i++) {
    std::cout << i+1 <<"° : Tarea con beneficio " << plan[i].beneficio << " y plazo " << plan[i].plazo << '\n';
    beneficio_max += plan[i].beneficio;
  }
  std::cout << "Beneficio maximizado = " << beneficio_max;
}
