void sieve_of_sundaram(int& number)
{
    int nNew = (number-1)/2;
    vector<bool> marked(nNew+1, false);
    for(int i=1; i <= nNew; ++i)
    {
        for(int j = i; i+j+2*i*j <= nNew; ++j)
        {
            marked[i+j+2*i*j] = true;
        }
    }

    if(number > 2) // 2 is a prime number and sieve of sundaram doesn't consider it
    {
        cout << 2 << " ";
    }

    for(int i = 1; i <= nNew; ++i)
    {
        if(!marked[i])
        {
            cout << 2*i+1 << " "; // 2*i+1 is the prime number
        }
    } 
}