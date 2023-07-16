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

vector<int> res;
vector<vector<ll>> adj(100005);
vector<ll> in(100005, 0);
vector<int> vis(100005,0);
bool kahn(int n)
{
    queue<ll> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0&&!vis[i])
        {
            q.push(i);
            vis[i] = 1;
        }
        while (!q.empty())
        {
            ll cur = q.front();
            q.pop();
            res.pb(cur);
            for (auto node : adj[cur])
            {
                in[node]--;
                if (in[node] == 0)
                {
                    q.push(node);
                    vis[node] = 1;
                }
            }
        }
    }
    //show(res);
    return res.size() == n;
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        in[b]++;
    }
    if (!kahn(n))
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    else
    {
        show(res);
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