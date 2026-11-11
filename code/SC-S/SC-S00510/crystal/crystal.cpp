#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

#define il inline
#define cstex constexpr
#define frer(filename) assert(freopen(filename, "r", stdin))
#define frew(filename) assert(freopen(filename, "w", stdout))

using ll = int64_t;

cstex int N = 5e5, XN = N + 10;
int n; ll m, a[XN], s[XN]; int ans;

int main() {
	frer("crystal.in"), frew("crystal.out");
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m; for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1); for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	return 0;
}
