//#include <algorithm>
//#include <cstdio>
//#include <queue>
//int c, n, m, d, q;
//namespace Task01_11
//{
//    int cnt;
//    std::vector<std::pair<int, long long>> graph[2010];
//    long long dis[2010][2010];
//    long long w[310];
//    void Dijkstra(int s)
//    {
//        for(int i = 1; i <= 2000; i++) dis[s][i] = 0x3f3f3f3f3f3f3f3fll;
//        dis[s][s] = 0;
//        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
//        pq.push({0, s});
//        while(!pq.empty())
//        {
//            long long d = pq.top().first;
//            int pos = pq.top().second;
//            pq.pop();
//            if(d > dis[s][pos]) continue;
//            for(auto x : graph[pos])
//            {
//                if(dis[s][x.first] > d + x.second)
//                {
//                    dis[s][x.first] = d + x.second;
//                    pq.push({dis[s][x.first], x.first});
//                }
//            }
//        }
//    }
//    void solve()
//    {
//        cnt = m;
//        for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
//        for(int i = 1; i <= n; i++)
//        {
//            int k;
//            scanf("%d", &k);
//            int lst = 0;
//            for(int j = 1; j <= k; j++)
//            {
//                int a;
//                long long t;
//                scanf("%d %lld", &a, &t);
//                cnt++;
//                graph[a].push_back({cnt, t});
//                graph[cnt].push_back({a, t});
//                if(lst != 0)
//                {
//                    graph[cnt].push_back({lst, 0});
//                    graph[lst].push_back({cnt, 0});
//                }
//                lst = cnt;
//            }
//        }
//        while(q--)
//        {
//            int u, v;
//            scanf("%d %d", &u, &v);
//            if(dis[u][v] != 0) printf("%lld\n", w[u] + dis[u][v] + w[v]);
//            else
//            {
//                Dijkstra(u);
//                printf("%lld\n", w[u] + dis[u][v] + w[v]); 
//            }
//        }
//    }
//};
//int main()
//{
//    freopen("subway.in", "r", stdin);
//    freopen("subway.out", "w", stdout);
//    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
//    if(1 <= c && c <= 11) Task01_11::solve();
//    return 0;
//}
// Ver1 : Finish at 15:54
// New Idea: Build a graph between lines and lines, and then you can get the result
// Time Complexity:O(d^2*Q+n^2logn+n^2logk)
// How smart I am!
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
long long edge[510][510];
long long dis[510][510];
long long w[500010];
std::vector<std::pair<int, long long>> sub[500010];
int c, n, m, d, q;
void Dijkstra(int s)
{
    for(int i = 1; i <= 500; i++) dis[s][i] = 0x3f3f3f3f3f3f3f3fll;
    dis[s][s] = 0;
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
    pq.push({0, s});
    while(!pq.empty())
    {
        long long d = pq.top().first;
        int pos = pq.top().second;
        pq.pop();
        if(d > dis[s][pos]) continue;
        for(int i = 1; i <= 500; i++)
        {
            if(dis[s][i] > d + edge[pos][i])
            {
                dis[s][i] = d + edge[pos][i];
                pq.push({dis[s][i], i});
            }
        }
    }
}
long long read()
{
    char ch = getchar();
    while(ch > '9' || ch < '0') ch = getchar();
    long long num = 0;
    while(ch >= '0' && ch <= '9')
    {
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    return num;
}
int main()
{
//    long long x = read();
//    printf("%lld", x);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(edge, 0x3f, sizeof(edge));
//    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    c = read();
    n = read();
    m = read();
    d = read();
    q = read();
    for(int i = 1; i <= n; i++) edge[i][i] = 0;
//    for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
    for(int i = 1; i <= m; i++) w[i] = read();
    for(int i = 1; i <= n; i++)
    {
        int k;
//        scanf("%d", &k);
        k = read();
        for(int j = 1; j <= k; j++)
        {
            int a;
            long long t;
//            scanf("%d %lld", &a, &t);
            a = read();
            t = read();
            sub[a].push_back({i, t});
        }
    }
    for(int i = 1; i <= m; i++)
    {
        int size = sub[i].size();
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                if(j == k) continue;
                edge[sub[i][j].first][sub[i][k].first] = std::min(edge[sub[i][j].first][sub[i][k].first], sub[i][j].second + sub[i][k].second);
            }
        }
    }
    for(int i = 1; i <= n; i++) Dijkstra(i);
//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 1; j <= n; j++) printf("%lld ", dis[i][j]);
//        puts("");
//    }
    while(q--)
    {
        int u, v;
//        scanf("%d %d", &u, &v);
        u = read();
        v = read(); 
        int size1 = sub[u].size(), size2 = sub[v].size();
        long long ans = 0x3fffffffffffffffll;
        for(int j = 0; j < size1; j++)
        {
            for(int k = 0; k < size2; k++)
            {
                ans = std::min(ans, sub[u][j].second + sub[v][k].second + dis[sub[u][j].first][sub[v][k].first]);
            }
        }
        printf("%lld\n", ans + w[u] + w[v]);
    }
    return 0;
}
// Finish at 16:41
