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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> g(n);
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].pb({b, c});
    }
    ll inf = 1e18;
    vector<ll> d(n, inf);
    d[0] = 0;
    priority_queue<pair<ll,ll>> pq;
    vector<int> vis(n,0);
    pq.push({0, 0});
    while (!pq.empty())
    {
        ll a = pq.top().second;
        pq.pop();
        if (!vis[a])
        {
            vis[a] = 1;
            for (auto u : g[a])
            {
                ll b = u.first;
                ll c = u.second;
                if (d[a] + c < d[b])
                {
                    d[b] = d[a] + c;
                    pq.push({-1 * d[b], b});
                }
            }
        }
    }
    show(d);
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