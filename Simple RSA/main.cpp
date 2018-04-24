#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string>
#include <gmp.h>

void menu_art();

int main()
{
  int menu_option;
  menu_art();
  char hex[]= "0abcdefghijklmnopqrstuvwxyz";

    std::cin >> menu_option;
    switch (menu_option) {
      case 1:
      system("clear");
      std::cout << "Choose two primes to generates key" << '\n';
      break;

      case 2:
      system("clear");
      break;

      case 3:
      system("clear");
      break;
    }


  /*
//-----------------------------------------  Bob Keys�s generation Zone
    cout << "Bob generates his public and private keys ----" << endl;

int p=5, q=13;   //  Bob chosen primes

int n;
    n=p*q;    //   product of primes TOTIENT = 48
    int k=5;  //   privada
    int j=29;  //   publica

    // public key of Bob is  (48,29)
    unsigned long int E;

   cout << "the product p*q=n is "<< n << endl<<endl;
   cout << "the chosen prime number k is "<< k << endl<<endl;
   cout << "the private key of Bob is "<< j << endl<<endl;

   cout << "the public key of bob is (" << n << "," << k << ")" << endl<<endl;
   cout << "---- Bob finish his keys generation----" << endl<<endl;

 //-----------------------------------------  Alice Encryption Zone
entry:

   int P;  //  data to be broadcast

   cout << "Enter the data to be send by Alice: ";

   cin >> P ;
   system("cls");
   cout << endl;
   cout << "The data Alice want to send is ---" << P << endl;
   cout << "Encryption by Alice begins ----" << endl;

   E=pow(P,j);    //     P is data , k is public key of Bob
   cout << " E=P^k   is "<< E <<endl;
   E = E %n; //  mod(n),  n is public key of Bob
   cout << "E mod(n) is "<< E << endl;
   cout << "the encrypted message Alice sends is "<< E << endl<<endl;

   //----------------------------------------  bob decryption Zone

   cout << "Decriptopn by Bob begins; E^j = P(mod n) " << endl;

   E = pow(E,k);
   E = E %n;
   cout << " the decrypted message is "<< E << endl<<endl;


   cout << "--------------------" << endl;
   //gets(dummy);
   goto entry;

   return 0;
   */
}

void menu_art(){
printf("                    888        Y88b   d88P\n");
printf("                    888         Y88b d88P  \n");
printf("                    888          Y88o88P  \n");
printf("                    888          Y88o88P \n");
printf(".d8888b .d88b.  .d88888 .d88b.    Y888P\n");
printf("d88P¨   d88¨¨88bd88¨ 888d8P  Y8b  d888b \n");
printf("888     888  888888  88888888888 d88888b\n");
printf("Y88b.   Y88..88PY88b 888Y8b.    d88P Y88b\n");
printf("¨Y8888P ¨Y88P¨  ¨Y88888 ¨Y8888d88P    Y88b \n");

printf("\n\n-----------------------------------------------\n");
printf("Andrés Orozco\nKevin Cardenas \nHector Mejia\n\n");
std::cout << "Main Menu" << '\n';
std::cout << "1) Generate Keys" << '\n';
std::cout << "2) Encrypt Data" << '\n';
std::cout << "3) Decrypt Data" << '\n';
}
