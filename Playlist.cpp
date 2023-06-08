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



//Unordered_Set gives TLE



void solve()
{
    int n;
    cin >> n;
    int a[n];
    take(a);
    set<int> s1;
    int ans = 0;
    int j = 0;
    int i = 0;
    while (i < n && j < n)
    {
        if (s1.find(a[j]) == s1.end()&&j<n)
        {
            s1.emplace(a[j]);
            j++;
        }
        else
        {
            ans = max(ans, j - i);
            while (s1.find(a[j]) != s1.end()&&i<n)
            {
                s1.erase(a[i]);
                i++;
            }
        }
    }
    cout << max(ans, (int)s1.size()) << endl;
    return;
}

int main()
{
    int tt;
    tt = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (tt--)
    {
        solve();
    }

    return 0;
}