#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int len[N];
char c[N];
int main () {
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);
    int n; cin >> n;
    long long tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> len[i] >> c[i];
        tot += len[i];
    }
    int L = 1, R = n;
    long long res = 0;
    while (L < R) {
        int now = len[L];
        while (now > 0 && L < R) {
            if (c[R] == c[L]) {
                if (now > len[R]) now -= len[R], -- R;
                else len[R] -= now, now = 0;
            } else {
                if (now > len[R]) res += len[R], now -= len[R], -- R;
                else res += now, len[R] -= now, now = 0;
            }
        }
        ++ L;
    }
    cout << res << "\n";
    return 0;
}
