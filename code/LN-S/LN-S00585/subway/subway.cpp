#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#include <queue>
#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int F = 505, N = 501005, M = 1000005, P = 25;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int n, m, nn;
int h[N], e[M], w[M], ne[M], idx;
LL dist[F][F];
int ww[N];
int q;
LL ans[N];
int line[N][P], tim[N][P], lcnt[N];
vector<PII> ll[F];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}


int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    memset(h, -1, sizeof h);

    int c, d;
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);

    for (int i = 1; i <= m; i ++ ) scanf("%d", &ww[i]);
    for (int i = 1; i <= n; i ++ ) {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j ++ ) {
            int a, t;
            scanf("%d%d", &a, &t);
            line[a][ ++ lcnt[a]] = i, tim[a][lcnt[a]] = t;
            ll[i].push_back({a, t});
        }
    }

    memset(dist, 0x3f, sizeof dist);

    for (int i = 1; i <= n; i ++ ) {
        dist[i][i] = 0;
        for (PII site: ll[i]) {
            for (int j = 1; j <= lcnt[site.x]; j ++ ) {
                int dest = line[site.x][j], t = tim[site.x][j];
                dist[i][dest] = dist[dest][i] = min(dist[i][dest], 0ll + t + site.y);
            }
        }
    }

    for (int k = 1; k <= n; k ++ ) {
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= q; i ++ ) {
        int x, y;
        scanf("%d%d", &x, &y);
        LL res = 0x3f3f3f3f3f3f3f3f;
        for (int l1 = 1; l1 <= lcnt[x]; l1 ++ ){
            for (int l2 = 1; l2 <= lcnt[y]; l2 ++ ){
                int ll1 = line[x][l1], ll2 = line[y][l2];
                int t1 = tim[x][l1], t2 = tim[y][l2];
                res = min(res, t1 + dist[ll1][ll2] + t2);
            }
        }
        printf("%lld\n", res + ww[x] + ww[y]);
    }
}