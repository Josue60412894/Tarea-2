#include <iostream>
using namespace std;

/*
Los numero se alamcenan automaticamente en la funcion main
*/


void conversion(int *ptr, int posicion){ //funcion para leer el array y convertir numeros negativos a positivos

  if(*(ptr + posicion) < 0){ 

    *(ptr + posicion) = *(ptr+ posicion) * -1; //si el numero es negativo se multiplica por -1 para cambiar de signo

}   
  posicion++;

  if(posicion <= 9){ 

    conversion(ptr,posicion);
  }
}

void lecutra_array(int *ptr, int posicion){ //funcion para imprimir en consola los 10 numeros enteros almacenados en el vector 

  std::cout << *(ptr + posicion) << std::endl; 

  posicion++;

  if(posicion <= 9){ 

    lecutra_array(ptr,posicion);
  }
}


int main() {

  int *numeros = nullptr; 
  numeros = new int[10];   //declaración de la variable y reserva del espacion en el heap con NEW

  *(numeros + 0) = -50;
  *(numeros + 1) = -56;
  *(numeros + 2) = -20;
  *(numeros + 3) = -52;
  *(numeros + 4) = -99;
  *(numeros + 5) = -2;
  *(numeros + 6) =  33;
  *(numeros + 7) = -22;
  *(numeros + 8) = -63;
  *(numeros + 9) = -100;

  int posicion1 = 0;

  std::cout << "Los numeros orignales son los siguientes" << std::endl;

  lecutra_array(numeros, posicion1);

  conversion(numeros, posicion1); // llamado a la funcion para convertir numeros negativos a positivos

  std::cout << "\nLos numeros después de la conversion de cambio de signo negativo a positivo son los siguientes" << std::endl;

  lecutra_array(numeros, posicion1);

  delete[] numeros; // liberación de la memoria con DELETE 

  return 0;

}

