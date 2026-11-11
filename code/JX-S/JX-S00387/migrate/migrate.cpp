#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e6 + 5;

int c, t;
int n, d;
int x[MAX_N];
int minn, cnt;

void dfs (int u, int ed, int sum, int st) {
    if (u == ed) {
        //if (st == 1 && ed == 4) cout << sum << endl;
        if (sum <= minn) cnt++;
        if (cnt > 2) return;
    }
    if (cnt > 2 || sum > 2) return;
    for (int i = u + 1; i <= ed; i++) {
        if (x[i] - x[u] > d) break;
        dfs (i, ed, sum + 1, st);
    }
}

bool check (int a, int b) {
    minn = 1;
    for (int i = a, p = a; i <= b; i++) {
        if (x[i] - x[p] > d) {
            minn++;
            p = i - 1;
        }
    }
    cnt = 0;
    dfs (a, b, 0, a);
    if (cnt == 2) return true;
    else return false;
}

void solve () {
    cin >> n >> d;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        if (i >= 3 && x[i] - x[i - 1] != x[i - 1] - x[i - 2]) flag = 0;
    }

    int k = x[n] - x[n - 1];
    int ans = 0;
    if (n <= 9) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (check (i, j)) ans++;
            }
        }
    } else {
        if (k > d) ans = 0;
        else {
            int l = d / k;
            for (int i = 1; i < l; i++) {
                ans += n - (1 + l + i) + 1;
            }
        }
    }
    cout << ans << endl;
}
int main () {
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);

    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    cin >> c >> t;
    while (t--) solve ();
    return 0;
}
