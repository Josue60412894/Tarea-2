#include <iostream>
using namespace std;
#include <string.h>
#include <cstring>

/*
Instrucciones:
  1. Los Datos son automaticamente ingresados con la funcion ingreso_datos para agilizar el registro de datos.
  2. Los Datos son analizados para verificar que los numeros sean validos (no sean 0) y que el nombre no sea Null. La empresa es opcional. Solo se continua con el programa si todos los datos son validos, en caso contrario se imprime Error y se indica el dato faltante
  3. Luego se reseva memoria para el nombre y empresa utilizando la funcion reserva_memoria
  4. Seguidamente se imprimen los datos validos utilizando la funcion imprimir_datos
  5. Posteriormente se solicia el ingreso de un numero de cédula para realiar la busque, y si se encuentra un match se imprimen los datos de ese usuario. Si no se encuentra, se imprime un error
  6. Finalmente se limpia la memoria de todos los datos almacenados usando la funcion limpiar_memoria
*/

struct Cliente 
{
  int cedula;
  int telefono;
  char *nombre;
  char *empresa;
};

struct Cliente_reservado 
{
  char *nombre;
  char *empresa;
};

Cliente ingreso_datos(struct Cliente *ptr)
{ 
    
    
    (ptr+0) -> cedula =1111;
    (ptr+0) -> telefono =22623337;
    (ptr+0) -> nombre ="JEAsN";
    (ptr+0) -> empresa ="TOYOTA";

    (ptr+1) -> cedula =2222;
    (ptr+1) -> telefono =47585676;
    (ptr+1) -> nombre ="KAREN";
    (ptr+1) -> empresa ="NISSAN";
     
    (ptr+2) -> cedula =3333;
    (ptr+2) -> telefono =4516;
    (ptr+2) -> nombre ="ROBERT";
    (ptr+2) -> empresa ="BMW";
     
    (ptr+3) -> cedula =4444;
    (ptr+3) -> telefono =89789;
    (ptr+3) -> nombre ="JOSEPH";
    (ptr+3) -> empresa ="AUDI";

    (ptr+4) -> cedula =5555;
    (ptr+4) -> telefono =68767;
    (ptr+4) -> nombre ="VLADIMIR";
    (ptr+4) -> empresa ="KIA";
    return *ptr;
}

void reserva_memoria(struct Cliente_reservado *ptr, int Nclients, struct Cliente *ptr1){

  Nclients = Nclients -1;

  (ptr + Nclients)->nombre = new char[strlen((ptr1 + Nclients)->nombre)];
  (ptr + Nclients)->empresa = new char[strlen((ptr1 + Nclients)->empresa)];
  strcpy((ptr + Nclients)->nombre, (ptr1 + Nclients)->nombre);
  strcpy((ptr + Nclients)->empresa, (ptr1 + Nclients)->empresa);

  if (Nclients > 1)
  {
    reserva_memoria(ptr,Nclients,ptr1);
  }
  

}

void revisar_datos_invalidos(struct Cliente *ptr, int Nclientes, bool &bandera_validacion)
{
    if((ptr + Nclientes)->cedula == 0){

        std::cout << "\n[Error] Debe Ingresar el dato del cliente " << (Nclientes + 1) << ": cedula\n" << std::endl;
    
        bandera_validacion = false;

    } else if((ptr + Nclientes)->telefono == 0){

        std::cout << "\n[Error] Debe Ingresar el dato del cliente " << (Nclientes + 1) << ": telefono\n" << std::endl;
        
        bandera_validacion = false;

    } else if((ptr + Nclientes)->nombre == nullptr){

        std::cout << "\n[Error] Debe Ingresar el dato del cliente " << (Nclientes + 1) << ": nombre\n" << std::endl;
       
        bandera_validacion = false;
        
    } else{
      
        Nclientes =  Nclientes - 1;
    }

    if (Nclientes >= 0  && bandera_validacion == true)
    {
        revisar_datos_invalidos(ptr, Nclientes, bandera_validacion);

    } else if(Nclientes < 0  && bandera_validacion == true){

        std::cout << "\nTodos los datos ingresados son validos \n" << std::endl;

    } 
}

