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
2 - Remover (OK)
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
        "=========================== MENU ==========================\n"
        "0 - SAIR\n"
        "1 - MOSTRAR DADOS\n"
        "2 - MOSTRAR INTERVALO\n"
        "3 - BUSCAR DADOS\n"
        "4 - INSERIR DADOS\n"
        "5 - REMOVER\n"
        "===========================================================\n";

    cout << menu;
    cout << endl;
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
    
    cout << "===========================================================" << endl;
    cout << "====================== MOSTRAR DADOS ======================" << endl;
    cout << endl;
    sleep(2);
    
    // Abrir arquivo
    ifstream arquivo("dados.txt");
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
        
        if (i < 9) {
            cout << 0 << i + 1 << "ª: ";
        } else {
            cout << i + 1 << "ª: " ;
        }
        
        cout << info[i].identificador << " | ";
        cout << info[i].nome << " | ";
        cout << info[i].estiloMusical << " | ";
        cout << info[i].ano << " | ";
        cout << info[i].musicasFamosas << " |" << endl;
        
        i++;
    }

    arquivo.close();
    
    cout << endl;
}

void MostrarIntervalo(BandasDeRock* info, int tamanho){
    int inicial, final;
    
    cout << "===========================================================" << endl;
    cout << "================ MOSTRAR INTERVALO DE DADOS ===============" << endl;
    cout << endl;
    sleep(1);
    
    cout << "Identificador inicial: ";
    cin >> inicial;
    cout << "Identificador final: ";
    cin >> final;
    cout << endl;

    inicial--;
    final--;

    string linha, identificador, nome, estiloMusical, ano, musicasFamosas;
    ifstream arquivo("dados.txt");
    int i = 0;
    while(getline(arquivo, linha) and i <= tamanho){

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
            
            if (i < 9) {
                cout << 0 << i + 1 << "ª: " ;
            } else {
                cout << i + 1 << "ª: " ;
            }
            
            cout << info[i].identificador << " | ";
            cout << info[i].nome << " | ";
            cout << info[i].estiloMusical << " | ";
            cout << info[i].ano << " | ";
            cout << info[i].musicasFamosas << " |" << endl;
        }

        i++;
    }

    arquivo.close();
    
    cout << endl;
}

void BuscarDados(BandasDeRock* info, int tamanho){
    string nome;
    int busca, opcao;
    
    short int encontrado = 0;
    opcao = 0;
    
    cout << "===========================================================" << endl;
    cout << "======================= BUSCAR DADOS ======================" << endl;
    cout << endl;
    sleep(1);
    
    cout << "Deseja buscar dados por (digite o número): " << endl;
    cout << "1 - Id" << endl;
    cout << "2 - Nome" << endl;
    cout << endl;
    
    while ((opcao != 1) && (opcao != 2)) {
        cout << "ESCOLHA: ";
        cin >> opcao;
        cout << endl;
        
        switch (opcao) {
            case 1:
                cout << "Busca por Id: ";
                cin >> busca;
                cout << endl;
                
                busca--;
            
                if (busca < tamanho){
                    cout << busca + 1 << "ª: ";
                    cout << info[busca].identificador << " | ";
                    cout << info[busca].nome << " | ";
                    cout << info[busca].estiloMusical << " | ";
                    cout << info[busca].ano << " | ";
                    cout << info[busca].musicasFamosas << " |" << endl;
                } else {
                    cout << "Valor inválido!" << endl;
                }
            
                cout << endl;
                
                break;
            
            case 2:
                cout << "Busca por Nome: ";
                cin.ignore();
                getline(cin, nome);

                for (int i = 0; i < tamanho; i++) {
                    
                    if (nome == info[i].nome) {
                        cout << endl;
                        cout << i + 1 << "ª: ";
                        cout << info[i].identificador << " | ";
                        cout << info[i].nome << " | ";
                        cout << info[i].estiloMusical << " | ";
                        cout << info[i].ano << " | ";
                        cout << info[i].musicasFamosas << " |" << endl;
                        
                        encontrado = 1;
                    }
                
                } if (encontrado == 0) {
                    cout << "Nome não econtrado" << endl;
                }
                
                break;
                
            default:
                cout << "Opção inválida" << endl;
                break;
        }
    }
    
    cout << endl;
}

