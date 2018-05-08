// Created by: Andres Orozco, Kevin Cardenas, Hector Mejía
// Yachay Tech 2018 Informatic security class project
// Check https://github.com/moonR2/EduAlgorithms for Repository
// Under MIT License

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <gmp.h>
#include "prime_gen.h"

char plaintext[1200];
char plaintext_dec[1200];
mpz_t charbase;
void texttonum();
void menu_art();
void load_data();


int main()
{
  //Variables
  int menu_option, main_menu;
  char prime1[1024];// Prime N1 (1024 bytes supported)
  char prime2[1024];// Prime N2
  char coprime_p[1024];
  int flag1, flag2;
  int cond;

  //GMP Variables
  mpz_t p1, p2,n, totien, coprime, inverse,encrypted_text;
  //Variables Initialize
  mpz_inits(p1,p2,n,totien,coprime,inverse,encrypted_text,NULL);

  do {
    menu_art();
    std::cin >> menu_option;

    switch (menu_option) {
      case 1:

      system("clear");
      {
        main_menu=0;
        std::cout << "Choose two primes to generates key" << '\n';
        std::cout << "Prime N1: " << '\n';
        scanf("%1023s", prime1);
        std::cout << "Prime N2: " << '\n';
        scanf("%1023s", prime2);
        std::cout << "Coprime: " << '\n';
        scanf("%1023s", coprime_p);
        //input assigment for p1,p2
        mpz_set_str(p1,prime1,10);
        mpz_set_str(p2,prime2,10);
        mpz_set_str(coprime,coprime_p,10);
        //The function return 2 if p is prime
        flag1 = mpz_probab_prime_p(p1,15);
        flag2 = mpz_probab_prime_p(p2,15);

        if(flag1==2 && flag2==2)
        {
          system("clear");
          std::cout << "----------------------------------------------------------" << '\n';
          std::cout << "Primes Numbers Checked" << '\n';
          mpz_mul(n,p1,p2);
          std::cout << "Prime 1: " << p1 <<'\n';
          std::cout << "Prime 2: " << p2 <<'\n';
          std::cout << "n: " << n << '\n';
          mpz_sub_ui(p1,p1,1);
          mpz_sub_ui(p2,p2,1);
          mpz_mul(totien,p1,p2);
          mpz_invert(inverse,coprime,totien);
          std::cout << "Totien: " << totien << '\n';
          std::cout << "Coprime(k): " << coprime << '\n';
          std::cout << "Inverse(j): " << inverse << '\n';
          std::cout << "----------------------------------------------------------" << '\n';
          std::cout << "Public Key(k,n): ("<< coprime << "," <<n <<")" << '\n';
          std::cout << "Private Key(j,n): ("<< inverse << "," <<n <<")" << '\n';
          cond = 1;
        }
        else
        {
          std::cout << "Error: Please enter a valid prime number" << '\n';
        }
      }
      mpz_clear(p1);
      mpz_clear(p2);
      std::cout << "Press 4 to display Main Menu: " << '\n';
      std::cin >> main_menu;
      break;

      case 2:
      system("clear");
      main_menu=0;
      prime_gen(p1,p2,999999999999999999,18446744073709551615);
      mpz_mul(n,p1,p2);
      std::cout << "----------------------------------------------------------" << '\n';
      std::cout << "Prime 1: " << p1 <<'\n';
      std::cout << "Prime 2: " << p2 <<'\n';
      std::cout << "n: " << n << '\n';
      mpz_sub_ui(p1,p1,1);
      mpz_sub_ui(p2,p2,1);
      mpz_mul(totien,p1,p2);
      coprime_gen(totien,coprime);
      std::cout << "Totien: " << totien << '\n';
      std::cout << "Coprime(k): " << coprime << '\n';
      mpz_invert(inverse,coprime,totien);
      std::cout << "Inverse(j): " << inverse << '\n';
      std::cout << "----------------------------------------------------------" << '\n';
      std::cout << "Public Key(k,n): ("<< coprime << "," <<n <<")" << '\n';
      std::cout << "Private Key(j,n): ("<< inverse << "," <<n <<")" << '\n';
      std::cout << "\nPress 4 to display Main Menu: " << '\n';
      std::cin >> main_menu;
      break;

      case 3:
      main_menu=0;
      system("clear");
      load_data();
      std::cout << "----------------------------------------------------------" << '\n';
      texttonum();
      mpz_powm(encrypted_text,charbase,coprime,n);
      std::cout << "Encrypted: " << encrypted_text << '\n';
      std::cout << "----------------------------------------------------------" << '\n';
      std::cout << "Press 4 to display Main Menu: " << '\n';
      std::cin >> main_menu;
      break;

      case 4:
      main_menu=0;
      system("clear");
      mpz_t decrypted_text;
      mpz_init(decrypted_text);
      mpz_powm(decrypted_text,encrypted_text,inverse,n);
      std::cout << "----------------------------------------------------------" << '\n';
      texttonum();
      std::cout << "Encrypted: " << encrypted_text <<'\n';
      std::cout << "Decrypted: " << decrypted_text << '\n';
      mpz_get_str(plaintext_dec,62,decrypted_text);
      std::cout << "Decrypted message: " << plaintext_dec << '\n';
      std::cout << "----------------------------------------------------------" << '\n';
      std::cout << "Press 4 to display Main Menu: " << '\n';
      std::cin >> main_menu;
      break;
    }
  }while(main_menu==4);

}

void load_data()
{

  char strconfig[120];
  FILE *msPtr;
  if ((msPtr = fopen("message.txt","r"))==NULL)
  {
    std::cout << "File not found" << '\n';
  }
  else
  {
    strcpy(plaintext," ");
    fseek(msPtr,0,SEEK_SET);
    while (fscanf(msPtr, "%s",strconfig) !=EOF)
    {
      strcat(strcat(plaintext, " "),strconfig);
    }
  }
  std::cout << "Message: " << plaintext << '\n';
  fclose(msPtr);

}


void menu_art()
{
  system("clear");
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
  printf("Andrés Orozco\nKevin Cardenas \nHector Mejia\n");
  printf("Repository: github.com/moonR2/EduAlgorithms \n\n");
  std::cout << "Main Menu" << '\n';
  std::cout << "1) Manually generation Keys" << '\n';
  std::cout << "2) Auto generation Keys" << '\n';
  std::cout << "3) Encrypt Data" << '\n';
  std::cout << "4) Decrypt Data" << '\n';
}

void texttonum()
{

  mpz_init(charbase);
  mpz_set_str(charbase,plaintext,62);
  std::cout << "TexInNumbers: " << charbase <<'\n';

}
