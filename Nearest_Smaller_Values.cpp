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
    int n;
    cin >> n;
    int a[n];
    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        while(!s.empty()&&a[i]<=a[s.top()])
        {
            s.pop();
        }
        if(s.empty())
        {
            ans.pb(0);
        }
        else
        {
            ans.pb(s.top()+1);
        }
        s.push(i);
    }
    show(ans);
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