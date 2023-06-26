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


ll paths[1001][1001];
pair<int, int> from[1001][1001];
queue<pair<int, int>> q;
bool k;
ll n, m;
string ans;
void retrace(pair<int, int> node)
{
    pair<int, int> origin = from[node.first][node.second];
    if (origin == pair<int,int>(0, 0))
        return;
    if (origin.first == node.first + 1)
        ans.push_back('U');
    if (origin.first == node.first - 1)
        ans.push_back('D');
    if (origin.second == node.second + 1)
        ans.push_back('L');
    if (origin.second == node.second - 1)
        ans.push_back('R');
    retrace(origin);
}

void check(pair<int, int> s, pair<int, int> e)
{
    ll x = paths[s.first][s.second];
    if (x + 1 < paths[e.first][e.second])
    {
        paths[e.first][e.second] = x+1;
        q.push(e);
        from[e.first][e.second] = s;
    }
}

void bfsm()
{
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        pair<int, int> next = curr;
        q.pop();
        // Now check for all possible moves L,R,D,U
        next.first--;
        check(curr, next);
        next = curr;
        next.first++;
        check(curr, next);
        next = curr;
        next.second--;
        check(curr, next);
        next = curr;
        next.second++;
        check(curr, next);
    }
}

void bfsA()
{
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        pair<int, int> next = curr;
        q.pop();
        // Now check for all possible moves L,R,D,U
        next.first--;
        check(curr, next);
        next = curr;
        next.first++;
        check(curr, next);
        next = curr;
        next.second--;
        check(curr, next);
        next = curr;
        next.second++;
        check(curr, next);
        if (curr.first == 0 || curr.first == n-1 || curr.second == m-1 || curr.second == 0)
        {
            cout << "YES" << endl;
            cout << paths[curr.first][curr.second] << endl;
            retrace(curr);
            k = true;
            return;
        }
    }
}

void solve()
{
    
    cin >> n >> m;
    pair<int, int> start;
    ll inf = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            paths[i][j] = inf;
            char c;
            cin >> c;
            if (c == '#')
            {
                paths[i][j] = 0;
            }
            else if (c == 'M')
            {
                paths[i][j] = 0;
                q.push({i, j});
            }
            else if (c == 'A')
            {
                start.first = i;
                start.second = j;
            }
        }
    }

    bfsm();
    
    from[start.first][start.second] = pair<int,int>(0, 0);
    paths[start.first][start.second] = 0;
    q.push(start);
    bfsA();
    if (k)
    {
        reverse(all(ans));
        cout<<ans<<endl;
        return;
    }
    cout << "NO" << endl;

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