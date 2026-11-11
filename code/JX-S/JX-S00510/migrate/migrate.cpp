#include <bits/stdc++.h>

using namespace std;

#define int long long // sikaoyifan...
#define endl '\n'
#define gc getchar
#define PII pair<int, int> 

int read() {
    int x = 0, f = 1;
    char c = gc();
    while (!isdigit(c)) {
        if (c == '-') f = -1;
        c = gc();
    }
    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = gc();
    }
    return x * f;
}

const int N = 5010, INF = 1e9;

int n, m;
int x[N];
int dist[N][N], cnt[N][N];

void floyd() {
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ ) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    cnt[i][j] = cnt[i][k] * cnt[k][j];
                }
                if (dist[i][j] == dist[i][k] + dist[k][j])
                    cnt[i][j] += cnt[i][k] * cnt[k][j];
            }
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i ++ ) x[i] = read();

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i != j) dist[i][j] = INF, cnt[i][j] = 0;
            else dist[i][j] = 0, cnt[i][j] = 1;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (abs(x[j] - x[i]) <= m && i != j) dist[i][j] = 1, cnt[i][j] = 1;
        
    floyd();
    int res = 0;
    for (int i = 1; i <= n; i ++ ){
        for (int j = i + 1; j <= n; j ++ ){
            //cout << cnt[i][j] << ' ';
            if (cnt[i][j] == 36) {
                res ++;
            }            
        }        
        //cout << endl;
    }
    printf("%lld\n", res);
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int ID = read(), T = read();
    while (T -- ) {
        solve();
    }
    return 0; 
}