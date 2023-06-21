#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define take(x)       \
    for (auto &y : x) \
        cin >> y;
#define show(x)           \
    for (auto y : x)      \
        cout << y << " "; \
    cout << endl;
#define pb push_back
#define mp make_pair
#define max3(a, b, c) max(max((a), (b)), (c))
#define max4(a, b, c, d) max(max((a), (b)), max((c), (d)))
#define min3(a, b, c) min(min((a), (b)), (c))
#define min4(a, b, c, d) min(min((a), (b)), min((c), (d)))
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
ll M = 998244353;
#define MAX 100000
ll mod = 1e9 + 7;

ll INF = 1e18;
ll adj[501][501];



void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0;i<501;i++)
{
    for(int j = 0;j<501;j++)
    {
        adj[i][j] =INF;
    }
}
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a][b] = min(c,adj[a][b]);
        adj[b][a] = min(c,adj[a][b]);
    }
    ll d[501][501];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if(i == j)
           {
            d[i][j] = 0;
           }
           else if(adj[i][j]) d[i][j] = adj[i][j];
           else
                d[i][j] =INF;
        }
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        if(d[a][b]==INF)
        {
            cout<<-1<<endl;
        }
        else
            cout<<d[a][b]<<endl;
    }
    return;
}

int main()
{
    int tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }

    return 0;
}