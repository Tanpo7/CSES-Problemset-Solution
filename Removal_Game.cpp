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

ll dp[5001][5001];
vector<ll> a(5001);

ll ans(int i, int j)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    ll ans1 = a[i]+min(ans(i+2,j),ans(i+1,j-1));
    ll ans2 = a[j]+min(ans(i+1,j-1),ans(i,j-2));

    return dp[i][j] = max(ans1,ans2);
}



void solve()
{
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=n;j++)
        {
            dp[i][j] = -1;
        }
    }
    cout<<ans(0,n-1)<<endl;
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