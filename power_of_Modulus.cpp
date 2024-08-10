void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;}
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
int nCrModPFermat(int n, int r, int p) { if (n < r) return 0;if (r == 0)return 1;int fac[n + 1];fac[0] = 1;for (long long i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;return mod_div(fac[n], mod_mul(fac[n-r], fac[r], p), p);}
int nPrModPFermat(int n, int r, int p) { if (n < r) return 0;if (r == 0)return 1;int fac[n + 1];fac[0] = 1;for (long long i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;return mod_div(fac[n], fac[r], p);}


unsigned long long power(unsigned long long x, long long y, long long p)
{
    //calculate large power very easily..
    unsigned long long res = 1; // Initialize result
    x = x % p; // Update x if it is more than or
    // equal to p
  
    while (y > 0) 
    {
      
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
  
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
  
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, long long p)
{
    return power(n, p - 2, p);
}
  
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n, long long r, long long p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
  
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (long long i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
  
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
unsigned long long nPrModPFermat(unsigned long long n, long long r, long long p)
{
    // If n<r, then nPr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
  
    // Fill factorial array so that we
    // can find all factorial of n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (long long i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
  
    return (fac[n]* modInverse(fac[n - r], p) % p)% p;
}
