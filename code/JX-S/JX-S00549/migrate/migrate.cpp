#include<bits/stdc++.h>
using namespace std;
int c, t, n, d, x[2000005], cnt, ans;
void dfs(int u, int v, int mi, int now, int num) {
    if (num > mi) {
        return;
    }
    if (now == v && num == mi) {
        cnt++;
        return;
    }
    if (now == v) {
        return;
    }
    for (int i = now + 1; i <= v; i++) {
        if (x[i] - x[now] <= d) {
            dfs(u, v, mi, i, num + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        if (n <= 500) {
            for (int i = 1; i <= n; i++) {
                for (int j = i + 3; j <= n; j++) {
                    int mi = 0;
                    for (int k = i; k <= j;) {
                        if (mi == 1e9) {
                            break;
                        }
                        if (x[j] - x[k] <= d) {
                            mi++;
                            break;
                        }
                        for (int l = k + 1; l <= j; l++) {
                            if (x[l] - x[k] >= d) {
                                if (l - k <= 1) {
                                    mi = 1e9;
                                    break;
                                }
                                mi++;
                                k = l - 1;
                                break;
                            }
                        }
                    }
                    if (mi == 1e9) {
                        continue;
                    }
                    cnt = 0;
                    dfs(i, j, mi, i, 0);
                    if (cnt == 2) {
                        ans++;
                    }
                }
            }
            cout << ans << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
    return 0;
}
