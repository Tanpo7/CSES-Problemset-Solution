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

int n, m;

vector<int> vis(1e5+1, 0);
vector<int> col(1e5+1, 3);
vector<vector<int>> adj(1e5 + 2);

bool dfs(int v, int c)
{
    vis[v] = 1;
    col[v] = c;
    for (auto i : adj[v])
    {
        if (!vis[i])
        {
            if (dfs(i, c ^ 1) == false)
            {
                return false;
            }
            else
            {
                if (col[v] == col[i])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            //cout<<"Working"<<endl;
            if(!dfs(i, 1))
            {
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
    for(int i = 0;i<n;i++)
    {
        for(auto j:adj[i])
        {
            if(col[i] == col[j])
            {
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
    for(int i = 0;i<n;i++)
    {
        cout<<col[i]+1<<" ";
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