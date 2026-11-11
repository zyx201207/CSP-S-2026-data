#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 507, M = 500007;
const ll INF = 1e18;

int c, n, m, d, q;
ll w[M];
int k, a, b;
vector<int> s[N];
bool sta[N][M];
vector<int> tran[M];
int t[N][M];

ll ans = INF, def = 0;
void dfs(int from_l, int x, ll tim) {
    //cout << from_l << ' ' << x << ' ' << '\n';
    ll T = tim;
    if (from_l == 0) T += w[x];
    else T += t[x][from_l];
    if (x == def) {
        ans = min(ans, T + w[def]);
        return;
    }
    for (auto l : tran[x]) {
        if (l == from_l || !sta[l][def]) continue;
        dfs(l, def, T + t[x][l]);
    }
    for (auto l : tran[x]) {
        if (l == from_l || sta[l][def]) continue;
        for (auto it : s[l]) {
            if (tran[it].empty()) continue;
            dfs(l, it, T + t[x][l]);
        }
    }
    return;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> a >> b;
            sta[i][a] = 1;
            s[i].push_back(a);
            tran[a].push_back(i);
            t[a][i] = b;
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        ans = INF, def = y;
        dfs(0, x, 0);
        cout << ans << '\n';
    }
    return 0;
}