void InserirDados(BandasDeRock*& info, int& tamanho){

    string nome, estiloMusical, ano, musicasFamosas;
    
    cout << "===========================================================" << endl;
    cout << "====================== INSERIR DADOS ======================" << endl;
    cout << endl;
    sleep(1);
    
    cout << "Nome da Banda: ";
    cin.ignore();
    getline(cin, nome);

    cout << "Estilo Musical: ";
    getline(cin, estiloMusical);

    cout << "Ano de criação: ";
    cin >> ano;

    cout << "Quantidade de Músicas Famosas: ";
    cin >> musicasFamosas;

    RedimensionarVetor(info, tamanho);
    int n_tam = tamanho - 1;

    info[n_tam].identificador = tamanho;
    info[n_tam].nome = nome;
    info[n_tam].estiloMusical = estiloMusical;
    info[n_tam].ano = stoi(ano);
    info[n_tam].musicasFamosas = stoi(musicasFamosas);

    cout << endl;
    cout << "Dados inseridos: " << endl;

    cout << info[n_tam].identificador << " | ";
    cout << info[n_tam].nome << " | ";
    cout << info[n_tam].estiloMusical << " | ";
    cout << info[n_tam].ano << " | ";
    cout << info[n_tam].musicasFamosas << " |" << endl;

    cout << endl;

    // SALVAR DADOS:
    string salvar;
    
    cout << "===========================================================" << endl;
    cout << "======================= SALVAR DADOS ======================" << endl;
    cout << endl;
    sleep(1);
    
    cout << "SALVAR (S/N)?" << endl;
    
    while((salvar != "S") && (salvar != "N")) { // tratamento de erro
        
        cin >> salvar;
        cout << endl;
        
        if(salvar == "S"){
            ofstream arquivo("dados.txt", ios::app);
            
            if(arquivo.is_open()) {
                arquivo << endl 
                        << info[n_tam].identificador << ","
                        << info[n_tam].nome << ","
                        << info[n_tam].estiloMusical << ","
                        << info[n_tam].ano << ","
                        << info[n_tam].musicasFamosas << "\n";

                arquivo.close();
                
                cout << "Alterações salvas!" << endl;
            }
        } else if(((salvar != "S") && (salvar != "N"))) {
            cout << "Opção inválida!" << endl;
            cin >> salvar;
        } else {
            cout << "Alterações não salvas!" << endl;
        }
    }
    
    cout << endl;
}

void CarregarDados(BandasDeRock* info, int tamanho){
    ifstream arquivo("dados.txt");

    string linha, identificador, nome, estiloMusical, ano, musicasFamosas;
    int i = 0;

    while(getline(arquivo, linha) && i < tamanho){

        stringstream sep(linha);

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

        i++;
    }

    arquivo.close();
}

void RemoverDados(BandasDeRock*& info, int& tamanho){
    CarregarDados(info, tamanho);
    
    int remover;

    cout << "===========================================================" << endl;
    cout << "====================== REMOVER DADOS ======================" << endl;
    cout << endl;
    sleep(1);
    
    cout << "Informe o ID que deseja remover: ";
    cin >> remover;
    cout << endl;

    remover--; // ajustar para índice do vetor

    if((remover < 0) || (remover >= tamanho)){
        cout << "ID inválido!" << endl;
        cout << endl;
        
        return;
    }

    // Criar novo vetor com tamanho - 1
    int NovoTamanho = tamanho - 1;
    BandasDeRock* New_info = new BandasDeRock[NovoTamanho];

    int j = 0;
    for(int i = 0; i < tamanho; i++){
        if(i != remover){
            New_info[j] = info[i];
            New_info[j].identificador = j + 1; // reajustar IDs
            j++;
        }
    }

    delete[] info;
    info = New_info;
    tamanho = NovoTamanho;

    // Reescrever arquivo inteiro
    ofstream arquivo("dados.txt");
    if(arquivo.is_open()){
        for(int i = 0; i < tamanho; i++){
            arquivo << info[i].identificador << ","
                    << info[i].nome << ","
                    << info[i].estiloMusical << ","
                    << info[i].ano << ","
                    << info[i].musicasFamosas;

            if(i < tamanho - 1)
                arquivo << "\n";
        }
        arquivo.close();
    }

    cout << "Registro removido com sucesso!" << endl;

    cout << endl;
}


int main () {
    cout << endl;
    cout << "                        Seja Bem-Vindo(a)" << endl;
    sleep(1);
    cout << "                    ao Sistema de Arquivo de" << endl;
    sleep(1);
    cout << "                         Bandas de Rock" << endl;
    sleep(1);
    cout << endl;
    cout << "Feito por: Anamaya, Anny e Lucas." << endl;
    sleep(3);
    cout << endl;
    cout << "Digite o número da opção para o que deseja fazer:" << endl;
    sleep(2);
    
    ifstream arq("dados.txt");
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
    cout << "OPÇÃO: ";
    cin >> escolha;
    cout << endl;
    
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
                MostrarDados(info, tamanho);
                RemoverDados(info, tamanho);
                break;
            default:
                cout << "Opção invalida!";
                break;
        }
        
        sleep(1);
        MostrarMenu();
        cout << "NOVA FUNÇÃO: ";
        cin >> escolha;
        cout << endl;
        
        system("clear");
    }

    cout << endl;
    cout << "                       FINAL DO PROGRAMA!" << endl;
    cout << endl;

    return 0;
}
