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
ll cl(ll a, ll b)
{
    if (a % b == 0)
    {
        return a / b;
    }
    else
    {
        return a / b + 1;
    }
}

// O(sqrt(n))
vector<long long int> prime_factors(ll n)
{
    vector<ll> vec;
    if (n % 2 == 0)
    {
        vec.push_back(2);
    }
    while (n % 2 == 0)
    {
        n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            vec.push_back(i);
        }
        while (n % i == 0)
        {
            n = n / i;
        }
    }
    if (n > 2)
    {
        vec.push_back(n);
    }
    return vec;
}
// ll power(ll x, unsigned long long int y, unsigned long long int M);
ll power(ll x, unsigned long long int y, unsigned long long int M)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2, M) % M;
    p = (p * p) % M;
    return (y % 2 == 0) ? p : (x * p) % M;
}
ll modInverse(ll A, ll M)
{
    int g = gcd(A, M);
    if (g != 1)
    {
        return A;
    }
    else
    {
        return (power(A, M - 2, M));
    }
}

ll fact(ll n)
{
    ll x = 1;
    for (int i = 1; i <= n; i++)
    {
        x = x * i;
        x = x % M;
    }
    return x;
}

void solve()
{

    return;
}

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> v1;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v1.push_back({input, i + 1});
    }
    sort(all(v1));
    ll i = 0;
    ll j = n - 1;
    ll sum = 0;
    int flag = 0;
    while (i < j)
    {
        sum = v1[i].first + v1[j].first;
        if (sum == x)
        {
            cout << v1[i].second << " " << v1[j].second << endl;
            flag = 1;
            break;
        }
        else if (sum > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    if (flag == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}