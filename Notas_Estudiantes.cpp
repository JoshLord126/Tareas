#include<iostream>


using namespace std;
struct Estudiante{
	int *codigo;
	string *nombre;
	int **pm_notas;
};

int notas(){
int fila_estudiante=0,columna_notas=0;
Estudiante estudiante;
cout<<"Cuantos Estudiantes Desea Ingresar: ";
cin>>fila_estudiante;	
cout<<"Cuantas Notas Desea Ingresar: ";
cin>>columna_notas;	
estudiante.pm_notas = new  int *[fila_estudiante];
estudiante.codigo = new int[fila_estudiante];
estudiante.nombre = new string[fila_estudiante];
for (int i=0;i<fila_estudiante;i++){
estudiante.pm_notas[i] = new int[columna_notas]; 	
}
cout<<"--------------Ingrese Notas--------------"<<endl;
string nombre;
for (int i=0;i<fila_estudiante;i++){
	cout<<"Codigo: ";
	cin>>estudiante.codigo[i];
	cin.ignore();
	cout<<"Nombre:";
	getline(cin,estudiante.nombre[i]);
	//strcpy(estudiante.nombre, nombre.c_str()); 
for (int ii=0;ii<columna_notas;ii++){
	
	
    
	cout<<"Ingrese Nota "<<ii + 1<<": ";
	cin>>*(*(estudiante.pm_notas+i)+ii);
	}
	cout<<"------------------------------------"<<endl;
}
	cout<<"--------------Mostrar Notas--------------"<<endl;
for (int i=0;i<fila_estudiante;i++){
	cout<<"Codigo: "<<estudiante.codigo[i]<<" Estudiante:"<<estudiante.nombre[i]<<"."<<endl;
for (int ii=0;ii<columna_notas;ii++){
	cout<<"Nota ["<<ii + 1 <<"]: "
	<<*(*(estudiante.pm_notas+i)+ii);
	cout<<endl;

	}
		cout<<"------------------------------------"<<endl;
}
// Liberar el espacio reservado en memoria
for (int i=0;i<fila_estudiante;i++){
	delete [] estudiante.pm_notas[i];
}

delete [] estudiante.pm_notas;
delete[] estudiante.codigo;
delete[] estudiante.nombre;

	system("PAUSE");
	return 0;
	
}

int main(){
	notas();
}
