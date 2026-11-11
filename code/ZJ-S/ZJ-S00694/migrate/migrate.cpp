#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;

int cas, T;
int vis[15][15];
int n, d, a[15], s[15][15];
void dg(int st, int x, int cnt) {
    if (s[st][x] > cnt) s[st][x] = cnt, vis[st][x] = 1;
    else if (s[st][x] == cnt) {
        vis[st][x]++;
        if (vis[st][x] >= 3) return;
    }
    for (int i = x + 1; i <= n && a[x] + d >= a[i]; i++)
        dg(st, i, cnt + 1);
}
void tp1() {
    while (T--) {
        int ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++)
                s[i][j] = 2e18+1, vis[i][j] = 0; 
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            dg(i, i, 0);
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (vis[i][j] == 2) ans++;
        cout << ans << '\n';
    }    
}
// void tpB() {
//     while (T--) {
//         cin >> n >> d;

//     }
// }

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> cas >> T;
    if (cas <= 2) tp1();
    // if (cas == 13 || cas == 14) tpB();
    return 0;
}