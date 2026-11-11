// BLuemoon_
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 5e5 + 5;
const LL kP = 1e9 + 7;

LL T = 1, n, m, a[kMaxN], ans, s[kMaxN], L, R;

LL Chk(int i, int x) { return a[i] * (i - x + 1) - (s[i] - s[x - 1]); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        L = 1, R = i;
        for (LL mid = L + R >> 1; L < R; mid = L + R >> 1) {
            Chk(i, mid) <= m ? R = mid : L = mid + 1;
        }
        ans = max(ans, i - L + 1);
    }
    cout << ans << '\n';
    return 0;
}
// g++ crystal.cpp -o crystal -O2 -static -Wall && time ./crystal