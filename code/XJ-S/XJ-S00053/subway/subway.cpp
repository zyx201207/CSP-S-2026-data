//还剩下2小时，尽力吧
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

const int N = 510, M = 1010;
int c, n, m, d, q, cnt;
//int head[M], dis[M];
int dis[M][M], w[M];
int a[N][M], t[N][M];

// struct edge{
//     int to, w, next;
// }e[M];

// struct node{
//     int point, dis;
// }

// void add(int u, int v, int w) {
//     e[++ cnt].to = v;
//     e[cnt].w = w;
//     e[cnt].next = head[u];
//     head[u] = cnt;
// }
void add(int u, int v, int w) {
    dis[u][v] = dis[v][u] = w;
}

void Floyd(){
    for(int i = 1; i <= m + n; i ++)
        for(int j = 1; j <= m + n; j ++)
            for(int k = 1; k <= m + n; k ++) {
                if(dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
                }
//                    cout << i << " " << j << " " << k << " " << dis[i][k] + dis[k][j] << "\n";
            }

}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    memset(dis, inf, sizeof(dis));
    cin >> c >> n >> m >> d >> q;

//    for(int i = 1; i <= m + n; i ++)
//        for(int j = 1; j <= m + n; j ++)
//            dis[i][j] = 0;

        for(int i = 1; i <= m + n; i ++)
            dis[i][i] = 0;

    for(int i = 1; i <= m; i ++) {
        cin >> w[i];
    }

    for(int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j ++) {
            cin >> a[i][j] >> t[i][j];
            add(i + m, a[i][j], t[i][j]);
        }
    }
    Floyd();

    for(int i = 1; i <= q; i ++) {
        int x, y;
        cin >> x >> y;
//        for(int i = 1; i <= m + n; i ++) {
//            for(int j = 1; j <= m + n; j ++) {
//                cout << dis[i][j] << " ";
//            }
//            cout << "\n";
//        }
        cout << dis[x][y] + w[x] + w[y] << "\n";
    }
}
