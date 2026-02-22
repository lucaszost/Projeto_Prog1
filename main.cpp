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
6 - Salvar (ok)
0 - Sair (ok)


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

void MostrarMenu(){
    string menu = "########################## MENU ##########################\n0 - INSERIR\n1 - REMOVER\n2 - BUSCAR\n3 - MOSTRAR DADOS\n4 - MOSTRAR INVERVALO\n5 - SALVAR\n-1 - SAIR \n##########################################################\n";
    cout << menu << endl;
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


void InserirDados(BandasDeRock*& info, int& tamanho){
    string nome, estiloMusical, ano, musicasFamosas;

    // INSERIR DADOS
    cout << "Inserir dados: " << endl;
    string inserir;
    cin >> inserir;
    while (inserir == "S"){
        RedimensionarVetor(info, tamanho);
        
        cout << "Nome | Estilo Musical | Ano | musicas Famosas" << endl;
        cin >> nome >> estiloMusical >> ano >> musicasFamosas;

        info[tamanho - 1].identificador = tamanho;
        info[tamanho - 1].nome = nome;
        info[tamanho - 1].estiloMusical = estiloMusical;
        info[tamanho - 1].ano = stoi(ano);
        info[tamanho - 1].musicasFamosas = stoi(musicasFamosas);
        
        cout << info[tamanho - 1].identificador << " | ";
        cout << info[tamanho - 1].nome << "|";
        cout << info[tamanho - 1].estiloMusical << " | ";
        cout << info[tamanho - 1].ano << "|";
        cout << info[tamanho - 1].musicasFamosas << " | " << endl;
        
        cout << "Continuar inserindo dados? ";
        cin >> inserir;
    }

    // SALVAR TODOS OS DADOS NO ARQUIVO
    ofstream arquivo1("dados.csv");
    for (int j = 0; j < tamanho; j++){
        arquivo1 << info[j].identificador << ',' << info[j].nome << ',' << info[j].estiloMusical << ',' << info[j].ano << ',' << info[j].musicasFamosas << endl;
    }
    arquivo1.close();
    cout << "Dados salvos com sucesso!";
    

    MostrarMenu();
}

void MostrarDados(BandasDeRock* info, int tamanho){

    string linha, identificador, nome, estiloMusical, ano, musicasFamosas;
    
    // Abrir arquivo
    ifstream arquivo("dados.csv");

    // LER TODO O ARQUIVO (ate a posição 59)
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


int Sair(int escolha){
    return -1;
}

void SalvarDados(BandasDeRock*& info, int tamanho){
    


}

void MostrarIntervalo(BandasDeRock*& info, int tamanho){
    // MOSTRAR INTERVALO

    int inicial, final;
    cout << "Valor Inicial e final: " << endl;

    cin >> inicial >> final;

    for (int k = inicial -1; k < final; k++){
        cout << info[k].identificador << ',' << info[k].nome << ',' << info[k].estiloMusical << ',' << info[k].ano << ',' << info[k].musicasFamosas << endl;

    }
    MostrarMenu();

}

void BuscarDados(BandasDeRock*& info){
    // BUSCAR INFORMAÇÕES 
    cout << "Busca por id: " << endl;
    int busca;
    cin >> busca;
    for (int i = 0; i < busca; i++){
        if (info[i].identificador == busca){
            cout << info[i].identificador << ',' << info[i].nome << ',' << info[i].estiloMusical << ',' << info[i].ano << ',' << info[i].musicasFamosas << endl;
        }
    }
    MostrarMenu();
}

void RemoverDados(BandasDeRock*& info){

    // REMOVER DADOS
    int remover;
    string conRemover;
    cout << "Remover dados: " << endl;
    cin >> conRemover;
    
    /*
    if (conRemover == "S"){
        cin >> remover;
        ofstream arquivo2("dados.csv");
        /*
        for (int j = 0; j < tamanho; j++){
            if (remover != j+1 ){
                arquivo2 << info[j].identificador << ',' << info[j].nome << ',' << info[j].estiloMusical << ',' << info[j].ano << ',' << info[j].musicasFamosas << endl;
            }else{
                arquivo2 << info[-j].identificador << ',' << info[-j].nome << ',' << info[-j].estiloMusical << ',' << info[-j].ano << ',' << info[-j].musicasFamosas << endl;
            }
        }

       


        for (int p = 0; p < tamanho; p++){
            if (p+1 < remover ){
                arquivo2 << info[p].identificador << ',' << info[p].nome << ',' << info[p].estiloMusical << ',' << info[p].ano << ',' << info[p].musicasFamosas << endl;
            }else{
                arquivo2 << info[p-1].identificador << ',' << info[p-1].nome << ',' << info[p-1].estiloMusical << ',' << info[p-1].ano << ',' << info[p-1].musicasFamosas << endl;
            }
        }

        arquivo2.close();  
    }
    
    */

}


int main ()
{   

    //DECLARANDO VARIAVEIS

    int tamanho = 60;
    BandasDeRock* info = new BandasDeRock[tamanho];
    string linha, dado;
    string identificador, nome, estiloMusical, ano, musicasFamosas;


    //MOSTRA A TELA INICIAL
    cout << endl;
    cout << "                   Seja Bem-Vindo(a) ao" << endl;
    cout << "            Sistema de arquivo de bandas de Rock" << endl;
    cout << "                  de Anamaya, Anny e Lucas" << endl;
    sleep(3);
    cout << " " << endl;
    cout << "Digite que a��o deseja tomar segundo o menu:" << endl;
    cout << " " << endl;
    sleep(2);
    MostrarMenu();
    sleep(1);

    int escolha;
    cin >> escolha;
    while(escolha != -1){
        switch (escolha){
            case 0: 
                InserirDados(info, tamanho);
                break;
            case 1: 
                RemoverDados(info);
                break;
            case 2: 
                BuscarDados(info);
                break;
            case 3: 
                MostrarDados(info, tamanho);
                break;
            case 4: 
                MostrarIntervalo(info, tamanho);
                break;
            case 5:    
                SalvarDados(info, tamanho);
                break;
            case -1:
                Sair(escolha);
                break;
            default:
                cout << "Algo de errado não parece certo ! " << endl;
                break;
        }

        cin >> escolha;     
    }


 
    return 0;
}