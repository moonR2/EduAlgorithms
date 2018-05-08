void prime_gen(mpz_t prime1, mpz_t prime2, unsigned long long int min,unsigned long long int max)
{
  unsigned long long int r1, r2;
  mpz_inits(prime1, prime2, NULL);
    srand(time(0));
    r1 = (rand()%max)+min;
    r2 = (rand()%max)+min;
    mpz_set_ui(prime1,r1);
    mpz_set_ui(prime2,r2);
    for(int i = 0 ; i <= 9999;i++){
      mpz_nextprime(prime1,prime1);
      mpz_nextprime(prime2,prime2);
    }
}

void coprime_gen(mpz_t number, mpz_t coprime)
{
  unsigned long long int handle;
  mpz_t prime2,resul;
  mpz_inits(coprime,prime2, resul, NULL);
  do {
    prime_gen(coprime,prime2,999999999999999999,18446744073709551615);
    mpz_gcd(resul,number,coprime);
    handle = mpz_get_ui(resul);
  } while (handle != 1);

}
