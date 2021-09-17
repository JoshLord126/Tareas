#include <iostream>

using namespace std;

int a, b=0, c = 0, i = 0, d = 0, num = 100;
float tot1=0, tot2=0;

struct Forzado{
	string busc, valorpato;
};



float *sueldo = new float[num], *boni = new float[num];
string *cod = new string [num], *nom = new string [num], *ape = new string [num], *pue = new string [num];


class Examen{
	Forzado forc;
	public:
	void ingreso_datos() {
		char fin = 'n';
		do{
			cout<<"------------ INGRESO DE DATOS -------------"<<endl<<endl;
			cout<<"<-------------- Empleado #"<<i+1<<" -------------->"<<endl;
			
			cin.ignore();
			cout<<"Ingresa el codigo: ";
			cin>>forc.valorpato;
			
			do{
				d=0;
				b = 0;
				for(int jj=0;jj<=i;jj++){
					if(forc.valorpato==cod[jj]){
						d++;
					}
				}
				if(d>0){
					cout<<"Codigo ya en uso; Ingrese uno nuevo: ";
					cin>>forc.valorpato;
				}else{
					b = 1;
				}
			}while(b==0);
			cod[i] = forc.valorpato;
			cin.ignore();
			
			cout<<"Ingresa el nombres: ";
			getline(cin,nom[i]);
			cout<<"Ingresa el apellidos: ";
			getline(cin,ape[i]);
			cout<<"Ingresa el puesto: ";
			getline(cin,pue[i]);
			cout<<"Ingresa el sueldo base: ";
			cin>>sueldo[i];
			cout<<"Ingresa la bonificacion: ";
			cin>>boni[i];
			
			i++;

			cout<<"\n\nDeseas ingresar info. de otro empleado? (S/N): ";
			cin>>fin;
			system("cls");
		}while(fin=='s' || fin=='S');
    }
    
    void mostrar(int resumen, int dinero, int numero){
    	tot1 = 0;
    	tot2 = 0;
    	//empleado emp;
    	if(resumen==1){
    		cout<<"<----------- Lista de Empleados ---------->"<<endl;
			for(int ii=0;ii<i;ii++){
				cout<<"["<<cod[ii]<<"]"<<" "<<ape[ii]<<", "<<nom[ii];
				if(dinero>=1){
					cout<<" --> "<<sueldo[ii];
					tot1 += sueldo[ii];
				}
				
				if(dinero>=2){
					cout<<" + "<<boni[ii]<<" = "<<sueldo[ii]+boni[ii];
					tot2 += sueldo[ii]+boni[ii];
				}
				
				cout<<endl;
			}
		}
		
		if(numero>=0){
			cout<<"<------------- Empleado Actual ----------->"<<endl;
			cout<<"\nCodigo: "<<cod[numero]<<"\nApellidos: "<<ape[numero]<<"\nNombres: "<<nom[numero]<<"\nPuesto: "<<pue[numero]<<"\nSueldo: "<<sueldo[numero]<<"\nBonificacion: "<<boni[numero]<<endl<<endl;
		}	
	}
	
	void buscar(){
		//empleado emp;
		
		cout<<"Ingrese el Codigo a buscar: ";
		cin.ignore();
		getline(cin,forc.busc);
		
		for(int ii=0;ii<=i;ii++){
			if(forc.busc==cod[ii]){
				a = ii+1;
				Examen::mostrar(0,0,ii);
				forc.busc = "OK";
			}
		}
		
		if(forc.busc!="OK"){
			cout<<"No se encuentra el item buscado"<<endl<<endl;
		}
		
		
	}
	
	void remplazar(){
		//empleado emp;
		Examen prueba;
		a = 111;
		prueba.buscar();
		a--;
		if(a!=111){
			
			for(int ii=0;ii<=i;ii++){
				if(a==ii){
					cout<<"\n\n<------------ Valor a Modificar ---------->"<<endl;
					cout<<"Nombres ................................. 1"<<endl;
					cout<<"Apellidos ............................... 2"<<endl;
					cout<<"Puesto .................................. 3"<<endl;
					cout<<"Sueldo .................................. 4"<<endl;
					cout<<"Bonificacion ............................ 5"<<endl<<endl<<endl;
					cout<<"Ingrese el valor a modificar: ";
					cin>>b;
					cin.ignore();
					switch(b){
						case 1:
							cout<<"Ingrese el nuevo nombre: ";
							getline(cin,nom[ii]);
						break;
						case 2:
							cout<<"Ingrese el nuevo apellido: ";
							getline(cin,ape[ii]);
						break;
						case 3:
							cout<<"Ingrese el nuevo puesto: ";
							getline(cin,pue[ii]);
						break;
						case 4:
							cout<<"Ingrese el nuevo sueldo: ";
							cin>>sueldo[ii];
						break;
						case 5:
							cout<<"Ingrese la nueva bonificacion: ";
							cin>>boni[ii];
						break;	
					}
					Examen::mostrar(0,0,ii);
				}
			}
		}
	}
	
	
	void sueldos(){
		cout<<"<---------- Costo total de Sueldos ------->"<<endl;
		Examen::mostrar(1,1,-1);
		cout<<"TOTAL Q. "<<tot1<<endl<<endl;
		cout<<"<--- Costo total de Sueldo+Bonificacion -->"<<endl;
		Examen::mostrar(1,2,-1);
		cout<<"TOTAL Q. "<<tot2<<endl<<endl;
		
		cout<<"\n\n\n";
		system("pause");
		
	}
};



int main(){
	Examen exam;
	int opcion;
	do{
		cout<<"---------------- EMPLEADOS ----------------"<<endl<<endl;
		cout<<"Ingreso de datos ........................ 1"<<endl;
		cout<<"Mostrar datos ........................... 2"<<endl;
		cout<<"Remplazar datos ......................... 3"<<endl;
		cout<<"Buscar datos ............................ 4"<<endl;
		cout<<"Ver sueldos ............................. 5"<<endl<<endl<<endl;

		cout<<"Ingresa la opcion: ";
		cin>>opcion;
		system("cls");
		switch (opcion){
			case 1:
				exam.ingreso_datos();
			break;
			case 2:
				cout<<"-------------- MOSTRAR DATOS --------------"<<endl<<endl;
				exam.mostrar(1,0,-1);
				cout<<"\n\n\n";
				system("pause");
			break;
			case 3:
				cout<<"------------- REMPLAZAR DATOS -------------"<<endl<<endl;
				exam.remplazar();
				cout<<"\n\n\n";
				system("pause");
			break;
			case 4:
				cout<<"--------------- BUSCAR DATOS --------------"<<endl<<endl;
				exam.buscar();
				cout<<"\n\n\n";
				system("pause");
			break;	
			case 5:
				cout<<"--------------- VER SUELDOS ---------------"<<endl<<endl;
				exam.sueldos();
			break;
		}
		system("cls");
	}while(c==0);
}

