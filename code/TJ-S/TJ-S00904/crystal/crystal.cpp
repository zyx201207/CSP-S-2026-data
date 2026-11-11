//
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define N 500005

ll n, m, a[N], s[N], ans = -114514;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, idx;
		while (l <= r) {
			int mid = (l + r) / 2;
			ll x = a[i] * (i - mid + 1) - (s[i] - s[mid - 1]);
			if (x <= m) idx = mid, r = mid - 1;	
			else l = mid + 1;
		}
		ans = max(ans, (ll)(i - idx + 1));
	}
	cout << ans;
	return 0;
}
