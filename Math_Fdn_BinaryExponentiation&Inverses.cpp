#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M 1e9+7

#define pb push_back
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define all(x) (x).begin(), (x).end()
#define ll             long long
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            ll x; cin>>x; while(x--)
#define google cout << "Case #" << test_num << ": "
#define hi(x)           cout<<"hi"<<x<<endl;
#define ACC(v)          accumulate(v.begin(),v.end(),0ll)

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define pr(...){}
#define debarr(a,n){}
#define debmat(mat,row,col){}
#endif

//1101 
//BINARY EXPONENTIATION

ll binary_exponentiation(ll a,ll b,ll mod)
{
 //iterative fashion
 ll ans = 1; 
 while(b)
 {
  if(b%2==1) //b&1
 {
  ans = ans*a%mod;
 }
 a = a*a%mod ;
 b/=2;
 }

 return ans ;
}

//INVERSES OF NUMBERS
// a^(mod-2)%mod  = a^(-1)%mod 
// inverse of 2 in domin of 1e9+7 = 500000004
// (2 * 500000004) % 1e9+7 = 1; ..


void solve()
{
 ll a,b;
 cin>>a>>b;
 cout<<binary_exponentiation(a,b,1e9+7)<<"\n";
 cout<<binary_exponentiation(a,1e9+5,1e9+7)<<"\n";
}


int32_t main()
{
  fast;
  #ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  w(t)
  solve();
  
}
