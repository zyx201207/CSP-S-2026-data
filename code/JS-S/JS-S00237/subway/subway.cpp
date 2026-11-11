#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 505, M = 5e5 + 5, Q = 1e5 + 5, INF = 1e13;
int c, n, m, d, q;
int w[M];
int x[Q], y[Q];
int G[N][N];//yi ditie wei dian de tu
int dis[N][N];//
vector <pair <int, int> > cnt[M];
bool vis[N];

/*void debuger() {
    cerr << "G:\n";
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (G[i][j] == INF) cerr << "X ";
            else cerr << G[i][j] << ' ';
        }
        cerr << '\n';
    }
    cerr << "dis:\n";
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (dis[i][j] == INF) cerr << "X ";
            else cerr << dis[i][j] << ' ';
        }
        cerr << '\n';
    }
    return;
}*/

void DJ(int x) {
    for(int i = 1; i <= n; ++ i) vis[i] = 0;
    priority_queue <pair <int, int> > pq;
    pq.push({0, x});
 //   cerr << '\n' << x << ':';
    while (!pq.empty()) {
        int tu = pq.top().second, tt = -pq.top().first;
  //      cerr << tu << ' ' << tt << ' ' << '\n' ;
        pq.pop();
        if (vis[tu]) continue;
        dis[x][tu] = tt;
 //       cerr << "disUpdate\n";
        for (int i = 1; i <= n; ++ i) {
            if (i == tu) continue;
            if (vis[i]) continue;
            if (G[tu][i] == INF) continue;
            pq.push({-1 * (tt + G[tu][i]), i});
 //           cerr << "push:" << tt + G[tu][i] << ' ' << i << "sz:" << pq.size() <<  '\n';
        }
        vis[tu] = 1;
    }
 //  cerr << '\n';
    return;
}

signed main () {
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++ i) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++ i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++ j) {
            int a, t;
            cin >> a >> t;
            cnt[a].push_back({i, t});
        }
    }
    for (int i = 1; i <= q; ++ i) {
        cin >> x[i] >> y[i];
    }

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (i == j) continue;
            else G[i][j] = INF;
        }
    }

    for (int i = 1; i <= m; ++ i) {
        int len = cnt[i].size();
        //cerr << len << ' ';
        for (int j = 0; j < len; ++ j) {
            for (int k = j + 1; k < len; ++ k) {
                //cerr << "Update";
                G[cnt[i].at(j).first][cnt[i].at(k).first] = min(G[cnt[i].at(j).first][cnt[i].at(k).first], cnt[i].at(j).second + cnt[i].at(k).second) ;
                G[cnt[i].at(k).first][cnt[i].at(j).first] = min(G[cnt[i].at(k).first][cnt[i].at(j).first], cnt[i].at(j).second + cnt[i].at(k).second) ;
            }
        }
    }
    for (int i = 1; i <= n; ++ i) {
        DJ(i);
    }

  //  debuger();

    for (int i = 1; i <= q; ++ i) {
        int tx = x[i], ty = y[i], tans = INF;
        for (int j = 0; j < cnt[tx].size(); ++ j) {
            for (int k = 0; k < cnt[ty].size(); ++ k) {
                tans = min(tans, dis[cnt[tx][j].first][cnt[ty][k].first] + cnt[tx][j].second + cnt[ty][k].second);
  //              cerr << cnt[tx][j].first << ' ' << cnt[tx][j].second;
   //             cerr << ' ' << cnt[ty][k].first << ' ' << cnt[ty][k].second << ' ' << dis[cnt[tx][j].first][cnt[ty][k].first] << ' ' << tans << '\n';
            }
        }
        cout << tans + w[tx] + w[ty] << '\n';
   //     cerr << "ans:" << tans + w[tx] + w[ty] << '\n';
    }
    return 0;

}
