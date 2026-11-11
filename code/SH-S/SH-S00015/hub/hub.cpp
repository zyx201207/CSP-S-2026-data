#include <cstdio>
#include <cstring>
#include <queue>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
int c, t;
namespace task01_03
{
    int ans;
    int n, k;
    std::vector<int> graph[20];
    bool chosen[20];
    bool colorred[20];
    int dist[20];
    void color(int pos)
    {
        for(auto x : graph[pos])
        {
            if(!colorred[x] && chosen[x])
            {
                colorred[x] = true;
                color(x);
            }
        }
    }
    int calc()
    {
        memset(colorred, 0x3f, sizeof(colorred));
        memset(dist, 0x3f, sizeof(dist));
        int cnt = 0;
        for(int i = 1; i <= n; i++) if(chosen[i]) cnt++;
        if(cnt > k) return 1e9;
        cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!colorred[i] && chosen[i])
            {
                cnt++;
                color(i);
            }
        }
        if(cnt > 2) return 1e9;
        for(int i = 1; i <= n; i++)
        {
            if(chosen[i])
            {
                dist[i] = 0;
                std::queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    for(auto x : graph[q.front()])
                    {
                        if(dist[x] > dist[q.front()] + 1)
                        {
                            dist[x] = dist[q.front()] + 1;
                            q.push(x);
                        }
                    }
                    q.pop();
                }
            }
        }
        int mx = 0;
        for(int i = 1; i <= n; i++) mx = max(mx, dist[i]);
        return mx;
    }
    void dfs(int pos)
    {
        if(pos == n + 1)
        {
            ans = min(ans, calc());
            return ;
        }
        chosen[pos] = true;
        dfs(pos + 1);
        chosen[pos] = false;
        dfs(pos + 1);
    }
    void solve()
    {
        ans = 1e9;
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++) graph[i].clear();
        for(int i = 1; i <= n - 1; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1);
        printf("%d\n", ans);
    }
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d %d", &c, &t);
    while(t--)
    {
        if(1 <= c && c <= 3) task01_03::solve();
    }
    return 0;
}
// I guess the correct solution is the binary search
// Finish at 18:00
