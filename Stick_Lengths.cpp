#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
 
// Kadane's Algorithm
long long int maxSubArraySum(long long int a[], long long int size)
{
    long long int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (long long int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}
bool isPrime(ll n)
{
    if (n == 1)
    {
        return false;
    }
    for (ll i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
 
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    take(a);
    //cout<<maxSubArraySum(a,n);
    sort(a,a+n);
    ll r = n/2;
    ll diff = 0;
    for(int i = 0;i<n;i++)
    {
        diff += abs(a[r]-a[i]);
    }
    cout<<diff<<endl;
}