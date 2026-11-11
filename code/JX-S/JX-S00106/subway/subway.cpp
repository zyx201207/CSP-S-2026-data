#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 505, M = 500005, INF = 1e9;

int c, n, m, d, q;
int w[N], k[M], a[N][M], t[N][M];
int e[N][N];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    memset(e, 0x3f, sizeof e);

    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) scanf("%d", &w[m]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; j++)
            scanf("%d%d", &a[i][j], &t[i][j]);
    }

    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);

        printf("%d\n", w[x] + w[y]);
    }

    return 0;
}

