/*
EQUIPE:
    - ANAMAYA
    - ANNY
    - LUCAS
TEMA:


*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct BandasDeRock {
    int identificador;
    string nome;
    string estiloMusical;
    short int ano;
    short int musicasFamosas;

};

void LerDados(){}
void EscreverDados(){}
void RemoverDados(){}
void RedimensionarVetor(){}
void BuscarRegistro(){}
void MostrarDados(){}


int main ()
{

    int tamanho = 60;
    BandasDeRock* info = new BandasDeRock[tamanho];
    string linha, dado;
    string identificador, nome, estiloMusical, ano, musicasFamosas;

    // Abrir arquivo
    ifstream arquivo("dados.csv");

    // LER TODO O ARQUIVO
    int i = 0;
    while(getline(arquivo, linha) and i < 60){

        // SEPARAR OS DADOS 
        stringstream sep(linha);
        // IMPRIMIR DADOS SEPARADOS
        getline(sep, identificador, ',');
        getline(sep, nome, ',');
        getline(sep, estiloMusical, ',');
        getline(sep, ano, ',');
        getline(sep, musicasFamosas, ',');

        info[i].identificador = stoi(identificador);
        info[i].nome = nome;
        info[i].estiloMusical = estiloMusical;
        info[i].ano = stoi(ano);
        info[i].musicasFamosas = stoi(musicasFamosas);

        cout << info[i].identificador << " | ";
        cout << info[i].nome << "|";
        cout << info[i].estiloMusical << " | ";
        cout << info[i].ano << "|";
        cout << info[i].musicasFamosas << " | " << endl;

        
        i++;
        cout << endl;
    }


    // INSERIR DADOS
    cout << "Inserir dados: " << endl;
    string inserir;
    cin >> inserir;
    if (inserir == "S"){
        BandasDeRock* info = new BandasDeRock[tamanho++];
        cin >> identificador >> nome >> estiloMusical >> ano >> musicasFamosas;
        info[tamanho].identificador = stoi(identificador);
        info[tamanho].nome = nome;
        info[tamanho].estiloMusical = estiloMusical;
        info[tamanho].ano = stoi(ano);
        info[tamanho].musicasFamosas = stoi(musicasFamosas);

        cout << info[tamanho].identificador << " | ";
        cout << info[tamanho].nome << "|";
        cout << info[tamanho].estiloMusical << " | ";
        cout << info[tamanho].ano << "|";
        cout << info[tamanho].musicasFamosas << " | " << endl;

        // INSERINDO NO ARQUIVO
        // algo nao está certo aqui...
        ofstream arquivo("dados.csv");
        for(int j = 0; j < tamanho; j++){
            arquivo << info[j].identificador << ',' << info[j].nome << ',' << info[j].estiloMusical << ',' << info[j].ano << ',' << info[j].musicasFamosas << endl;
        }
    }
    arquivo.close();
    return 0;
}
