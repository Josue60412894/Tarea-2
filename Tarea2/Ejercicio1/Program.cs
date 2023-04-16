
Console.WriteLine($"Ingrese un numero para calcular fibonacci \n");  

double numero_objetivo = Convert.ToDouble(Console.ReadLine());

double numero_pasado_pasado = 0;
double numero_pasado = 1;
double nuevo_numero = 2;   

if(numero_objetivo == 0){

          Console.WriteLine($"Fibonacci (0) -> Resultado: 0 \n");

   } else if (numero_objetivo == 1){

        Console.WriteLine($"Fibonacci (0) -> Resultado: 1 \n");

   } else if (numero_objetivo > 1){
     
          Console.WriteLine($"Fibonacci (0) -> Resultado: 0 \n");

          Console.WriteLine($"Fibonacci (1) -> Resultado: 1 \n");

          Fibonacci(numero_objetivo,nuevo_numero,numero_pasado,numero_pasado_pasado);
   }


////Funcion Fibonnaci ////

void Fibonacci(double numero_objetivo, double numero_bandera, double numero_1, double numero_2) {

     double fibonacci = numero_1 + numero_2;
      
     Console.WriteLine($"Fibonacci ({numero_bandera}) -> Resultado: {fibonacci} \n");
     
     double new_numero_2 = numero_1;
     double new_numero_1 = fibonacci;
     double new_numero_bandera = numero_bandera +1;

     if(numero_objetivo > numero_bandera){
          
          Fibonacci(numero_objetivo, new_numero_bandera,new_numero_1,new_numero_2);

     }

   } 


    