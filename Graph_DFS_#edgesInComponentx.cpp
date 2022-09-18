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
void dfs(ll node,ll comp)
{
  // marking the nodes with the component number only
  // -> finding for each node in which component it lies in.
  vis[node]=comp;
  for(auto v : g[node])
  {
    if(!vis[v])
    dfs(v,comp);
  }
}

void solve()
{
  ll n,m;
  cin>>n>>m;
  g.resize(n+1); // resize to number of nodes
  vis.assign(n+1,0); // resize + clear
  vector<pair<ll,ll>> edgelist;
  for(ll i=0;i<m;i++)
  {
    ll a,b;
    cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
    edgelist.pb({a,b}); // we make edge list undirected only extra info present in problem statement
  }

  ll num_comp =0;
  for(ll i=1;i<=n;i++)
  {
    if(!vis[i])
    {
      num_comp++;
      dfs(i,num_comp);
    }
  }
  cout<<num_comp<<"\n";

  // size 1 greater than components as 1 based indexing
  // number of edges in the given component
  vector<ll> num_of_edge(num_comp+1);

    for(auto v:edgelist)
    {
      num_of_edge[vis[v.first]]++;
    }
  pr(num_of_edge);
  
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
 

