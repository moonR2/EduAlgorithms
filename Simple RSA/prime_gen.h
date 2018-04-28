void prime_gen(mpz_t prime1, mpz_t prime2)
{
  int flag1, flag2,r,r2;
  mpz_init(prime1);
  mpz_init(prime2);
  mpz_set_ui(prime1,1);
  mpz_set_ui(prime2,1);
  flag1 = mpz_probab_prime_p(prime1,15);
  flag2 = mpz_probab_prime_p(prime2,15);
  while (flag1!=2 && flag2!=2) {
    srand(time(0));
    r = (rand()%30000)+9999;
    r2 = (rand()%30000)+9999;
    mpz_set_ui(prime1,r);
    mpz_set_ui(prime2,r2);
    flag1 = mpz_probab_prime_p(prime1,15);
    flag2 = mpz_probab_prime_p(prime2,15);
  }
  mpz_nextprime(prime1,prime1);
  mpz_nextprime(prime2,prime2);
}
