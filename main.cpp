/*
EQUIPE:
    - ANAMAYA
    - ANNY
    - LUCAS
TEMA: Bandas de Rock


*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
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
    cout << endl;
    cout << "                   Seja Bem-Vindo(a) ao" << endl;
    cout << "            Sistema de arquivo de bandas de Rock" << endl;
    cout << "                  de Anamaya, Anny e Lucas" << endl;
    sleep(3);
    cout << " " << endl;
    cout << "Digite que ação deseja tomar segundo o menu:" << endl;
    cout << " " << endl;
    sleep(2);
    string menu = "########################## MENU ##########################\n0 - SAIR\n1 - ler arquivo\n2 - gravar novo item\n3 - remover item\n4 - buscar item\n5 - salvar alterações\n##########################################################\n";
    cout << menu << endl;
    sleep(1);

    int escolha;
    cin >> escolha;

    switch (escolha){
        case 0: // SAIR
            break
        case 1: // ler arquivo
            LerDados()
        case 2: // gravar novo item
            EscreverDados()
        case 3: // remover item
            RemoverDados()
        case 4: // buscar item
            BuscarRegistro()
        case 5: // salvar alteracoes
            
            
    }

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
        // algo nao estÃ¡ certo aqui...
        
        short int identificador_verifica;
        cin >> identificador_verifica;

        if (identificador_verifica > tamanho) {
            ofstream arquivo("dados.csv");
            short int j = identificador_verifica;
            arquivo << info[j].identificador << ',' << info[j].nome << ',' 
                    << info[j].estiloMusical << ',' << info[j].ano << ',' << info[j].musicasFamosas << endl;
            
            tamanho ++;
        } else {
            cout << "identificador invalido!" << endl;
        }
    }

    for (int i = 0; i < tamanho; i++) {
        cout << info[i].identificador << ',' << info[i].nome << ',' << info[i].estiloMusical 
            << ',' << info[i].ano << ',' << info[i].musicasFamosas << endl;
    }
    
    arquivo.close();
    return 0;
}
