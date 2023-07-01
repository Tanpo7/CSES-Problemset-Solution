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


int dp[501][125000];




void solve()
{
    int n;
    cin >> n;
    ll sum = n * (n + 1);
    sum /= 2;
    //cout<<sum<<endl;
    if (sum % 2 != 0)
    {
        cout << 0 << endl;
        return;
    }
    sum /= 2;
    //cout<<sum<<endl;
    
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=sum;j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum ; j++)
        {
            if (i <= j)
            {
                dp[i][j] = (dp[i - 1][j - i] + dp[i - 1][j]) % mod;
            }
            else
            {
                dp[i][j] = dp[i - 1][j]%mod;
            }
        }
    }
    
    cout << (dp[n][sum]) << endl;

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