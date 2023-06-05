#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
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
    int n,k;
    cin>>n>>k;
    int a[n];
    int len = 0;
    indexed_set s;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
        len++;
        s.insert(a[i]);
        if(k == 1)
        {
            cout<<a[i]<<" ";
            continue;
        }
        if(len==k)
        {
            if(k%2==0)
            {
                auto x = s.find_by_order(k/2-1);
                cout<<*x<<" ";
            }
            else
            {
                auto x = s.find_by_order(k/2);
                cout<<*x<<" ";
            }
            len--;
            s.erase(s.find_by_order(s.order_of_key(a[i-k+1])));
        }

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