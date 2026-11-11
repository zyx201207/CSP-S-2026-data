#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e6 + 10;

int tp, T, n, cnt[N][9], r[N], l[N], dis[N], c[N];
ll d, x[N];

void Solve() {
    cin >> n >> d, x[0] = -5e18;
    if (n <= 300) {
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            l[i] = lower_bound(x + 1, x + i + 1, x[i] - d) - x;
        }
        int ans = 0;
        for (int st = 1; st <= n; st++) {
            dis[st] = 0, c[st] = 1;
            for (int i = st + 1; i <= n; i++) {
                if (l[i] == i) break;
                dis[i] = dis[max(st, l[i])] + 1, c[i] = 0;
                for (int j = max(st, l[i]); j <= i; j++) {
                    if (dis[j] == dis[i] - 1) c[i] += c[j];
                    else break;
                }
                ans += c[i] == 2;
            }
        }
        cout << ans << '\n';
    } else {
        for (int i = 1; i <= n; i++) cin >> x[i];
        for (int i = 1; i <= n; i++) r[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x;

        ll ans = 0;
        for (int i = n, j = n; i >= 1; i--) {
            for (; j > i && x[j] - x[i] > d; j--);
            if (i == j) fill(cnt[i], cnt[i] + 9, 0);
            else if (i + 1 == j) {
                fill(cnt[i], cnt[i] + 9, 0);
                cnt[i][0] = cnt[j][0], cnt[i][1] = cnt[j][1] + 1, cnt[i][2] = cnt[j][2];
                if (x[j] - x[i - 1] <= d) {
                    if (i > 2 && x[j] - x[i - 2] <= d) {
                        cnt[i][3] = cnt[i][4] = cnt[i][5] = cnt[i][6] = cnt[i][7] = cnt[i][8] = cnt[i][9] = cnt[j][2];
                    } else {
                        cnt[i][3] = cnt[j][1] + 1;
                        cnt[i][4] = cnt[i][5] = cnt[i][6] = cnt[i][7] = cnt[i][8] = cnt[j][2];
                    }
                }
            } else {
                fill(cnt[i], cnt[i] + 9, 0);
                cnt[i][0] = cnt[j][3], cnt[i][1] = cnt[j][5] + j - i, cnt[i][2] = cnt[j][8];
                if (x[j] - x[i - 1] <= d) {
                    if (i > 2 && x[j] - x[i - 2] <= d) {
                        cnt[i][3] = cnt[i][4] = cnt[i][5] = cnt[i][6] = cnt[i][7] = cnt[i][8] = cnt[j][8];
                    } else {
                        cnt[i][3] = cnt[j][5] + j - r[i - 2] + 1;
                        cnt[i][4] = cnt[i][5] = cnt[i][6] = cnt[i][7] = cnt[i][8] = cnt[j][8];
                    }
                } else if (x[j - 1] - x[i - 1] <= d) {
                    if (i > 2 && x[j - 1] - x[i - 2] <= d) {
                        cnt[i][3] = cnt[j][6];
                        cnt[i][4] = cnt[j][6];
                        cnt[i][5] = cnt[j][7] + 1;
                        cnt[i][6] = cnt[j][6];
                        cnt[i][7] = cnt[j][7] + 1;
                        cnt[i][8] = cnt[j][8];
                    } else {
                        cnt[i][3] = cnt[j][4] + j - max(r[i - 2], i + 1);
                        cnt[i][4] = cnt[j][6];
                        cnt[i][5] = cnt[j][7] + 1;
                        cnt[i][6] = cnt[j][6];
                        cnt[i][7] = cnt[j][7] + 1;
                        cnt[i][8] = cnt[j][8];
                    }
                } else {
                    cnt[i][3] = cnt[j][3] + max(0, r[i - 1] - max(i, r[i - 2]));
                    cnt[i][4] = cnt[j][3];
                    cnt[i][5] = cnt[j][5] + j - max(i + 1, r[i - 1]) + 1;
                    cnt[i][6] = cnt[j][3];
                    cnt[i][7] = cnt[j][5] + j - max(i + 1, r[i - 1]) + 1;
                    cnt[i][8] = cnt[j][8];
                }
            }
            ans += cnt[i][0];
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> tp >> T;
    while (T--) Solve();
    return 0;
}
