#include <iostream>

using namespace std;

void pos_i(double *u, double min_x, double delta_x, int nt);
void adelante(double *u_n, double *u_v, int n, double delta_x, double delta_t, int c);

int main(){
	//Se declaran las variables
	int c = 1;
	int i;
	double dt = 0.001;
	double min_x=-2.0, max_x=2.0;
	double dx = 0.01;
	int nx = (max_x - min_x)/dx;
	int nt = 700;
	double * u_v, *u_n;
	//Se definen los puntos que se quieren imprimir
	int p1 = nt/5, p2 = 2*nt/5, p3 = 3*nt/5, p4 = 4*nt/5;
	//Se inicializan los arrays para el vector anterior y el nuevo
	u_v = new double[nx];
  	u_n = new double[nx];
	//Se corren las funciones
	pos_i(u_v, min_x, dx, nx);
	//Se leen 700 iteraciones
	adelante(u_n, u_v, nx, dx, dt, c);
	for(i=0;i<nt;i++){
		cout << u_n[i] << endl;
	}
	
	return 0;
}


//Funcion que definira los valores iniciales de la funcion
void pos_i(double *u, double min_x, double delta_x, int nt){
  int i;
  double x;
  for(i=0;i<nt;i++){
	//Valores de x
	x = min_x +  i * delta_x;
    	if(x<=0.5 ){
      	u[i] = 0.5;
   }
   	else{
      		u[i] = 0.0;
   }
  }
}
//Funcion que definira la iteracion de la funcion
void adelante(double *u_n, double *u_v, int n, double dx, double dt, int c){
  int i;
  double alpha = (c/2)*(dt/dx);
//Derivada
  for(i=1;i<n-1;i++){
    	u_n[i] = u_v[i] - alpha*(u_v[i+1]-u_v[i-1]);
  }
//Valor anterior de la funcion sera igualado al nuevo para la siguiente iteracion
  for(i=1;i<n-1;i++){
	u_v[i] = u_n[i];
	}
}


