#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
struct comentario{
	int idComentario;
    string produc;
    string user;
    string comment;
    string fecha;
};

int main() {
	system("chcp 65001 >nul"); // For Windows console UTF-8
    setlocale(LC_ALL, "");
    ifstream file("comentarios.txt");
    string line;
    vector<comentario> comentarios;
    while(getline(file, line)){
    	comentarios.emplace_back();
    	
		int begin = 0;
    	int pos = line.find(',', begin);
    	comentarios.back().idComentario=(stoi(line.substr(begin, pos-begin)));
    	
    	begin=pos+1;
    	pos = line.find(',', begin);
    	comentarios.back().produc=(line.substr(begin, pos-begin));
    	
    	begin=pos+1;
    	pos = line.find(',', begin);
    	comentarios.back().user=(line.substr(begin, pos-begin));
    	
    	begin=pos+1;
    	pos = line.find(',', begin);
    	comentarios.back().comment=(line.substr(begin, pos-begin));
    	
    	begin=pos+1;
    	comentarios.back().fecha=(line.substr(begin));
		}
    file.close();
    
     for (const auto& c : comentarios) {
        cout << "ID: " << c.idComentario
             << " | Producto: " << c.produc
             << " | Usuario: " << c.user
             << " | Comentario: " << c.comment
             << " | Fecha: " << c.fecha << endl;
    }
}

