#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 5e3 + 5;
const int INF = 1e7;

struct Node
{
    int u;
    int val;

    friend bool operator < (Node X, Node Y)
    {
        return X.val > Y.val;
    }
};

priority_queue <Node> Q;
vector <int> G[N];
long long arr[N];
int dis[N];
long long cnt[N];
bool vis[N];
int c, T, n;

void dijkstra(int s)
{
    while (!Q.empty()) Q.pop();
    for (int i = 1; i <= n; ++i)
    {
        cnt[i] = 1;
        dis[i] = INF;
        vis[i] = false;
    } 

    dis[s] = 0;
    Q.push({s, 0});

    while (!Q.empty())
    {
        Node now = Q.top();
        Q.pop();

        int u = now.u;
        if (vis[u]) continue;
        vis[u] = true;

        for (auto v : G[u])
        {
            if (dis[v] > dis[u] + 1)
            {
                cnt[v] = cnt[u];
                dis[v] = dis[u] + 1;
                Q.push({v, dis[v]});
            } else if (dis[v] == dis[u] + 1)
            {
                cnt[v] += cnt[u];
            }
        }
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> T;

    while (T--)
    {
        long long d;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) G[i].clear();

        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (arr[j] - arr[i] <= d)
                {
                    G[i].push_back(j);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            dijkstra(i);

            for (int j = i + 1; j <= n; ++j)
            {
                if (cnt[j] == 2) ++ans;
            } 
        }

        cout << ans << endl;
    }

    return 0;
}