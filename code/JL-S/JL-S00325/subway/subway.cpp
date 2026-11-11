#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
const int N = 5e2 + 5;
const int M = 5e5 + 5;
const LL inf = 0x3f3f3f3f3f3f3f3f;

int n, m, d, q;
int w[M], k[N], a[N][M], t[N][M];
vector <PII> points[M];
int S, T;
LL dis[N][N];

void bemin(LL &a, LL b) {
    a = a < b ? a : b;
}

void inp() {
    int c;
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);

    for (int i = 1; i <= m; i ++ )
        scanf("%d", &w[i]);

    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &k[i]);

        for (int j = 1; j <= k[i]; j ++ ) {
            scanf("%d%d", &a[i][j], &t[i][j]);
            points[a[i][j]].push_back({i, j});
        }
    }
}

void work() {
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            dis[i][j] = i == j ? 0 : inf;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= k[i]; j ++ )
            for (auto item : points[a[i][j]])
                if (i != item.first)
                    dis[i][item.first] = t[i][j] + t[item.first][item.second];

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i != j)
                for (int k = 1; k <= n; k ++ )
                    if (i != k && j != k)
                        bemin(dis[i][j], dis[i][k] + dis[k][j]);


    while (q -- ) {
        scanf("%d%d", &S, &T);
        LL ans = inf;

        for (auto i : points[S])
            for (auto j : points[T])
                bemin(ans, dis[i.first][j.first] + t[i.first][i.second] + t[j.first][j.second]);

        printf("%lld\n", ans + w[S] + w[T]);
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    inp();
    work();

    fclose(stdin);
    fclose(stdout);

    return 0;
}
