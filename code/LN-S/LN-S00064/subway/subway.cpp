#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, int> Edge;

const int N = 510, M = 500010;

int testcase;
int n, m, d, q;
LL w[M];
vector<Edge> e[M];
LL f[N][N];

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &testcase, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++)
        scanf("%lld", &w[i]);
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++)
        f[i][i] = 0;
    for(int i = 1; i <= n; i++){
        int k;
        scanf("%d", &k);
        for(int j = 1; j <= k; j++){
            int a; LL t;
            scanf("%d%lld", &a, &t);
            e[a].push_back({t, i});
        }
    }
    for(int i = 1; i <= m; i++){
        int siz = e[i].size();
        for(int j = 0; j < siz; j++)
            for(int k = j + 1; k < siz; k++){
                int u = e[i][j].second;
                int v = e[i][k].second;
                LL len = e[i][j].first + e[i][k].first;
                f[u][v] = min(f[u][v], len);
                f[v][u] = min(f[v][u], len);
            }
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while(q--){
        int x, y;
        scanf("%d%d", &x, &y);
        LL ans = 0x3f3f3f3f3f3f3f3f;
        int sizx = e[x].size();
        int sizy = e[y].size();
        for(int j = 0; j < sizx; j++)
            for(int k = 0; k < sizy; k++){
                int u = e[x][j].second;
                int v = e[y][k].second;
                LL len = e[x][j].first + e[y][k].first;
                ans = min(ans, f[u][v] + len);
            }
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}
