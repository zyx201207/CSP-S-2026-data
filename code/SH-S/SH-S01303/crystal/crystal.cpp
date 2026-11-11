#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
using i64 = long long;
inline void optimizeIO(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
}
bool mem_beg;
i64 n, m, a[N], s[N];
bool mem_end;
int main(void) {
    int ans = 0;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    optimizeIO(), cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
        int L = 1, R = i, mid;
        while (L < R) {
            mid = (L + R + 1) >> 1;
            if (a[i] * mid - s[i] + s[i - mid] <= m) {
                L = mid;
            } else {
                R = mid - 1;
            }
        }
        ans = max(ans, L);
    }
    cout << ans << endl;
	return 0;
}
