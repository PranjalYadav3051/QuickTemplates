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
vector<ll> color;
vector<ll> par; // parent vector to store parent of each node 


//COUNT THE NUMBER OF CYCLES A NODE IS A PART OFF 
//***************************
vector<ll> cnt_cycle;
vector<ll> prefixorder; // order in which they become 3 is the order in which we do the prefix sum part
//***************************

// DON'T DO THE PREFIX SUM ON THE NODE NUMBERS WE HAVE TO GENERATE A KIND OF ORDER

bool is_cycle = 0;

vector<ll> any_cycle;

void dfs(ll node, ll parent)
{
  par[node]=parent;
  color[node]=2;
  for(auto i:g[node])
  {
    if(color[i]==1)
    {
      //forward edge
    color[i]=2;
    dfs(i,node);
    }
    else if (color[i]==2){
      if(is_cycle==0)
      {
        cout<<"HIT:"<<node<<"\n";
        ll temp = node; // is the node on whihc we are doing dfs
        // is its last child that have backedge with it. temp(2)---->i(2)
        while (temp!=i)
        {
          any_cycle.pb(temp);
          temp = par[temp];
        }
        any_cycle.pb(temp);
        reverse(all(any_cycle));

      //***************************
      //for every backedge
      cnt_cycle[node]++;
      cnt_cycle[par[i]]--; //as we want ot keep i in the count also therefore its parent--
      //now prefix sum 
      }
      is_cycle =1;
      

    }
    else if (color[i]==3){

    }
  }
  //all neighbours ae exhausted for the current node color it 3
  color[node]=3;
  prefixorder.push_back(node); //order of the nodes
 
}
// base case for this recursion is: explore everything until and unless everything become color 2 or 3

void solve()
{
 int n,m;
 cin>>n>>m;
 g.resize(n+1); 
 color.assign(n+1,1);
 par.assign(n+1,0);
 cnt_cycle.assign(n+1,0);

 for(ll i=0;i<m;i++)
 {
  ll x,y;
  cin>>x>>y;
  g[x].pb(y);//directed 
 }

 //we don't assume that the graph have a single component, or every node is reachable from every other node
for(ll i=1;i<=n;i++){
  if(color[i]==1)
  dfs(i,0 );
}

for(auto i:any_cycle)
cout<<i<<" ";
cout<<"\n";

for(auto v: prefixorder)
{
  cnt_cycle[par[v]]+=cnt_cycle[v];
}


ll countofnodevizpartofcycle=0;
for(auto i: cnt_cycle)
{
  if(i> 0)
  {
    countofnodevizpartofcycle++;
  }
   cout<<i<<" "; 
}
cout<<"\n";

cout<<countofnodevizpartofcycle<<"\n";
}


int32_t main()
{
  fast;
  #ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  //w(t)
  solve();
  
}
 

