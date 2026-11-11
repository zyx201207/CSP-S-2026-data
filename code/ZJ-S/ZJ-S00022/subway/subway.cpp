#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+10;
const int MAXD = 30;
long long n, m, _, d, q, lines[MAXN], res[MAXN*MAXD], vis[MAXN*MAXD];
vector <pair<int, long long> > edge[MAXN*MAXD];

void dij(int s){
    memset(res, 0x3f3f, sizeof(res));
    memset(vis, 0, sizeof(vis));
    res[s] = 0;
    priority_queue <pair<long long, int> > q;
    q.push({0, s});
    while (!q.empty()){
        int u = q.top().second;
        q.pop();
        if (vis[u]){
            continue;
        }
        vis[u] = 1;
        int sz = edge[u].size();
        for (int i = 0; i < sz; i++){
            int v = edge[u][i].first, w = edge[u][i].second;
            if (res[v] > res[u]+w){
                res[v] = res[u]+w;
                q.push({-res[v], v});
            }
        }
    }
}

int read(){
    int sum = 0, sign = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-'){
            sign = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9'){
        sum = (sum << 1)+(sum << 3)+(ch ^ 48);
        ch = getchar();
    }
    return sum*sign;
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    _ = read();
    n = read();
    m = read();
    d = read();
    q = read();
    for (int i = 1, w; i <= m; i++){
        w = read();
        edge[i].push_back({i+m, w});
        edge[i+m].push_back({i, w});
    }
    for (int i = 1, k; i <= n; i++){
        k = read();
        int last = -1, lastLyr = -1;
        for (int j = 1, a, t; j <= k; j++){
            a = read();
            t = read();
            int lyr = lines[a];
            if (last != -1){
                edge[last+(lastLyr+2)*m].push_back({a+(lyr+2)*m, 0});
                edge[a+(lyr+2)*m].push_back({last+(lastLyr+2)*m, 0});
            }
            edge[a+m].push_back({a+(lyr+2)*m, t});
            edge[a+(lyr+2)*m].push_back({a+m, t});
            last = a;
            lastLyr = lyr;
            lines[a]++;
        }
    }
    for (int i = 1, x, y; i <= q; i++){
        x = read();
        y = read();
        dij(x);
        printf("%d\n", res[y]);
    }
}