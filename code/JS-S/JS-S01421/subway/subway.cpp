#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 5e5 + 5;
#define mp(a, b) make_pair(a, b)

struct edg{
    int u, v;
    long long w;
};

int n, m, d, q;
long long w[M], mat[N][N], dp[N][N];
vector<pair<int, long long> > a[M];
vector<edg> e;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, k, x, t, y;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) {
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++) {
        cin >> k;
        for(int j = 1;j <= k;j++) {
            cin >> x >> t;
            a[x].push_back(mp(i, t));
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(i != j) mat[i][j] = 1e17;
        }
    }
    for(int i = 1;i <= m;i++) {
        int len = a[i].size();
        for(int j1 = 0;j1 < len;j1++) {
            for(int j2 = j1 + 1;j2 < len;j2++) {
                int l1 = a[i][j1].first, l2 = a[i][j2].first;
                long long t1 = a[i][j1].second, t2 = a[i][j2].second;
                mat[l1][l2] = min(mat[l1][l2], t1 + t2);
                mat[l2][l1] = mat[l1][l2];
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            dp[i][j] = mat[i][j];
        }
    }
    for(int i = 2;i <= n;i++) {
        for(int j1 = 1;j1 < i;j1++) {
            for(int j2 = 1;j2 < i;j2++) {
                dp[i][j1] = min(dp[i][j1], dp[i][j2] + dp[j1][j2]);
            }
            dp[j1][i] = dp[i][j1];
        }
    }
    while(q--) {
        cin >> x >> y;
        long long ans = 1e17;
        for(int i = 0;i < (int)a[x].size();i++) {
            for(int j = 0;j < (int)a[y].size();j++) {
                ans = min(ans, a[x][i].second + a[y][j].second + dp[a[x][i].first][a[y][j].first]);
            }
        }
        cout << ans + w[x] + w[y] << endl;
    }
    return 0;
}
