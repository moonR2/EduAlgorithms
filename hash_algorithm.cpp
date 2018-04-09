//  Easy hash algorithm
//  moonyneverend@gmail.com
//  February  2018
//-----------------------------------
//    GLOBALS

#define text_length 80
unsigned int i;
char dummy[1];
int  letters_count = 0;
unsigned char code;
unsigned char ascii = (unsigned char)'a';
//-----------------------------------
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <ctime>
//--------------------------------
using namespace std;
//-----------------------------------
char hex_number[]= "0123456789abcdef"; //Hexadecimal

//-----------------------------------
//        MAIN
//----------------------------------
int main()
{
   int i;
   unsigned char nibble[2];
   char plaintext[80];
   int nib_0, nib_1;
   int text_pointer;
   int hash_pointer;
   int temp;


 entry:
    system("clr"); //system("cls") for windows
    int hash_frame[]= {15,14,13,12,11,10,1,2,3,4}; //fixed hash
    for(i=0;i<10;i++)cout << hash_frame[i]<<" ";  //  print fixed hash
    cout << endl;

    cout << "Has Frame:";
    for(i=0;i<10;i++)cout << hex_number[hash_frame[i]]; //  fixed hash on hex
    cout << endl;

    text_pointer=0;
    hash_pointer=0;

    cout << "-------------\n";
    cout << "Enter message:";
    fgets(plaintext,80,stdin);
    cout << "-------------\n";


 do
   {
    cout << "-------------\n";

    nibble[0]=plaintext[text_pointer];   //    char capture
    cout << nibble[0];                   //    print it
    cout << endl;
    nib_0=nibble[0];              //   to int
    nib_0=nib_0>>4;               //  4 most significant bits
    cout << nib_0 ;               //   print it
    cout << endl;
    nibble[0]=nib_0;              //   to char
//------------------------------------------
// Same as before
    nibble[1]=plaintext[text_pointer];
    cout << nibble[1];
    cout << endl;
    nib_1=nibble[1];
    nib_1=nib_1 & 15;
    cout << nib_1 ;
    cout << endl;
    nibble[1]=nib_1;
// XOR operations
    hash_frame[hash_pointer]= hash_frame[hash_pointer]^nibble[0];
    hash_frame[hash_pointer+1]= hash_frame[hash_pointer+1]^nibble[1];

    text_pointer++;
    hash_pointer=hash_pointer+2;
    }
    while(hash_pointer<=10);

    cout << "-Hash Found-----press Enter for new round---\n";
    for(i=0;i<10;i++)cout << hex_number[hash_frame[i]]; //  Print the final hash
    cout << endl;


   fgets(dummy,1,stdin);
   goto entry;

   return 0;
}
