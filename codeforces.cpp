#include <bits/stdc++.h>
// #include <sstream>
// #include <fstream>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(long long t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
  
#define int long long
#define cout std::cout<<
#define cin std::cin
#define nline <<"\n";
#define MOD 1000000007
#define Mod 998244353
#define fr(variable, start, last) for(int variable=start; variable<last; variable++)
#define pfr(variable, last, start) for(int variable=last-1; variable>=start; variable--)
#define vi vector<long long>
#define vvi vector<vector<long long>>
#define all(c) c.begin(), c.end()
#define mi map<long long, long long>
#define pii pair<int, int>
#define minheap priority_queue<int, vector<int>, greater<int>> 
#define vii vector<pair<int, int>>
#define pb push_back
#define ff first
#define ss second
#define gap <<" "


const int INF = 1e9;
const int64_t inf = 1e18;
const int nMax = 2 * 1e5 + 5;
// const int Inf = 0x3f3f3f3f3f3f3f3f;
// int n;
// const int MAXN = 500005;
// vi v(MAXN);
// int modinv[MAXN];
// int fact[MAXN];

int hcf(int a, int b){return a == 0 ? b : hcf(b%a, a);}
bool sortbysec(const pii &a,const pii &b) {return (a.second < b.second);}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;}
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

// void precomp(){modinv[0]=1;fact[0] =1;for(int i=1; i<MAXN; i++){fact[i] = mod_mul(fact[i-1], i, Mod);modinv[i] = modInverse(fact[i], Mod);}}
// int nCrModPFermat(int n, int r, int p) { if (n < r) return 0;if (r == 0)return 1;int fac[n + 1];fac[0] = 1;for (long long i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;return mod_div(fac[n], mod_mul(fac[n-r], fac[r], p), p);}
// int nPrModPFermat(int n, long long r, long long p){if (n < r)return 0;if (r == 0)return 1;return (mod_mul(fact[n], modinv[n-r], Mod));}
// v.resize(unique(v.begin(), v.end()) - v.begin());



void solve(){
    
    int n; cin >> n;
    // int m; cin >> m;
    // int k; cin >> k;
    // int q; cin>>q;
    // int a, b, c;cin>>a>>b>>c;
    // int x; cin>>x;

    // vector<int> v(n); fr(i, 0, n) cin>>v[i];








    
   
    return;
}

signed main()
{
    // Remove the below 2 lines for interactive problems.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1; 
    cin>>t;
    for(int i=0; i<t; i++)
    {
        // cout "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}
    // used when you have sort index of aid with respect to vector a
    // iota(aid.begin(), aid.end(), 0);
    // sort(aid.begin(), aid.end(), [&] (int l, int r) {
    //             return a[l] < a[r];
    //             });

