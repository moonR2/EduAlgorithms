// Created by: Andres Orozco, Kevin Cardenas, Hector Mejía
// Yachay Tech 2018 Informatic security class project
// Check https://github.com/moonR2/EduAlgorithms for Repository
// Under MIT License

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string>
#include <gmp.h>

void menu_art();

int main()
{
  //Variables
  int menu_option;
  char prime1[1024];// Prime N1 (1024 bytes supported)
  char prime2[1024];// Prime N2
  int flag1, flag2;
  int cond;

  //GMP Variables
  mpz_t p1, p2;
  menu_art();
  char hex[]= "0abcdefghijklmnopqrstuvwxyz";

  std::cin >> menu_option;
  switch (menu_option) {
    case 1:
    system("clear");
    cond = 0;
    while (cond==0)
    {

      std::cout << "Choose two primes to generates key" << '\n';
      std::cout << "Prime N1: " << '\n';
      scanf("%1023s", prime1);
      std::cout << "Prime N2: " << '\n';
      scanf("%1023s", prime2);
      //Numbers Initialize
      mpz_init(p1);
      mpz_init(p2);
      mpz_set_ui(p1,0);
      mpz_set_ui(p2,0);
      //input assigment for p1,p2
      mpz_set_str(p1,prime1,10);
      mpz_set_str(p2,prime2,10);
      //The function return 2 if p is prime
      flag1 = mpz_probab_prime_p(p1,15);
      flag2 = mpz_probab_prime_p(p2,15);
      if(flag1==2 && flag2==2)
      {
        std::cout << "Primes Numbers Checked" << '\n';
        cond = 1;
      }
      else
      {
        std::cout << "Error: Please enter a valid prime number" << '\n';
      }
    }
    std::cout << "Generating Key......." << '\n';
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
