#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<clocale>
#include<stdlib.h>
#include<math.h>
#include<cmath>
#include<iomanip>

using namespace std;

void portadaGeneral()
{
cout<<"\n\t\t\t   M?todos N?mericos\n";
	cout<<"\nPrograma Para Calcular La Raiz De Una Funcion Mediante Dos Metodos Diferentes\n\tY Para Calcular El Determinante De Una Matriz Cuadrada\n";
	cout<<"\n\t\t\tIntegrantes Del Equipo:\n";
	cout<<"\n\t\t       Bermeo Barr?n Abril Itzel \n\t\t   Dur?n Zamarripa Brenda Elizabeth \n\t\t        Fuentes Flores Mauricio\n\t\t    Gutierrez Segura Jhonatan Lemuel\n\n\n";
	system("pause"); 
}

void portadaSistemas()
{
	cout<<"\n\t\tObtener Determinante De Una Matriz\n";
	cout<<"\n A continuaci?n deber?s ingresar una matriz cuadrada y el\n programa obtendr? su determinante y la soluci?n del sistema.\n\n ";
	system("pause"); 
}

void portadaEcuacion()
{
	cout<<"\n----------Soluci?n de una ecuaciones----------\n";
	cout<<"\n A continuaci?n deber?s seleccionar una ecuaci?n y un m?todo de soluci?n.";
	system("pause"); 
}


int menuGeneral(){
	int op;
	
	cout<<"\t\tMen?\n";
	cout<<"\n 1.- Soluci?n de una ecuaci?n.";
	cout<<"\n 2.- Obtener Determinante De Una Matriz.";
	cout<<"\n 3.- Calcular Eigenvalores.";
	cout<<"\n\n Elija una opci?n (1/3): ";
	cin>>op;
	
	while(op!=1 && op!=2 && op!=3){
		cout<<" **VALOR INVALIDO**\n\n Solo ingrese 1 o 2: ";
		cin>>op;
	}
	
	return op;
}

int menuMetodo(){
	int op;
	
	cout<<"	--Men? de m?todos--\n";
	
	cout<<"\n 1.- M?todo de Biseccion.";
	cout<<"\n 2.- M?todo de Newton.";
	
	cout<<"\n\n Elija un m?todo (1/2): ";
	cin>>op;
	
	while(op!=1 && op!=2){
		cout<<" **VALOR INVALIDO**\n\n Solo ingrese 1 o 2: ";
		cin>>op;
	}
	
	return op;
}

int menuFuncion(){
	int op;
	
	cout<<"\n	--Men? de funciones--\n";
	
	cout<<"\n 1.- f(x) = x^2 cosx - 2x";
	cout<<"\n 2.- f(x) = (6 - 2/x^2) (e^(2+x))/4  + 1";
	cout<<"\n 3.- f(x) = x^3 - 3senx^2  + 1";
	cout<<"\n 4.- f(x) = x^3 + 6x^2 + 9.4x + 2.5";
	
	cout<<"\n\n Elija una funci?n (1/2): ";
	cin>>op;
	
	while(op!=1 && op!=2 && op!=3 && op!=4){
		cout<<" **VALOR INVALIDO**\n\n Solo ingrese 1 o 2: ";
		cin>>op;
	}

	return op;
}

double f(double x, int op)
{
	switch(op)
	{
		case 1:
			return pow(x, 2) * cos(x) - 2*x;
			break;
		case 2:
			return (6-(2/pow(x, 2)))*(exp(2+x)/4)+1;
			break;
		case 3:
			return pow(x, 3) - 3*pow(sin(x), 2) + 1;
			break;
		case 4:
			return pow(x, 3) + 6*pow(x, 2) + 9.4*x + 2.5;
			break;
	}
}

double df(double x, int op)
{
	switch(op)
	{
		case 1:
			return 2*x*cos(x)-(pow(x,2)*sin(x))-2;
			break;
		case 2:
			return ((3*pow(x,3) - x + 2)*exp(x+2))/(2*pow(x,3));
			break;
		case 3:
			return 3*pow(x,2)-6*cos(x)*sin(x);
			break;
		case 4:
			return 3*(pow(x,2))+12*x+9.4;
			break;
	}
}


