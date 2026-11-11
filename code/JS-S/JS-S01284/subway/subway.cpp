#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10;
ll v, n, m, d, q, w[N], b[N][25], c[N][25], pos[N], dis[505][505];
void init() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= pos[i]; j++) {
            for (int k = 1; k <= pos[i]; k++) {
                if (j == k)continue;
                dis[b[i][j]][b[i][k]]=min(dis[b[i][j]][b[i][k]],c[i][j]+c[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }
}
void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && dis[i][k] != 0x3f3f3f3f && dis[k][j] != 0x3f3f3f3f)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> n >> m >> d >> q;
    memset(dis, 0x3f3f, sizeof(dis));
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        ll k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            ll a, t;
            cin >> a >> t;
            b[a][++pos[a]] = i;
            c[a][pos[a]] = t;
        }
    }
    init();
    floyd();
    while (q--) {
        ll s, t, ans = 1e18;
        cin >> s >> t;
        for (int i = 1; i <= pos[s]; i++) {
            for (int j = 1; j <= pos[t]; j++) {
                ans=min(ans,dis[b[s][i]][b[t][j]]+w[s]+w[t]+c[s][pos[i]]+c[t][pos[j]]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
