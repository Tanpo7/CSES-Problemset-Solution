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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    vector<ll> b(m);
    take(a);
    take(b);
    sort(all(a));
    sort(all(b));
    int ans = 0;
    int s = -1;
    for(int i = 0;i<n;i++)
    {
        
        int x = lower_bound(b.begin()+s+1,b.end(),a[i]-k)-b.begin();
        int y = lower_bound(b.begin()+s+1,b.end(),a[i])-b.begin();
        if(x<n&&b[x]<=a[i]&&b[x]>=a[i]-k)
        {
            ans++;
            //cout<<1<<" "<<i<<" "<<b[x]<<endl;;
            s = x;
        }
        else if(y<n&&b[y]<=a[i]+k&&b[y]>=a[i])
        {
            ans++;
            //cout<<2<<" "<<i<<" "<<b[y]<<endl;
            s = y;
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