#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int cambio = 100;
  std::vector<int> c = {94,1,50};
  std::vector<std::vector<int>> D(c.size(), std::vector<int>(cambio + 1, 0));
  std::vector<int> x(c.size(),0);
  int a;
  int b;
  for (int i = 0; i < D.size(); i++) {
    for (int j = 1; j < D[i].size(); j++) {
      a = (i == 0) ? 99999 : D[i - 1][j];
      b = (j - c[i] < 0) ? 99999 : D[i][j - c[i]];
      D[i][j] = std::min(a,b+1);
    }
  }
  int i = c.size()-1;
  int j = cambio;
  while(i>=0 && j>0){
    int a = (i==0)?99999:D[i-1][j];
    if(D[i][j]==a){
      i = i-1;
    }
    else{
      x[i] = x[i]+1;
      j = j-c[i];
    }
  }
  if(D[c.size()-1][cambio] >= 99999){
    std::cout << "no se puede devolver esa cantidad con las monedas";
  }
  else{
    std::cout << "[ ";
    for (i = 0; i < x.size(); i++) {
      std::cout << x[i] << " ";
    }
    std::cout << "]";
  }
  
}