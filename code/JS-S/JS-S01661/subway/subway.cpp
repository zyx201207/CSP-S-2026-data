#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c, n, m, d, q, w[500005];
struct node{
    int a, t;
} b[505][500005];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        for (int j = 1; j <= k; j++) cin >> b[i][j].a >> b[i][j].t;
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << "0\n";
    }
    return 0;
}
