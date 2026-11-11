#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2000024;
typedef long long ll;

int c, T, n, rea[N], tr[N], sx[N];
ll d, x[N], cm[N];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> T;
    while (T--) {
        ll ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        int lr = 0, ptr = 1;
        for (int i = 1; i <= n; i++) {
            while (ptr < n && x[ptr + 1] - x[i] <= d) ptr++;
            if (ptr == lr) tr[i] = tr[i - 1] + 1;
            else tr[i] = 1, lr = ptr;
            rea[i] = ptr;
        }
        sx[n] = cm[n] = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (tr[i] > 1) sx[i] = 0;
            else sx[i] = sx[rea[i]] + rea[i] - rea[i - 1];
            if (tr[rea[i]] > 2) cm[i] = 0;
            else {
                if (tr[rea[i]] == 2) cm[i] = sx[rea[rea[i]]];
                else cm[i] = cm[rea[i]];
                ans += cm[i];
                if (rea[rea[i] - 1] > rea[i]) {
                    ans += rea[rea[i] - 1] - max(rea[i], rea[rea[i] - 2]);
                    if (i > 1 && rea[i - 1] < rea[i] - 1) cm[i] += rea[rea[i] - 1] - max(rea[i], rea[rea[i] - 2]);
                }
            }
            if (tr[i] > 1) cm[i] = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}