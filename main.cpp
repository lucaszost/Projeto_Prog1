/*
EQUIPE:
    - ANAMAYA
    - ANNY
    - LUCAS
TEMA:
    - BANDAS DE ROCK

*/

/*
TAREFAS

1 - Inserir (OK)
2 - Remover
3 - Buscar  (ok)
4 - Mostrar todos (OK)
5 - Mostrar intervalo (ok)
6 - Salvar (OK)
0 - Sair (OK)


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

void MostrarMenu() {
    string menu = 
        "########################## MENU ##########################\n"
        "0 - SAIR\n"
        "1 - MOSTRAR DADOS\n"
        "2 - MOSTRAR INTERVALO\n"
        "3 - BUSCAR DADOS\n"
        "4 - INSERIR DADOS\n"
        "5 - REMOVER\n"
        "##########################################################\n";

    cout << menu;
}

void RedimensionarVetor(BandasDeRock*& info, int& tamanho){
    int NovoTamanho = tamanho + 1;
    BandasDeRock* New_info = new BandasDeRock[NovoTamanho];

    // copiando os dados antigos

    for(int i = 0; i < tamanho; i++){
        New_info[i] = info[i];
    }

    delete[] info; // LIBERA A MEMORIA ANTIGA
    info = New_info; // REDEFINE O VALOR DO ANTIGO VETOR PARA O NOVO E ATUALIZADO
    tamanho = NovoTamanho; // OS NOVOS DADOS DE TAMANHO VAI PRA VARIAVEL ORIGINAL

}

void MostrarDados(BandasDeRock* info, int tamanho){

    string linha, identificador, nome, estiloMusical, ano, musicasFamosas;
    
    // Abrir arquivo
    ifstream arquivo("dados.csv");
    int i = 0;
    while(getline(arquivo, linha) and i < tamanho){

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

        cout << i+1 << "ª: " ;
        cout << info[i].identificador << " | ";
        cout << info[i].nome << "|";
        cout << info[i].estiloMusical << " | ";
        cout << info[i].ano << "|";
        cout << info[i].musicasFamosas << " | " << endl;


        i++;
        cout << endl;
    }

    arquivo.close();
    MostrarMenu();

}

void MostrarIntervalo(BandasDeRock* info, int tamanho){
    int inicial, final;
    cout << "MOSTRAR INTERVALO DE DADOS! " << endl;
    cout << "Id inicial: " << endl;
    cin >> inicial;
    cout << "Id final: " << endl;
    cin >> final;

    inicial--;
    final--;

    string linha, identificador, nome, estiloMusical, ano, musicasFamosas;
    ifstream arquivo("dados.csv");
    int i = 0;
    while(getline(arquivo, linha) and i < tamanho){

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

        if(inicial <= i  and i <= final){
            cout << i+1 << "ª: " ;
            cout << info[i].identificador << " | ";
            cout << info[i].nome << "|";
            cout << info[i].estiloMusical << " | ";
            cout << info[i].ano << "|";
            cout << info[i].musicasFamosas << " | " << endl;
        }

        i++;
    
    }

    arquivo.close();
    

    MostrarMenu();

}

void BuscarDados(BandasDeRock* info, int tamanho){
    cout << "Busca por id: " << endl;
    int busca;
    cin >> busca;
    cout << busca << "ª: " ;
    busca--;

    if (busca < tamanho){
        cout << info[busca].identificador << " | ";
        cout << info[busca].nome << "|";
        cout << info[busca].estiloMusical << " | ";
        cout << info[busca].ano << "|";
        cout << info[busca].musicasFamosas << " | " << endl;

    }else{
        cout << "Valor inválido!" << endl;
    }

    MostrarMenu();
}

void InserirDados(BandasDeRock*& info, int& tamanho){

    string nome, estiloMusical, ano, musicasFamosas;
    cout << "===INSERIR DADOS === " << endl;
    cout << "Nome: " << endl;
    cin >> nome;
    cout << "Estilo Musical: " << endl;
    cin >> estiloMusical;
    cout << "Ano: " << endl;
    cin >> ano;
    cout << "Q. Musicas Famosas: " << endl;
    cin >> musicasFamosas;

    RedimensionarVetor(info, tamanho);
    int n_tam = tamanho -1;

    info[n_tam].identificador = tamanho;
    info[n_tam].nome = nome;
    info[n_tam].estiloMusical = estiloMusical;
    info[n_tam].ano = stoi(ano);
    info[n_tam].musicasFamosas = stoi(musicasFamosas);

    cout << endl;
    cout << "Dados inseridos): " << endl;
    cout << endl;
    
    cout << info[n_tam].identificador << " | ";
    cout << info[n_tam].nome << "|";
    cout << info[n_tam].estiloMusical << " | ";
    cout << info[n_tam].ano << "|";
    cout << info[n_tam].musicasFamosas << " | " << endl;

    cout << "==============" << endl;

    // SALVAR DADOS:
    string salvar;
    cout << "SALVAR ? (S/N)" << endl;
    cin >> salvar;
    if(salvar == "S"){
        ofstream arquivo("dados.csv", ios::app);
        if (arquivo.is_open()) {
            arquivo << endl 
                    << info[n_tam].identificador << ","
                    << info[n_tam].nome << ","
                    << info[n_tam].estiloMusical << ","
                    << info[n_tam].ano << ","
                    << info[n_tam].musicasFamosas << "\n";

            arquivo.close();
    }
    }

    MostrarMenu();
    
}

void RemoverDados(){

}

int main ()
{   
    
    ifstream arq("dados.csv");
    string linha;
    int tamanho = 0;

    //VER QUANTAS LINHAS HA NO ARQUIVO
    
    while(getline(arq, linha)){
        tamanho++;
    }

    arq.close();

    BandasDeRock* info = new BandasDeRock[tamanho];
    string identificador, nome, estiloMusical, ano, musicasFamosas;
    
    MostrarMenu();

    int escolha;
    cin >> escolha;
    while(escolha != 0){
        switch(escolha){
            case 1:
                MostrarDados(info, tamanho);
                break;
            case 2:
                MostrarIntervalo(info, tamanho);
                break;
            case 3:
                BuscarDados(info, tamanho);
                break;
            case 4:
                InserirDados(info, tamanho);
                break;
            case 5:
                RemoverDados(info, tamanho);
            default:
                cout << "Opção invalida!";
                break;
        }

        cout << "NOVA FUNÇÃO: " << endl;
        cin >> escolha;     
    }


    cout << "FINAL DO PROGRAMA!" << endl;

 
    return 0;
}