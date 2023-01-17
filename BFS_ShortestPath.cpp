#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define M 1e9 + 7

#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ps(x, y) fixed << setprecision(y) << x
#define w(x)  \
    ll x;     \
    cin >> x; \
    while (x--)
#define google cout << "Case #" << test_num << ": "
#define hi(x) cout << "hi" << x << endl;
#define ACC(v) accumulate(v.begin(), v.end(), 0ll)

// Read
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
// Print

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define pr(...) \
    {           \
    }
#define debarr(a, n) \
    {                \
    }
#define debmat(mat, row, col) \
    {                         \
    }
#endif

ll n, m;
vector<string> arr;

char dirchar[] = {'U', 'R', 'D', 'L'};
int dx[] = {-1, 0, +1, 0};
int dy[] = {0, +1, 0, -1};

bool check(int x, int y)
{ // is a valid cell
    if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != 'W')
        return 1;
    return 0;
}
/*
6 6
S.....
.W.W.W
R..W..
......
.D....
E.....

13
*/

// pos -> array of vectors -> rows are dynamic
//  we can't resize() the static arrays
//  it is not vector of arrays  -> columns are dynamic
void process(vector<pair<int, int>> pos[])
{ // syntax to put vector of pairs in argument
    // how to pass the array of vector of pairs
    //(vector<pair<int, int>>[] pos) -> this also works
    // & doesn't matter here as we are going to process it only once
    for (int dir = 0; dir < 4; dir++)
    {
        for (auto v : pos[dir])
        {
            int x = v.first + dx[dir], y = v.second + dy[dir];
            while (check(x, y) && arr[x][y] != dirchar[dir])
            {
                if (arr[x][y] == '.') // IF ULDR THEN ALSO ITS BLOCKED
                    arr[x][y] = 'B';
                x += dx[dir];
                y += dy[dir];
            }
        }
        for (auto v : pos[dir])
        { // SARE ULDR KO B KAR DIYA
          // PHLE TOH SARE . WALE B -> B BAN GAYE THE
            int x = v.first, y = v.second;
            arr[x][y] = 'B';
        }
    }
}

using state = pair<int, int>;
vector<vector<int>> dist;
vector<vector<pair<ll, ll>>> par;

#define F first
#define S second

int bfs(state st, state en)
{
    queue<state> q;
    dist.assign(n, vector<int>(m, 1e9));
    par.assign(n, vector<pair<ll, ll>>(m, {-1, -1}));
    dist[st.F][st.S] = 0;
    par[st.F][st.S] = {0, 0};
    q.push(st);
    while (!q.empty())
    {
        state cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int x = cur.F + dx[dir];
            int y = cur.S + dy[dir];
            if (check(x, y) && arr[x][y] != 'B' && dist[x][y] == 1e9)
            {
                // for every neighbour its not equals to B and its valid.
                dist[x][y] = dist[cur.F][cur.S] + 1;
                q.push(make_pair(x, y));
                par[x][y] = {cur.F, cur.S};
            }
        }
    }
    if (dist[en.F][en.S] == 1e9)
        return -1;
    else
        return dist[en.F][en.S];
}

void solve()
{
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pair<int, int> st, en;
    vector<pair<int, int>> pos[4]; // U,R,D,L

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'S')
            {
                st = {i, j};
            }
            else if (arr[i][j] == 'E')
            {
                en = {i, j};
            }
            else if (arr[i][j] == 'U')
            {
                pos[0].push_back({i, j});
            }
            else if (arr[i][j] == 'R')
            {
                pos[1].push_back({i, j});
            }
            else if (arr[i][j] == 'D')
            {
                pos[2].push_back({i, j});
            }
            else if (arr[i][j] == 'L')
            {
                pos[3].push_back({i, j});
            }
        }
    }
    process(pos);
    // how to pass the array of vector of pairs
    // just pass the name
    cout << bfs(st, en) << endl;

    vector<pair<ll, ll>> shortest;
    pair<ll, ll> now = en;
    shortest.pb({en.F, en.S});
    for (ll i = 0; i < dist[en.F][en.S]; i++)
    {
        shortest.pb(par[now.F][now.S]);
        now = par[now.F][now.S];
    }
    reverse(all(shortest));
    for (ll i = 0; i < shortest.size(); i++)
        cout << shortest[i].F<<" "<<shortest[i].S << "\n";
}

int main()
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
