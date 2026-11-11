#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 505, M = 2e4 + 5;
ll c, n, m, d, q;
ll w[N], k[N], a[N][M], t[N][M], x[M], y[M];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    for(int i = 1; i <= q; i++){
        cin >> x[i] >> y[i];
    }

    return 0;
}
