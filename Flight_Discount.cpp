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
    vector<vector<pair<int, int>>> g1(n);
    vector<vector<pair<int, int>>> g2(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g1[a].pb({b, c});
        g2[b].pb({a, c});
    }
    ll inf = 1e18;
    vector<ll> d(n, inf);
    vector<ll> d2(n, inf);
    d[0] = 0;
    priority_queue<pair<ll, ll>> pq;
    vector<int> vis1(n, 0);
    pq.push({0, 0});
    while (!pq.empty())
    {
        ll a = pq.top().second;
        pq.pop();
        if (!vis1[a])
        {
            vis1[a] = 1;
            for (auto u : g1[a])
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
    d2[n-1] = 0;
    priority_queue<pair<ll, ll>> p;
    vector<int> vis2(n, 0);
    p.push({0, n-1});
    while (!p.empty())
    {
        ll a = p.top().second;
        p.pop();
        if (!vis2[a])
        {
            vis2[a] = 1;
            for (auto u : g2[a])
            {
                ll b = u.first;
                ll c = u.second;
                if (d2[a] + c < d2[b])
                {
                    d2[b] = d2[a] + c;
                    p.push({-1 * d2[b], b});
                }
            }
        }
    }
    ll ans = d[n-1];
    for(int i = 0;i<n;i++)
    {
        for(auto u:g1[i])
        {
            
            ll b = u.first;
            ll c = u.second;
            //cout<<b+1<<" "<<c<<endl;
            ans = min(ans,d[i]+d2[b]+c/2);
            //cout<<ans<<endl;
        }
    }
    cout<<ans<<endl;
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