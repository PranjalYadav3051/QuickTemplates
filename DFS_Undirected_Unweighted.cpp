#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M 1000000007

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

vector<vector<ll>> g;

vector<ll> vis;
void dfs(ll node)
{
  vis[node]=1;
  for(auto v : g[node])
  {
    if(!vis[v])
    dfs(v);
  }
}

void solve()
{
  ll n,m;
  cin>>n>>m;
  g.resize(n+1); // resize to number of nodes
  vis.assign(n+1,0); // resize + clear

  for(ll i=0;i<m;i++)
  {
    ll a,b;
    cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }
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
  {
    solve();
    g.clear();
  }
 
  
}
 