void imprimir_datos(struct Cliente *ptr, int cliente)
{
   
   cliente = cliente - 1;
   
   if(cliente >= 0 ){
    
    std::cout << "Informacion del cliente --> " << (cliente + 1) << std::endl;
    
    std::cout <<"Cedula: "<< (ptr+cliente) ->cedula << std::endl;  
    std::cout <<"Telefono: "<< (ptr+cliente) ->telefono << std::endl; 
    std::cout <<"Nombre: "<< (ptr+cliente) ->nombre << std::endl; 
    std::cout <<"Empresa: "<< (ptr+cliente) ->empresa << "\n" <<std::endl;  
  }

  if(cliente >= 0 ){
    imprimir_datos(ptr,cliente);
  }

}

int buscar_cliente(struct Cliente *ptr, int cedula, int Nclientes, bool &p){

  Nclientes = Nclientes - 1;

  if((ptr + Nclientes)->cedula == cedula ){

    return Nclientes;   

  }else if(Nclientes > 0){

    buscar_cliente(ptr,cedula,Nclientes,p);

  }else{
    p = false;
    std::cout << "\nNo se encontró la cedula ingresada. Favor iniciar de nuevo." << std::endl;
  }

}   

void limpiar_memoria(struct Cliente_reservado *ptr, int Nclients, struct Cliente *ptr1)
{
  Nclients = Nclients -1;

  delete (ptr + Nclients)->empresa;

  delete (ptr + Nclients)->nombre;


  if(Nclients > 0){

    limpiar_memoria(ptr,Nclients,ptr1);

  } else {

     delete ptr1;

    std::cout << "\nLa memoria reservada para los punteros del Nombre y Empresa fue liberada. Luego se liberaron todos los datos internos del cliente y finalmnete el puntero *clientes \n" << std::endl;


  }
  
}

int main() 

{
  
  std::cout << "\n+-+-+-Inicio del Ejercicio # 3 de la tarea 2+-+-+-\n" << std::endl;

   int cantidad_clientes = 5;

  struct Cliente *clientes = new Cliente[cantidad_clientes]; // declaracion de struct clientes

  struct Cliente_reservado *cliente_reserva = new Cliente_reservado[cantidad_clientes]; // declaracion de struct clientes_reservado

  bool validacion = true;
  
  bool cliente_existe = true;

  int cedula_buscado;

  ingreso_datos(clientes); // ingreso de datos automatico al sistema 

  revisar_datos_invalidos(clientes,cantidad_clientes - 1,validacion); // validacion de datos para asegurarse que los numeros sean validos

  if (validacion == true)  // solo se continua si la bandera de datos validos es TRUE. En caso contrario se termina la funcion. 

    {
      reserva_memoria(cliente_reserva,cantidad_clientes,clientes);

      imprimir_datos(clientes,cantidad_clientes);

      std::cout << "\nIngrese el numero de cedula a buscar: \n" << std::endl;

      cin >> cedula_buscado; 

      int cliente_encontrado = buscar_cliente(clientes,cedula_buscado,cantidad_clientes,cliente_existe); //funcion de buscar cliente en base al numero de cedula. Retorna el # de cliente dentro del array

      if(cliente_existe == true){ //solo se imprimen los valores de usuario si se encontró un match con la cedula ingresada

        std::cout << "\nEl cliente encontrado es el numero " << (cliente_encontrado + 1) << std::endl;
        std::cout <<"\n   Cedula: "<< (clientes+cliente_encontrado) ->cedula << std::endl;  
        std::cout <<"   Telefono: "<< (clientes+cliente_encontrado) ->telefono << std::endl; 
        std::cout <<"   Nombre: "<< (clientes+cliente_encontrado) ->nombre << std::endl; 
        std::cout <<"   Empresa: "<< (clientes+cliente_encontrado) ->empresa << "\n" <<std::endl;  

      }
      

      limpiar_memoria(cliente_reserva,cantidad_clientes,clientes); //limpieza de memoria
    }
    

  return 0;

}

