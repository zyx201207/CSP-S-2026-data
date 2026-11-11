#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500, M = 500007;

int c, n, m, d, q;
int w[M];
int k[N];
int a[N][M], t[N][M];
int x, y;
ll ans;

// struct node {
//     int n, m, t;
// };
// set<node> s[M];

bool vis[M];

// void dfs(int now, int last_n, int sum) {
//     for (auto i : s[now]) {
//         if (i.n == last_n)  dfs(a[i.n][s[i].m + 1], i.n, sum);
//     }
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j], t[i][j];
            // s[a[i][j]].insert({i, j, t[i][j]});
        }
    }

    // if (c >= 1 && c <= 3)
    while (q--) {
        cin >> x >> y;
        ans = ll(w[x] + w[y]);
        // dfs(x, 0, 0);
    }

    if (c == 20 || c == 21) {
    while (q--) {
        cin >> x >> y;
        ans = ll(w[x] + w[y]);
        // dfs(x, 0, 0);
    }

    int ax = -1, bx = -1, ay = -1, by = -1;
        for (int j = 1; j <= k[1]; j++) {
            if (a[1][j] == x) ax = j;
            if (a[1][j] == y) ay = j;
        }
        for (int j = 1; j <= k[1]; j++) {
            if (a[2][j] == x) bx = j;
            if (a[2][j] == y) by = j;
        }
        // if (s[x].size() = 2)
    
    if (ax == -1 && bx == -1)  cout << ans + t[1][ax] + t[1][ay];
    if (bx == -1 && bx == -1)  cout << ans + t[1][ax] + t[1][ay];
    }

    return 0;
}