#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, q;
int w[N], k[505], a[505][N], t[505][N], x, y;
int s[20005][505], cnt[N];
vector <int> g[N];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++){
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++){
            cin >> a[i][j] >> t[i][j];
            s[a[i][j]][cnt[a[i][j]]] = i;
        }
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= cnt[i]; j++)
            for (int r = j + 1; r <= cnt[i]; r++){
                g[s[i][j]].push_back(s[i][r]);
                g[s[i][r]].push_back(s[i][j]);
            }
    while (q--){
        cin >> x >> y;
        cout << w[x] + w[y];
    }
    return 0;
}
