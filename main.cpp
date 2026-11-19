#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>

using namespace std;

class No
{
private:
    string id;

public:
    No(string id) : id(id) {}
    ~No() {}

    string getId() { return id; }

    void setId(string id) { this->id = id; }
};

class Aresta
{
private:
    string origin;
    string destination;

public:
    Aresta(string origin, string destination) : origin(origin), destination(destination) {}
    ~Aresta() {}

    string getOrigin() { return origin; }
    string getDestination() { return destination; }
    void setOrigin(string no) { origin = no; }
    void setDestination(string no) { destination = no; }
};

class Graph
{
private:
    vector<No *> nos;
    vector<Aresta *> arestas;

public:
    // ============================
    //  Construtor e Destrutor
    // ============================
    Graph() {}
    ~Graph();

    //  Getters
    // =========
    vector<No *> getNos() { return nos; }
    vector<Aresta *> getEdges() { return arestas; }

    //  Setters
    // =========
    void addNo(No no) { nos.push_back(new No(no)); }
    void addEdge(Aresta aresta) { arestas.push_back(new Aresta(aresta)); }
};


class Dados
{
private:
    string linha;
    ifstream arquivo;

public:

    bool AbrirArquivo(string doc) 
    {
        // Abre o arquivo CSV
        this->arquivo.open(doc);
        
        // Verifica se o arquivo foi aberto com sucesso
        if (!arquivo.is_open()) {
            cout << "Erro ao abrir o arquivo!" << endl;
            return false;
        }

        return true;
    }

    void LeArquivo(){
        string primeira_linha, num1 = "", num2 = "";
        getline(arquivo, primeira_linha);
        int tam = primeira_linha.length();
        bool alt = true;
        for(int i = 0; i<tam; i++){
            if(primeira_linha[i] != ' ' && alt){
                num1 += primeira_linha[i];
            } else {
                alt = false;
            }
            if(!alt){
                num2 += primeira_linha[i];
            }
        }
        
        int nos = stoi(num1);
        int arestas = stoi(num2);

        
    }

    void FechaArquivo(){
        // Fecha o arquivo
        this->arquivo.close();
    }

};

int main(){
    Dados meu_arquivo;
    // meu_arquivo.AbrirArquivo("/home/arthur/Documentos/UFJF/Grafos/Aula_15_09/dados.csv");
    // meu_arquivo.LeArquivo();
    // meu_arquivo.FechaArquivo();

    return 0;
}