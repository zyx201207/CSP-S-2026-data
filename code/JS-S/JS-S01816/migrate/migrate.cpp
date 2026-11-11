#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 300;
int n, d, c, t;
int dp[N + 10][N + 10];
int x[N + 10];
bool is[N + 10][N + 10];
pair<int, int> dis[N + 10][N + 10];

void floyd() {
    for (int u = 2; u <= n; u ++) {
        for (int i = 1; i + u <= n; i ++) {
            int j = i + u;
            for (int k = i + 1; k < j; k ++) {
                 if (is[i][k] && is[k][j]) {
                    if (dis[i][j].first > dis[i][k].first + 1) {
                        dis[i][j].first = dis[i][k].first + 1;
                        dis[i][j].second = 1;
                    } else if(dis[i][j].first == dis[i][k].first+ 1) {
                        dis[i][j].second ++;
                    }
                }
            }
        }
    }/*
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            for (int k = i + 1; k <= j; k ++) {
                if (is[i][k] && is[k][j]) {
                    if (dis[i][j].first > dis[i][k].first + 2) {
                        dis[i][j].first = dis[i][k].first + 2;
                        dis[i][j].second = 1;
                    } else if(dis[i][j].first == dis[i][k].first+ 2) {
                        dis[i][j].second ++;
                    }
                }
            }
        }
    }*/
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t --) {
        cin >> n >> d;
        for (int i = 1; i <= n; i ++) {
            cin >> x[i];
        }

        for (int i = 1; i <= n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                dis[i][j].first = 1e15;
                dis[i][j].second = 0;
                is[i][j] = 0;
                if (x[j] - x[i] <= d) {
                    is[i][j] = 1;
                    dis[i][j].first = 1;
                    dis[i][j].second = 1;
                }

            }
        }
        floyd();
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                if(dis[i][j].second == 2) {
                    ans ++;
            //        cout << i << ' ' << j << '\n' ;
                  //  cout << dis[2][4].first << 's' << '\n';
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