void metodoNewton(int op, double x0, int maxIt, int tolE, double tol, int iteracion){
	double xa=0, fx0=0, derivfx0=0, x2, ea=0, er=0, erp=0;
	int i=0;
	bool encontrada=false;
	
	cout<<" M?todo: Newton \t\t";         
	switch(op){
		case 1:
			cout<<"Funci?n: f(x) = x^2 cosx - 2x\n";
			cout<<"\n x0: "<<x0<<"\t\tTolerancia: "<<fixed<<setprecision(10)<<tol<<"\tM?ximo de iteraciones: "<<maxIt<<endl<<endl;
			
			cout<<" i |x_0 \t\t|f(x_0) \t|f'(x_0) \t|Ea \t\t|Er \t\t|Erp\n";
			
			for(i=0; i<=maxIt; i++){
				fx0 = f(x0, op);
				derivfx0 = df(x0, op);
				x2 = x0 - (fx0/derivfx0);
				
				if(i>0){
					ea = fabs(x0-xa);
					er = ea/(fabs(x0));
					erp = er*100.00;
					
					iteracion=i;
					
					if(tolE==1 && i>0){
						if(ea<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else if(tolE==2){
						if(er<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else{
						if(erp<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
				}
				
				if(i==0){
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t| \t\t| \t\t|\n", i, x0, fx0, derivfx0);					
				}
				else if(i>0 && derivfx0!=0){
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \n", iteracion, x0, fx0, derivfx0, ea, er, erp);
				}
				else if(derivfx0==0){
					i=maxIt;
				}		
				xa = x0;
				x0 = x2;
			}
		break;
		
		case 2:
			cout<<"Funci?n: f(x) = (6 - 2/x^2) (e^(2+x))/4  + 1\n";
			cout<<"\n x0: "<<x0<<"\t\tTolerancia: "<<fixed<<setprecision(10)<<tol<<"\tM?ximo de iteraciones: "<<maxIt<<endl<<endl;
			
			cout<<" i |x_0 \t\t|f(x_0) \t|f'(x_0) \t|Ea \t\t|Er \t\t|Erp\n";
			
			for(i=0; i<=maxIt; i++){
				fx0 = f(x0, op);
				derivfx0 = df(x0, op);
				x2 = x0 - (fx0/derivfx0);
				
				if(i>0){
					ea = fabs(x0-xa);
					er = ea/(fabs(x0));
					erp = er*100.00;
					
					iteracion=i;
					
					if(tolE==1 && i>0){
						if(ea<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else if(tolE==2){
						if(er<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else{
						if(erp<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
				}
				
				if(i==0){
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t| \t\t| \t\t|\n", i, x0, fx0, derivfx0);					
				}
				else if(i>0 && derivfx0!=0){
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \n", iteracion, x0, fx0, derivfx0, ea, er, erp);
				}
				else{
					i=maxIt;
				}
				xa = x0;
				x0 = x2;
			}
		break;
		
		case 3:
			cout<<"Funci?n: f(x) = x^3 - 3senx^2  + 1\n";
			cout<<"\n x0: "<<x0<<"\t\tTolerancia: "<<fixed<<setprecision(10)<<tol<<"\tM?ximo de iteraciones: "<<maxIt<<endl<<endl;
			
			cout<<" i |x_0 \t\t|f(x_0) \t|f'(x_0) \t|Ea \t\t|Er \t\t|Erp\n";
			
			for(i=0; i<=maxIt; i++){
				fx0 = f(x0, op);
				derivfx0 = df(x0, op);
				x2 = x0 - (fx0/derivfx0);
				
				if(i>0){
					ea = fabs(x0-xa);
					er = ea/(fabs(x0));
					erp = er*100.00;
					
					iteracion=i;
					
					if(tolE==1 && i>0){
						if(ea<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else if(tolE==2){
						if(er<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else{
						if(erp<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
				}
				
				if(i==0){
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t| \t\t| \t\t|\n", i, x0, fx0, derivfx0);					
				}
				else if(i>0 && derivfx0!=0){
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \n", iteracion, x0, fx0, derivfx0, ea, er, erp);
				}
				else{
					i=maxIt;
				}
				xa = x0;
				x0 = x2;
			}
		break;
		
		case 4:
			cout<<"f(x) = x^3 + 6x^2 + 9.4x + 2.5\n";
			cout<<"\n x0: "<<x0<<"\t\tTolerancia: "<<fixed<<setprecision(10)<<tol<<"\tM?ximo de iteraciones: "<<maxIt<<endl<<endl;
			
			cout<<" i |x_0 \t\t|f(x_0) \t|f'(x_0) \t|Ea \t\t|Er \t\t|Erp\n";
			
			for(i=0; i<=maxIt; i++){
				fx0 = f(x0, op);
				derivfx0 = df(x0, op);
				x2 = x0 - (fx0/derivfx0);
				
				if(i>0){
					ea = fabs(x0-xa);
					er = ea/(fabs(x0));
					erp = er*100.00;
					
					iteracion=i;
					
					if(tolE==1 && i>0){
						if(ea<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else if(tolE==2){
						if(er<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else{
						if(erp<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
				}
				
				if(i==0){
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t| \t\t| \t\t|\n", i, x0, fx0, derivfx0);					
				}
				else if(i>0 && derivfx0!=0){
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \n", iteracion, x0, fx0, derivfx0, ea, er, erp);
				}
				else{
					i=maxIt;
				}
				xa = x0;
				x0 = x2;
			}
		break;	
	}
	if(encontrada==true){
		cout<<"\n La ra?z obtenida es "<<x2<<", en la iteraci?n "<<iteracion<<", con una toleracia de ";
				
		if(tolE==1){
			cout<<fixed<<setprecision(10)<<ea<<" <= "<<tol<<" en el error absoluto.\n";
		}
		else if(tolE==2){
			cout<<fixed<<setprecision(10)<<er<<" <= "<<tol<<" en el error relativo.\n";
		}
		else{
			cout<<fixed<<setprecision(10)<<erp<<" <= "<<tol<<" en el error relativo porcentual.\n";
		}
	}
	else if(iteracion==maxIt && encontrada==false){
		cout<<"\n Despu?s de "<<maxIt<<" iteraciones como m?ximo, la ra?z con tolerancia de "<<tol;
		
		if(tolE==1){
			cout<<" en el error absoluto, no ha sido encontrada con el valor ingresado.\n";
		}
		else if(tolE==2){
			cout<<" en el error relativo, no ha sido encontrada con el valor ingresado.\n";
		}
		else{
			cout<<" en el error relarivo porcentual, no ha sido encontrada con el valor ingresado.\n";
		}
	}
	else if(derivfx0==0){
		cout<<"\n Despu?s de "<<iteracion<<" iteraciones, la derivada de f(x_0) se indetermina y no se puede hallar la ra?z con este valor inicial.";
	}
}
				

void posicionFalsa(int op, double x0, double x1, int maxIt, int tolE, double tol, int iteracion){
	double x2=0, xa=0, fx0=0, fx1=0, fx2=0, ea=0, er=0, erp=0;
	int i=0;
	bool encontrada=false;
	
	cout<<" M?todo: Posici?n falsa \t";
	
	switch(op){
		case 1:
			cout<<"Funci?n: f(x) = x^2 cosx - 2x\n";
			
			cout<<"\n x0: "<<x0<<"\t\tx1: "<<x1<<"\t\tTolerancia: "<<fixed<<setprecision(10)<<tol<<"\tM?ximo de iteraciones: "<<maxIt<<endl<<endl;
			
			cout<<" i |x_0 \t\t|x_1 \t\t|f(x_0) \t|f(x_1) \t|x_2 \t\t|f(x_2) \t|Ea \t\t|Er \t\t|Erp\n";
			
			for(i=0; i<=maxIt; i++){
				fx0 = (pow(x0, 2)*cos(x0)) - (2*x0);
				fx1 = (pow(x1, 2)*cos(x1)) - (2*x1);
				x2 = x1-fx1*((x0-x1)/(fx0-fx1));
				fx2 = (pow(x2, 2)*cos(x2)) - (2*x2);
				
				if(i>0){
					ea = fabs(x2-xa);
					er = ea/(fabs(x2));
					erp = er*100.00;
					
					iteracion=i;
					
					if(tolE==1 && i>0){
						if(ea<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else if(tolE==2){
						if(er<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else{
						if(erp<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
				}
				
				if(i==0){
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t| \t\t| \t\t|\n", i, x0, x1, fx0, fx1, x2, fx2);					
				}
				else{
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \n", iteracion, x0, x1, fx0, fx1, x2, fx2, ea, er, erp);
				}
				
				xa = x2;
				
				if((fx2*fx0)>=0){
					x0 = x2;
				}
				else{
					x1 = x2;
				}
			}
		break; 
		
		case 2:
			cout<<"Funci?n: f(x) = (6 - 2/x^2) (e^(2+x))/4  + 1\n\n";
			
			cout<<"\n x0: "<<x0<<"\t\tx1: "<<x1<<"\t\tTolerancia: "<<fixed<<setprecision(10)<<tol<<"\tM?ximo de iteraciones: "<<maxIt<<endl<<endl; //se muestran valores ingresados
			
			cout<<" i |x_0 \t\t|x_1 \t\t|f(x_0) \t|f(x_1) \t|x_2 \t\t|f(x_2) \t|Ea \t\t|Er \t\t|Erp\n";
			
			for(i=0; i<=maxIt; i++){
				fx0 = (6-(2/pow(x0, 2)))*(exp(2+x0)/4)+1;
				fx1 = (6-(2/pow(x1, 2)))*(exp(2+x1)/4)+1;;
				x2 = x1-fx1*((x0-x1)/(fx0-fx1));
				fx2 = (6-(2/pow(x2, 2)))*(exp(2+x2)/4)+1;;
					
				if(i>0){
					ea = fabs(x2-xa);
					er = ea/(fabs(x2));
					erp = er*100;
						
					iteracion=i;
						
					if(tolE==1 && i>0){
						if(ea<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else if(tolE==2){
						if(er<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else{
						if(erp<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
				}
					
				if(i==0){
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t| \t\t| \t\t|\n", i, x0, x1, fx0, fx1, x2, fx2);					
				}
				else{
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \n", iteracion, x0, x1, fx0, fx1, x2, fx2, ea, er, erp);
				}
					
				xa = x2; 
					
				if((fx2*fx0)>=0){ 
					x0 = x2;
				}
				else{
					x1 = x2;
				}
			}
			
		break;
		
		case 3:
			cout<<"Funci?n: f(x) = x^3 - 3senx^2  + 1\n\n";
			
			cout<<"\n x0: "<<x0<<"\t\tx1: "<<x1<<"\t\tTolerancia: "<<fixed<<setprecision(10)<<tol<<"\tM?ximo de iteraciones: "<<maxIt<<endl<<endl;
			
			cout<<" i |x_0 \t\t|x_1 \t\t|f(x_0) \t|f(x_1) \t|x_2 \t\t|f(x_2) \t|Ea \t\t|Er \t\t|Erp\n";
			
			for(i=0; i<maxIt; i++){
				fx0 = pow(x0, 3) - 3*pow(sin(x0), 2) + 1;
				fx1 = pow(x1, 3) - 3*pow(sin(x1), 2) + 1;
				x2 = x1-fx1*((x0-x1)/(fx0-fx1));
				fx2 = pow(x2, 3) - 3*pow(sin(x2), 2) + 1;
				
				if(i>0){
					ea = fabs(x2-xa);
					er = ea/(fabs(x2));
					erp = er*100;
					
					iteracion=i;
					
					if(tolE==1 && i>0){
						if(ea<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else if(tolE==2){
						if(er<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else{
						if(erp<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
				}
				
				if(i==0){
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t| \t\t| \t\t|\n", i, x0, x1, fx0, fx1, x2, fx2);					
				}
				else{
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \n", iteracion, x0, x1, fx0, fx1, x2, fx2, ea, er, erp);
				}
				
				xa = x2;
				
				if((fx2*fx0)>=0){
					x0 = x2;
				}
				else{
					x1 = x2;
				}
			}
		break;
		
		case 4:
			cout<<"Funci?n: f(x) = x^3 + 6x^2 + 9.4x + 2.5\n\n";
			
			cout<<"\n x0: "<<x0<<"\t\tx1: "<<x1<<"\t\tTolerancia: "<<fixed<<setprecision(10)<<tol<<"\tM?ximo de iteraciones: "<<maxIt<<endl<<endl;
			
			cout<<" i |x_0 \t\t|x_1 \t\t|f(x_0) \t|f(x_1) \t|x_2 \t\t|f(x_2) \t|Ea \t\t|Er \t\t|Erp\n";
			
			for(i=0; i<=maxIt; i++){
				fx0 = pow(x0, 3) + 6*pow(x0, 2) + 9.4*x0 + 2.5;
				fx1 = pow(x1, 3) + 6*pow(x1, 2) + 9.4*x1 + 2.5;
				x2 = x1-fx1*((x0-x1)/(fx0-fx1));
				fx2 = pow(x2, 3) + 6*pow(x2, 2) + 9.4*x2 + 2.5;
				
				if(i>0){
					ea = fabs(x2-xa);
					er = ea/(fabs(x2));
					erp = er*100;
					
					iteracion=i;
					
					if(tolE==1 && i>0){
						if(ea<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else if(tolE==2){
						if(er<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
					else{
						if(erp<=tol){
							i=maxIt;
							encontrada=true;
						}
					}
				}
				
				if(i==0){
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t| \t\t| \t\t|\n", i, x0, x1, fx0, fx1, x2, fx2);					
				}
				else{
					printf(" %d |%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \t|%3.9lf \n", iteracion, x0, x1, fx0, fx1, x2, fx2, ea, er, erp);
				}
				
				xa = x2;
				
				if((fx2*fx0)>=0){
					x0 = x2;
				}
				else{
					x1 = x2;
				}
			}
		break;
	}
	
	if(encontrada==true){
		cout<<"\n La ra?z obtenida es "<<x2<<", en la iteraci?n "<<iteracion<<", con una toleracia de ";
				
		if(tolE==1){
			cout<<fixed<<setprecision(10)<<ea<<" <= "<<tol<<" en el error absoluto.\n";
		}
		else if(tolE==2){
			cout<<fixed<<setprecision(10)<<er<<" <= "<<tol<<" en el error relativo.\n";
		}
		else{
			cout<<fixed<<setprecision(10)<<erp<<" <= "<<tol<<" en el error relativo porcentual.\n";
		}
	}
	else if(iteracion==maxIt && encontrada==false){
		cout<<"\n Despu?s de "<<maxIt<<" iteraciones como m?ximo, la ra?z con tolerancia de "<<tol;
		
		if(tolE==1){
			cout<<" en el error absoluto, no ha sido encontrada en el intervalo ingresado.\n";
		}
		else if(tolE==2){
			cout<<" en el error relativo, no ha sido encontrada en el intervalo ingresado.\n";
		}
		else{
			cout<<" en el error relarivo porcentual, no ha sido encontrada en el intervalo ingresado.\n";
		}
	}
	
}


double normalizaVector(double vector[], double *error, int t)				//PROGRAMA 3
{
    double nuevoE = 0;
    double vectorAux[t];
    for(int x = 0; x < t; x++)
    {
        if(vector[x] < 0)
        {
            vectorAux[x] = vector[x] * -1;
        }else{
            vectorAux[x] = vector[x];
        }
    }
   
    double mayor = vectorAux[0];
    int c = 0;
    for(int x = 0; x < t; x++){
        if(mayor < vectorAux[x])
        {
            mayor = vectorAux[x];
            c = x;
        }
    }
    double landa = vector[c];
    double norma = mayor;
   
    printf("Landa %.4lf\n", landa);
    printf("Norma %.4lf\n", norma);
    nuevoE = norma - *error;
    if(nuevoE < 0)
    {
        nuevoE *= -1;
    }
    printf("Error: %.4lf\n", nuevoE);
    printf("\n");
    for(int x = 0; x < t; x++)
    {
        vector[x] /= landa;
    }
    *error = norma;
    return(nuevoE);
}

main(){
	setlocale(LC_CTYPE,"Spanish");
	
	int opMet, opFun, opMenu, i, j, k, n, maxIt, tolE,contador=0;
	double x0, x1, tolerancia, ne, raiz, derivfx0, det, aii=0,suma=0;
	char resp='S';
	bool condicion=false;
	
	portadaGeneral();
	
	do{
		system("cls");
		
		opMenu=menuGeneral();
		
		switch(opMenu){
			case 1:
				do{
					system("cls");
					
					opMet=menuMetodo();
					
					do{
						opFun=menuFuncion();
						
						do{
							system("cls");
							
							if(opMet==2){
								cout<<" Ingrese valor inicial: ";
								cin>>x0;
								
								derivfx0 = df(x0, opFun);	
								
								while(derivfx0==0 ||(opFun==2 && x0==0)){
									cout<<" **Error**\n Esta funcion no acepta "<<x0<<" como valor inicial\n";
									
									cout<<" Ingrese otro valor inicial: ";
									cin>>x0;
								
									derivfx0 = df(x0, opFun);	
								}
							}
							else{
								cout<<" Ingrese valores iniciales.\n";
								cout<<" x0: ";
								cin>>x0;
								cout<<" x1: ";
								cin>>x1;
								
								while(x0>=x1 || (opFun==2 && (x0==0 || x1==0))){
									if(x0>=x1){
										cout<<" **ERROR**\n Ingrese x0<x1\n";
										
										cout<<"\n Ingrese valores iniciales.\n";
										cout<<" x0: ";
										cin>>x0;
										cout<<" x1: ";
										cin>>x1;
										
									}
									else if(opFun==2 && (x0==0 || x1==0)){
										cout<<" **ERROR**\n Esta funcion no acepta valores iguales a 0 (cero)\n";
										
										cout<<"\n Ingrese valores iniciales.\n";
										cout<<" x0: ";
										cin>>x0;
										cout<<" x1: ";
										cin>>x1;
									}
								}
							}
							
							cout<<"\n Ingrese el m?ximo de iteraciones: ";
							cin>>maxIt;
							
							cout<<"\n 1.- Ea \n 2.- Er \n 3.- Erp \n ?Donde desea la tolerancia? ";
							cin>>tolE;
							while(tolE!=1 && tolE!=2 && tolE!=3){
								cout<<" **ERROR**\n Solo ingrese 1, 2 o 3.\n";
								cout<<"\n ?Donde desea la tolerancia? ";
								cin>>tolE;
							}
							
							cout<<"\n Ingrese una toleracia: ";
							cin>>tolerancia;
							
							system("cls");
				
							if(opMet==1){
								posicionFalsa(opFun, x0, x1, maxIt, tolE, tolerancia, i);
							}
							else{
								metodoNewton(opFun, x0, maxIt, tolE, tolerancia, i);						
							}
					
							cout<<"\n\n ?Qu? desea hacer ahora?\n R = Obtener otra ra?z.\n F = Ir a men? de funciones.\n M = Ir a men? de m?todos. \n P = Volver al men? principal. \n S = Salir.\n";
							cout<<"\n Respuesta: ";
							resp=getche();
							
							system("cls");
						}while(resp=='R' || resp=='r');
					}while(resp=='F' || resp=='f');
				}while(resp=='M' || resp=='m');
			break;
			
			case 2:
				do{
					system("cls");
					
					portadaSistemas();
			
					
					system("cls");
					
					cout<<" Ingrese el tama?o de la matriz: ";
					cin>>n;
					
					double matriz[n][n];
					double vIndep[n];
					double vector[n];
					double matrizJacobi[n][n];
					double matrizCholesky[n][n];
					
					while(n<1){
						cout<<"\n **La matriz no puede ser menor a 1**\n\n";
						cout<<" Ingrese el tama?o de la matriz: ";
						cin>>n;
					}
					
					cout<<" Ingrese los valores de la matriz.\n";
					for(i=0; i<n; i++){
						for(j=0; j<n; j++){ 
							cout<<" ["<<i+1<<"]["<<j+1<<"]= ";
							cin>>matriz[i][j];
						}
						cout<<endl;
					}
										
					for(i=0; i<n; i++){
						for(j=0; j<n; j++){
							cout<<"\t "<<fixed<<setprecision(2)<<matriz[i][j];
						}
						cout<<endl;
					}
						
					cout<<"\n Opciones";
					cout<<"\n C = Confirmar Datos Correctos";
					cout<<"\n M = Corregir Un Coeficiente De La Matriz.";
					cout<<"\n Respuesta: ";
					resp=getche();
					
					while(resp=='M' || resp=='m'){
						if(resp=='M' || resp=='m'){
							cout<<"\n\n Ingrese Rengl?n y Columna Del Coeficiente a Corregir.\n";
							cout<<" Rengl?n: ";
							cin>>i;
							cout<<" Columna: ";
							cin>>j;
						}
						else{
							cout<<"\n\n Ingrese El Rengl?n Del Coeficiente a Corregir.\n";
							cout<<" Rengl?n: ";
							cin>>i;
							j=1;
						}
						
						while(i<1 || i>n || j<1 || j>n){
							cout<<" **La Posici?n ["<<i<<"]["<<j<<"] no Existe ";
							if(resp=='M' || resp=='m'){
								cout<<"En Su Matriz**\n\n";
								cout<<" Ingrese Rengl?n y Columna Del Coeficiente a Corregir.\n";
								cout<<" Rengl?n: ";
								cin>>i;
								cout<<" Columna: ";
								cin>>j;
							}
						}
						
						cout<<"\n Ingrese el nuevo valor.\n ["<<i<<"]["<<j<<"]= ";
						if(resp=='M' || resp=='m'){
							cin>>matriz[i-1][j-1];
						}else{
							cin>>vIndep[i-1];
						}
						
						system("cls");
						
						for(i=0; i<n; i++){
							for(j=0; j<n; j++){
								cout<<"\t "<<fixed<<setprecision(2)<<matriz[i][j];
							}
							cout<<endl;
						}
						
					cout<<"\n Opciones";
					cout<<"\n C = Confirmar Datos Correctos";
					cout<<"\n M = Corregir Un Coeficiente De La Matriz.";
					cout<<"\n Respuesta: ";
						resp=getche();
					}			
					
					for(i=0; i<n; i++){
						for(j=0; j<n; j++){
							matrizJacobi[i][j]=matriz[i][j];
							matrizCholesky[i][j]=matriz[i][j];
						}
					}
					
					double fm, denominador;
					
					system("cls");
					if(n==1){
						cout<<endl;
						for(i=0; i<n; i++){
							for(j=0; j<n; j++){
								cout<<"\t "<<fixed<<setprecision(2)<<matriz[i][j];
							}
							cout<<endl;
						}
						cout<<"\n\n Determinante = "<<matriz[0][0]<<endl;
					}
					else{
						for(k=0; k<n; k++){
							denominador = matriz[k][k]; 
							for(i=k+1; i<n; i++){
								fm = -1*((matriz[i][k])/denominador);
								for(j=k; j<n; j++){
									matriz[i][j] = (fm*(matriz[k][j]))+(matriz[i][j]);
								}
							}
						}
						
						cout<<endl;
						
						for(i=0; i<n; i++){
							for(j=0; j<n; j++){
								cout<<"\t "<<fixed<<setprecision(2)<<matriz[i][j];
							}
							cout<<endl;
						}
						
						det=1;
						
						for(i=0; i<n; i++){
							det*=matriz[i][i];
						}
						
						cout<<"\n\n Determinante = "<<det<<endl;
					}
					
					cout<<"\n Opciones";
					cout<<" \n C = Calcular el determinante de otra matriz.";
					cout<<" \n J = Obtener La Solucion Del Sistema Por El Metodo De Jacobi";
					cout<<" \n S = Salir.";
					cout<<" \n\n Respuesta: ";
					resp=getche();
					if(resp=='J'||resp=='j')
					{
						{
						system("cls");
						if(det==0){
							cout<<" T? sistema de ecuaciones no tiene soluci?n."<<endl;
						}else{
							contador=0;
							for(i=0; i<n; i++){
								suma=0;
								for(j=0; j<n; j++){
									if(i==j){
										aii=abs(matrizJacobi[i][j]);	
									}
									else{
										suma+=abs(matrizJacobi[i][j]);
									}
								}
								if(aii>suma){
									contador++;
								}
							} 
							if(contador!=n){
								cout<<"\n La convergencia no se garantiza por no tratarse de un sistema EDD\n ";
								system("pause");
								system("cls");
							}
							
							for(i=0; i<n; i++){
								denominador = matrizJacobi[i][i]; 
								for(j=0; j<n; j++){
									if(j==i){
										matrizJacobi[i][j] = 0;
									}
									else{
										matrizJacobi[i][j] = -1*((matrizJacobi[i][j])/denominador); 
									}
									
									if(j==(n-1)){
										vIndep[i] = ((vIndep[i])/denominador); 
									}
									
								}
							}
							
							do{
								cout<<"\n Ingrese el vector inicial.\n";
								for(i=0; i<n; i++){
									cout<<"  ["<<i+1<<"]= ";
									cin>>vector[i];
								}
								
								cout<<"\n Ingrese el m?ximo de iteraciones: ";
								cin>>maxIt;
				
								cout<<"\n Ingrese una tolerancia: ";
								cin>>tolerancia;
								
								system("cls");
								
								cout<<"\t\t----Despeje---- \n\n";
								
								for(i=0;i<n;i++) {
									for(j=0; j<n; j++){
										cout<<"\t "<<matrizJacobi[i][j];
									}
									cout<<"\t| "<<vIndep[i];
									cout<<endl;
								}
								
								cout<<"\n\n\t\t-----Iteraciones-----\n k";
								
								for(i=0;i<n;i++){
									cout<<"\t|x(k)"<<i+1;
								}
								
								for(i=0; i<n; i++){
									cout<<"\t|x"<<i+1<<"(k)-x"<<i+1<<"(k-1)";
								}
								
								cout<<"\t|Norma espectral\n";
								
								for(i=0;i<n;i++){
									if(i==0){
										cout<<" x(0)";
									}
									cout<<"\t|"<<vector[i];
								}
								
							
								cout<<endl;
								
								contador=0;
								
								double vectorA[n];
								
								do{
									cout<<" x("<<contador+1<<")";
									for(i=0; i<n; i++){
										vectorA[i] = 0;
										for(j=0;j<n;j++){
											vectorA[i] += matrizJacobi[i][j]*vector[j];
										}
										vectorA[i] += vIndep[i];
									}
									
									for(i=0;i<n;i++){
										cout<<"\t|"<<fixed<<setprecision(3)<<vectorA[i];
									}
									
									for(i=0;i<n;i++){
										if(i==0){
											ne = abs(vectorA[i]-vector[i]);
											cout<<"\t|"<<fixed<<setprecision(8)<<abs(vectorA[i]-vector[i]);
										}
										else{
											if(ne<abs(vectorA[i]-vector[i])){
												ne = abs(vectorA[i]-vector[i]);
											}
											cout<<"\t|"<<fixed<<setprecision(8)<<abs(vectorA[i]-vector[i]);
										}
									}
									cout<<"\t|"<<fixed<<setprecision(10)<<ne<<endl;
									
									for(i=0;i<n;i++){
										vector[i]=vectorA[i];
									}
									
									contador++;		//0
								}while((ne>tolerancia)&&(contador<maxIt));
										//0                   //1
								cout<<"\n\n **Finalmente despu?s de "<<contador<<" iteraciones ";
								
								if(ne<=tolerancia){
									cout<<"se ha alcanzado una tolerancia de "<<ne<<"\n menor a "<<tolerancia<<" como se pidi?**\n";
									for(i=0;i<n;i++){
										cout<<"\tx"<<i+1<<": "<<vector[i]<<endl;
									}
								}
								else{
									cout<<"no se ha alcanzado la tolerancia de "<<tolerancia<<"**"<<endl<<endl;
								}
								
								cout<<" ?Desea calcular el sistema con otro vector inicial?(S/N) ";
								resp=getche();
							}while(resp=='s' || resp=='S');
						}
						cout<<"\n\n Opciones \n P = Regresar al men? principal. \n C = Calcular otra matr?z. \n S = Salir del programa.";
						cout<<"\n Respuesta: ";
						resp=getche();
					}
				}
				}while(resp=='C' || resp=='c');
			break;
		case 3:
			int t;
		    double vector[t];
		    double toleracia = 0.0005;
		    int iteraciones = 10;
		    double error = 1;
		    double errorT = 0;
		do
		{
				system("cls");
			    printf("Defina El Tama?o De La Matriz: ");		//"Defina El Tama?o De La Matriz
	    		scanf("%i", &t);
	    		printf("\n");
	    		if(t<1)
	    		{
		    		do
		    		{
			    		printf("\nLa matriz no puede ser menor a 1\n");
			    		printf("Defina El Tama?o De La Matriz: ");
			    		scanf("%i", &t);
					}while(t<1);
				}
				printf("\t\tINGRESE SU MATRIZ\n\n");
				double matriz[t][t];
			for(int x = 0; x < t; x++)							//ESCANEO DE MATRIZ
			{
				for(int y = 0; y < t; y++)
				{
				    printf("Ingresa [%d][%d]: ", x+1, y+1);
				    scanf("%lf", &matriz[x][y]);
				}
				printf("\n");
			}
		    for(int x = 0; x < t; x++)
		    {
		        printf("Ingresa [%d]: ", x+1);
		        scanf("%lf", &vector[x]);
		    }
			printf("\n");
		    for(int x = 0; x < t; x++)							//IMPRESION DE MATRIZ
			{
				printf("\t");
				for(int z = 0; z < t; z++)
				{
		            printf("%0.2lf", matriz[x][z]);
		            printf("\t");
		        }
		        printf("\n");
		    }
		    int i,j;
		    printf("\n Opciones");
			printf("\n C = Confirmar Datos Correctos");
			printf("\n M = Corregir Un Coeficiente De La Matriz.");
			printf("\n Respuesta: ");
			resp=getche();
		
		while(resp=='M' || resp=='m')			//Correcion Hasta Que Resp == M
		{
			system("cls");
			printf("\n");
			for(int x=0; x<t; x++)					//Impresion De Matriz
		    {
		        printf("\t");
		        for (int z=0; z<t; z++)
		        {
		            printf("%0.2lf", matriz[x][z]);
		            printf("\t");
		        }
		        printf("\n");
		    }
			if(resp=='M' || resp=='m')			//Donde Se Va A Corregir
			{
				printf("\n\n Ingrese Renglon y Columna Del Coeficiente a Corregir.\n");
				printf(" Renglon: ");
				scanf("%i", &i);
				printf(" Columna: ");
				scanf("%i", &j);
			}
			while(i<1 || i>t || j<1 || j>t)		//Validacion De Correcion
			{
				printf("La Posicion [%i][%i] no Existe ", i, j);
				printf("En Su Matriz\n\n");
				printf(" Ingrese Renglon y Columna Del Coeficiente a Corregir.\n");
				printf(" Renglon: ");
				scanf("%i", &i);
				printf(" Columna: ");
				scanf("%i", &j);
	
			}
			printf("\n Ingrese el nuevo valor.\n [%i][%i]= ", i, j);
			double auxcor;
			if(resp=='M' || resp=='m')			//Asignacion Del Nuevo Valor
			{
				scanf("%lf", &auxcor);
				matriz[i-1][j-1]=auxcor;
			}
				printf("\n");
			for(int x=0; x<t; x++)				//Impresion De La Nueva Matriz
			{
			    printf("\t");
			    for (int z=0; z<t; z++)
				{
					printf("%0.2lf", matriz[x][z]);
					printf("\t");
				}
				printf("\n");
			}
			printf("\n Opciones");
			printf("\n C = Confirmar Datos Correctos");
			printf("\n M = Corregir Un Coeficiente De La Matriz.");
			printf("\n Respuesta: ");
			resp=getche();						//Escaneo De Nuevo De La Respuesta
		}
			    printf("\n\nIngrese El Numero De Iteraciones: \n");
			    scanf("%d", &iteraciones);
			    printf("\nIngrese La Toleracia: \n");
			    scanf("%lf", &toleracia);
			    system("cls");
			    for(int i = 0; i < iteraciones; i++)
			    {
				    printf("\nIteracion %d\n", i+1);
				    double matrizAux[t][t];                     //INICIO DEL SU MAMA
		            double nuevoV[t];
		            for(int x = 0; x < t; x++)
		            {
		            	for(int y = 0; y < t; y++)
		            	{
		               		matrizAux[x][y] = matriz[x][y];
		            	}
		            }
		            
		            double aux = 0;
		            for(int x = 0; x < t; x++)
		            {
		                for(int y = 0; y < t; y++)
		                {
		                	aux += matrizAux[x][y] * vector[y];
		                //printf("%lf * %lf = %lf\n", matrizAux[x][y], vector[y], aux);
		                }
		                nuevoV[x] = aux;
		                printf("%lf\n", nuevoV[x]);
		                aux = 0;
		            }
					                                  
		            for(int x = 0; x < t; x++)
		            {
		               	vector[x] = nuevoV[x];
		            }
				    errorT = normalizaVector(vector, &error, t);
				    if(errorT < toleracia)
					{
				        printf("La Tolerancia Se Ha Revasado\n");
				        break;
				    }
					else if(i == iteraciones-1)
					{
				        printf("Se Ha Cumplido El Numero De Iteraciones Pero No Se Ha Llegado Al Eigenvalor\n");
				    }
				}
				printf("\n\n Opciones \n P = Regresar al men? principal. \n R = Calcular otro valor propio. \n S = Salir del programa.");
				printf("\n Respuesta: ");
				resp=getche();
		    }while(resp=='R' || resp=='r');
		break;
		}
	}while(resp=='P' || resp=='p');
}
