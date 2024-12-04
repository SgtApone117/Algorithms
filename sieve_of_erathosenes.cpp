void sieve_of_erathosenes(int& number)
{
    vector<bool> primes(number + 1, true);
    primes[0] = primes[1] = false;
    for(int i = 2; i * i <= number; ++i)
    {
        if(primes[i])
        {
            for(int j = i * i; j <= number; j += i)
            {
                primes[j] = false;
            }
        }
    }
    for(int i = 0; i <= number; ++i)
    {
        if(primes[i])
        {
            cout << i << " ";
        }
    }
}