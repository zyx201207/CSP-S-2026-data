#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;

int c, T, n;
long long d, ans, x[N], f[N], cnt[N], sum[N];

int main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> c >> T;
    while (T--) {
        cin >> n >> d, ans = 0;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        for (int i = 1; i < n; i++) {
            f[i] = 0, cnt[i] = 1, sum[i] = 1, sum[i - 1] = 0;
            for (int j = i + 1; j <= n; j++) {
                if (x[j] - x[j - 1] > d)
                    break;
                int L = i - 1, R = j - 1;
                while (L + 1 < R) {
                    int M = (L + R) >> 1;
                    if (x[j] - x[M] <= d)
                        R = M;
                    else
                        L = M;
                }
                int L2 = R, R2 = j;
                while (L2 + 1 < R2) {
                    int M = (L2 + R2) >> 1;
                    if (f[M] > f[R])
                        R2 = M;
                    else
                        L2 = M;
                }
                f[j] = f[R] + 1;
                cnt[j] = sum[L2] - sum[L], sum[j] = sum[j - 1] + cnt[j];
                if (cnt[j] == 2)
                    ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
