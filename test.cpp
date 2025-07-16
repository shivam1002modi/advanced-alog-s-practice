unsigned long long int gcd (unsigned long long int a, unsigned long long int b)
{
    unsigned long long int t;
    while (b !=0)
    {
        t = a%b;
        a = b;
        b = t;
    }
    return a;
}


unsigned long long int power(unsigned long long int a,unsigned long long int m,unsigned long long int p)
{
    unsigned long long int res =1;
    while(m>0)
    {
        if(m%2==1)
        {
            res = (res*a)%p;
        }
        a = (a*a)%p;
        m>>=1;
    }
    return res;
}

