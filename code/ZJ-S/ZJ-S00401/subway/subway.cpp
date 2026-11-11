#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[500010];
vector<vector<int>> swi;
vector<vector<int>> swt;
int cnt[500010];

int dis[510][510]; // minimal distance from x to y
int ans = 0;

int main () {
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    memset (dis, 0x3f, sizeof (dis));
    cin >> c >> n >> m >> d >> q;
    swi.resize (m + 1);
    swt.resize (m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        dis[i][i] = 0;
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int aij, tij;
            cin >> aij >> tij;
            for (int ii = 0; ii < cnt[aij]; ++ii) {
                int swc = swi[aij][ii];
                // printf ("station:%d subway:%d other:%d predis:%d tothis:%d toother:%d\n", aij, i, swc, dis[swc][i], tij + swt[aij][ii]);
                dis[swc][i] = min (dis[swc][i], tij + swt[aij][ii]);
                dis[i][swc] = dis[swc][i];
            }
            ++cnt[aij];
            swi[aij].push_back (i);
            swt[aij].push_back (tij);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                if (u == v) {
                    continue;
                }
                dis[u][v] = min (dis[u][v], dis[u][i] + dis[i][v]);
                dis[v][u] = dis[u][v];
            }
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         cout << setw (12) << dis[i][j];
    //     }
    //     cout << endl;
    // }
    while (q--) {
        int x, y;
        cin >> x >> y;
        dis[n + 1][n + 1] = 0;
        dis[n + 2][n + 2] = 0;
        int td[510];
        memset (td, 0x3f, sizeof (td));
        td[n + 1] = 0;
        for (int i = 0; i < cnt[x]; ++i) {
            dis[n + 1][swi[x][i]] = swt[x][i];
            dis[swi[x][i]][n + 1] = swt[x][i];
        }
        for (int i = 0; i < cnt[y]; ++i) {
            dis[n + 2][swi[y][i]] = swt[y][i];
            dis[swi[y][i]][n + 2] = swt[y][i];
        }

        // cout << endl;
        // for (int i = 1; i <= n + 2; ++i) {
        //     for (int j = 1; j <= n + 2; ++j) {
        //         cout << setw (12) << dis[i][j];
        //     }
        //     cout << endl;
        // }

        priority_queue <int, vector<int>, greater<int>> pq;
        pq.push (n + 1);
        while (!pq.empty ()) {
            int u = pq.top ();
            pq.pop ();
            // printf ("mid:%d\n", u);
            for (int i = 1; i <= n + 2; ++i) {
                // printf ("end:%d predis:%d middis:%d midlen:%d\n", i, td[i], td[u], dis[u][i]);
                if (td[i] > td[u] + dis[u][i]) {
                    td[i] = td[u] + dis[u][i];
                    pq.push (i);
                }
                // printf ("end:%d upddis:%d middis:%d midlen:%d\n", i, td[i], td[u], dis[u][i]);
                // cout << endl;
            }
        }
        cout << td[n + 2] + w[x] + w[y] << endl;

        for (int i = n + 1; i <= n + 2; ++i) {
            for (int j = 1; j <= n + 2; ++j) {
                dis[i][j] = 0x3f3f3f3f;
                dis[j][i] = 0x3f3f3f3f;
            }
        }
    }
    fclose (stdin);
    fclose (stdout);
    return 0;
}