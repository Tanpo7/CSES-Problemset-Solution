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

// Proper Explanantion:  https://github.com/phpduke/Algorithms-Notebook/blob/master/Graph%20Power%20Library.cpp
class Graph
{

    bool is_directed;

public:
    vector<vector<pair<int, ll>>> adj;
    int n, N = 2000000;
    Graph(int n_, bool is_directed_)
    {
        n = n_;
        is_directed = is_directed_;
        adj.resize(N, vector<pair<int, ll>>());
    }

    int hash(int u, int v)
    {
        return u * 1873 + v;
    }
    int hash(int u, int v, int k)
    {
        return k * 1873 * 1873 + u * 1873 + v;
    }
    bool node_has_edges(int u)
    {
        return (adj[u].size() != 0);
    }
    bool node_has_edges(int u, int v)
    {
        int x = hash(u, v);
        return (adj[x].size() != 0);
    }
    bool node_has_edges(int u, int v, int k)
    {
        int x = hash(u, v, k);
        return (adj[x].size() != 0);
    }

    void add_edge(int u, int v, ll c = 0)
    {
        add_edge_weighted_undirected(u, v, c);
        if (!is_directed)
            add_edge_weighted_undirected(v, u, c);
    }
    void add_edge(int ui, int uj, int vi, int vj, ll c = 0)
    {
        int u = hash(ui, uj), v = hash(vi, vj);
        add_edge_weighted_undirected(u, v, c);
        if (!is_directed)
            add_edge_weighted_undirected(v, u, c);
    }
    void add_edge(int ui, int uj, int uk, int vi, int vj, int vk, ll c = 0)
    {
        int u = hash(ui, uj, uk), v = hash(vi, vj, vk);
        add_edge_weighted_undirected(u, v, c);
        if (!is_directed)
            add_edge_weighted_undirected(v, u, c);
    }

private:
    void add_edge_weighted_undirected(int u, int v, ll c)
    {
        pair<int, ll> p = make_pair(v, c);
        adj[u].push_back(p);
    }
};

class BFS
{
    vector<ll> min_dist_from_source;
    vector<bool> visited;

public:
    BFS(Graph *g_)
    {
        g = g_;
        min_dist_from_source.resize(g->N, -1);
        visited.resize(g->N, false);
    }
    Graph *g;

    void run(int source)
    {
        queue<int> q;
        q.push(source);

        visited[source] = true;
        min_dist_from_source[source] = 0;

        while (!q.empty())
        {
            int cur_node = q.front();
            for (unsigned int i = 0; i < (g->adj[cur_node]).size(); ++i)
            {
                int adj_node = (g->adj[cur_node])[i].first;
                if (visited[adj_node] == false)
                {
                    visited[adj_node] = true;
                    min_dist_from_source[adj_node] = min_dist_from_source[cur_node] + 1;
                    q.push(adj_node);
                }
            }
            q.pop();
        }

        return;
    }

    void run(int sourcei, int sourcej)
    {
        int source = (g->hash)(sourcei, sourcej);
        run(source);
    }
    void run(int sourcei, int sourcej, int sourcek)
    {
        int source = (g->hash)(sourcei, sourcej, sourcek);
        run(source);
    }

    int min_dist(int targeti, int targetj)
    {
        int target = (g->hash)(targeti, targetj);
        return min_dist_from_source[target];
    }
    int min_dist(int targeti, int targetj, int targetk)
    {
        int target = (g->hash)(targeti, targetj, targetk);
        return min_dist_from_source[target];
    }
    int min_dist(int target)
    {
        return min_dist_from_source[target];
    }

    bool is_visisted(int targeti, int targetj)
    {
        int target = (g->hash)(targeti, targetj);
        return visited[target];
    }
    bool is_visisted(int targeti, int targetj, int targetk)
    {
        int target = (g->hash)(targeti, targetj, targetk);
        return visited[target];
    }
    bool is_visisted(int target)
    {
        return visited[target];
    }
};

void solve()
{
    
    int n,m;
    cin>>n>>m;
    Graph g(n*m,false);
    char a[n][m];
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(a[i][j] == '#')
            {
                continue;
            }
            else
            {
                if(i>0&&a[i][j] == a[i-1][j])
                {
                    g.add_edge(i,j,i-1,j);
                }
                if(i<n-1&&a[i][j] == a[i+1][j])
                {
                    g.add_edge(i,j,i+1,j);
                }
                if(j>0&&a[i][j] == a[i][j-1])
                {
                    g.add_edge(i,j,i,j-1);
                }
                if(j<m-1&&a[i][j] == a[i][j+1])
                {
                    g.add_edge(i,j,i,j+1);
                }

            }
        }
    }
    int ans = 0;
    BFS bfs(&g);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(bfs.min_dist(i,j) == -1&&a[i][j]=='.')
            {
                ans++;
            }
            bfs.run(i,j);
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