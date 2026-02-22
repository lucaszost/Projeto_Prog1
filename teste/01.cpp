#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(){
  ifstream arquivo("alunos.csv");
  string linha, campo;
  
  while (getline(arquivo, linha)){
    stringstream ss(linha);

    while(getline(ss, campo, ',')){
      cout << campo << " | ";
    }
    cout << endl;
  }

  arquivo.close();
  return 0;
}

