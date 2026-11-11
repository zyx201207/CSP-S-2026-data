#include <bits/stdc++.h>

#define int long long

using namespace std;

const int kMaxN = 5e5 + 5;

int n, m, a[kMaxN], ans, s[kMaxN];

signed main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if ((i - mid + 1) * a[i] - (s[i] - s[mid - 1]) > m) l = mid + 1;
			else r = mid - 1;
		}
		ans = max(ans, i - l + 1);
  }
	cout << ans;
  return 0;
}
// cutecutezrr
// only feels like nothing could be better when I'm with you