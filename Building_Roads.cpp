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

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<ll> vis(n, 0);
    set<ll> s;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            ans++;
            s.insert(i);
            vis[i] = 1;
            queue<ll> q;
            q.push(i);
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                vis[v] = 1;
                for (auto u : adj[v])
                {
                    if (!vis[u])
                    {
                        vis[u] = 1;
                        q.push(u);
                    }
                }
            }
        }
    }
    vector<ll> v(s.begin(), s.end());
    cout << ans-1 << endl;
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i]+1 << " " << v[i + 1]+1 << endl;
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