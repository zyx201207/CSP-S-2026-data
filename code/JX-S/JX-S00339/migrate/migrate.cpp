#include <bits/stdc++.h>
#define ll long long 
#define ull unsigned long long 
#define i128 __int128
#define fi first
#define se second
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define INF 0x3f3f3f3f
#define INFx 0x3f3f3f3f3f3f3f3f
using namespace std;

const int N = 2e6 + 10;

int n;
ll d;
ll x[N];
int nxt[N];

int f[5010][5010];

// sub1 n <= 300

int dis[310], cnt[310], vis[310];

void solve1() {
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        for (int j = i; j <= n; j++) {
            dis[j] = INF, cnt[j] = 0, vis[j] = 0;
        }
        dis[i] = 0, cnt[i] = 1; q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int j = u + 1; j <= nxt[u]; j++) {
                if (dis[j] > dis[u] + 1) {
                    dis[j] = dis[u] + 1, cnt[j] = cnt[u]; q.push(j);
                }
                else if (dis[j] == dis[u] + 1) cnt[j] += cnt[u];
            }
        }
        for (int j = i; j <= n; j++) {
            cnt[j] = min(cnt[j], 3);
            ans += cnt[j] == 2;
        }
    }
    cout << ans << '\n';
}

int g[N], sg[N];

void solve2() {
    for (int j = 0; j <= n; j++) sg[j] = g[j] = 0;

    g[1] = 1;
    int j = 1, lstj = -1;
    while (j != n && j != nxt[j]) {
        if (j != 1) {
            for (int k = j + 1; k <= nxt[j]; k++) {
                for (int p = 0; p <= min(2, j - lstj - 1); p++) {
                    if (nxt[j - p] < k || !g[j - p]) break; 
                    g[k] = min(g[k] + g[j - p], 3);
                    if (g[k] == 3) break;
                }
            }
        }
        else {
            for (int k = j; k <= nxt[j]; k++) g[k] = 1;
        }
        lstj = j, j = nxt[j];
    }

    sg[0] = 0;
    for (int j = 2; j <= n; j++) {
        sg[j - 1] = sg[j - 2] + (g[j] == 2);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += sg[n - i];

    cout << ans << '\n';
}

void solve() {
    cin >> n >> d;

    bool flag1 = true;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        if (i >= 3 && x[i] - x[i - 1] != x[i - 1] - x[i - 2]) flag1 = false;
    }

    nxt[n] = n;
    for (int i = n - 1; i >= 1; i--) {
        nxt[i] = nxt[i + 1];
        while (x[nxt[i]] - x[i] > d) nxt[i]--;
    }

    if (flag1) {solve2(); return;}

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) f[i][j] = 0;
    }

    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        f[i][i] = 1;
        int j = i, lstj = -1;
        while (j != n && j != nxt[j]) {
            if (j != i) {
                for (int k = j + 1; k <= nxt[j]; k++) {
                    for (int p = 0; p <= min(2, j - lstj - 1); p++) {
                        if (nxt[j - p] < k || !f[i][j - p]) break; 
                        f[i][k] = min(f[i][k] + f[i][j - p], 3);
                        if (f[i][k] == 3) break;
                    }
                    ans += (f[i][k] == 2);
                }
            }
            else {
                for (int k = j; k <= nxt[j]; k++) f[i][k] = 1;
            }
            lstj = j, j = nxt[j];
        }
    }

    cout << ans << '\n';
}

int main() {
    freopen("migrate.in", "r", stdin); // modify!!!
    freopen("migrate.out", "w", stdout); // modify!!!
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    int c, T;
    cin >> c >> T;
    while (T--) solve();

    return 0;
}