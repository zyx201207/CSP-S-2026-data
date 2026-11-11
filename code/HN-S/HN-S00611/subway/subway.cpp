#include<bits/stdc++.h>

using namespace std;

const int D = 22;
const int M = 505;
const int N = 5e5 + 5;
const long long INF = 5e15;

long long val[M][M], f[M][M];
int C, n, m, d, q, a[N], tot[N], c[N][D], tim[N][D];

void add(int x, int now, int t){
    tot[x]++;
    c[x][tot[x]] = now;
    tim[x][tot[x]] = t;
}

long long solve(int u, int v){
    long long ans = LLONG_MAX;
    for(int i = 1; i <= tot[u]; i++){
        for(int j = 1; j <= tot[v]; j++){
            long long now = f[c[u][i]][c[v][j]];
            now += a[u];
            now += a[v];
            now += tim[u][i];
            now += tim[v][j];
            ans = min(ans, now);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> C >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1, k; i <= n; i++){
        cin >> k;
        for(int j = 1, x, t; j <= k; j++){
            cin >> x >> t;
            add(x, i, t);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            val[i][j] = f[i][j] = INF;
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= tot[i]; j++){
            int u = c[i][j];
            for(int k = j + 1; k <= tot[i]; k++){
                int v = c[i][k];
                long long now = tim[i][j];
                now += tim[i][k];
                val[u][v] = min(val[u][v], now);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            val[i][j] = min(val[i][j], val[j][i]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            f[i][j] = val[i][j];
        }
        f[i][i] = 0;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for(int i = 1, x, y; i <= q; i++){
        cin >> x >> y;
        cout << solve(x, y) << '\n';
    }
    return 0;
}
