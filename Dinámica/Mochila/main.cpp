#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int capacidad = 17;
  int n = 5;
  std::vector<int> p = {2, 3, 6, 9, 11};
  std::vector<int> b = {3, 6, 9, 7, 14};
  std::vector<int> x(p.size(), 0);
  std::vector<std::vector<int>> V(n + 1, std::vector<int>(capacidad + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= capacidad; j++) {
      if (j - p[i - 1] < 0) {
        V[i][j] = V[i - 1][j];
      } else {
        V[i][j] = std::max(V[i - 1][j], b[i - 1] + V[i - 1][j - p[i - 1]]);
      }
    }
  }

  int i = n;
  int j = capacidad;
  while (i > 0 && j > 0) {
    if (V[i][j] == V[i - 1][j]) {
      x[i - 1] = 0;
      i = i - 1;
    } else if (j - p[i - 1] >= 0 &&
               V[i][j] == b[i - 1] + V[i - 1][j - p[i - 1]]) {
      x[i - 1] = 1;
      j = j - p[i - 1];
      i = i - 1;
    }
  }

  std::cout << "[";
  for (i = 0; i < x.size(); i++) {
    std::cout << x[i] << " ";
  }
  std::cout << "]";
  std::cout << "\nBeneficio maximizado: " << V[n][capacidad];
  return 0;
}