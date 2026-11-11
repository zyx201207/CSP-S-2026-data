#include <bits/stdc++.h>
using namespace std;
long long f[2005][2005];
long long w[500005], t[500005], a[500005];
int c, n, m, d, q;
void init(){
    for (int i = 0; i <= 2004; i ++){
        for (int j = 0; j <= 2004; j ++){
            f[i][j] = 0x3f3f3f3f;
        }
    }
}

void floyd(){
    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= m; j ++){
            for (int k = 1; k <= m; k ++){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    init();

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++){
        cin >> w[i];
    }
    for (int i = 1; i <= n; i ++){
        memset(t, 0, sizeof(t));
        memset(a, 0, sizeof(a));
        int k;
        cin >> k;
        for (int j = 1; j <= k; j ++){
            cin >> a[j] >> t[j];
        }
        for (int di = 1; di <= k; di ++){
            for (int dj = di+1; dj <= k; dj ++){
                f[a[di]][a[dj]] = min(f[a[di]][a[dj]], t[di] + t[dj]);
                f[a[dj]][a[di]] = min(f[a[dj]][a[di]], t[dj] + t[di]);
            }
        }
    }

    floyd();
    for (int i = 1; i <= q; i ++){
        int u, v;
        cin >> u >> v;
        cout << f[u][v] + w[u] + w[v] << endl;
    }
    return 0;
}

//__int 128 rp; rp ++;
//I love CCF
//I hope to AC.But AK is better!
