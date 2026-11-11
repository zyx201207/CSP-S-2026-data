#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long m, mm;
long long a[500001], b[500001];

int j, ans;

int l, r;
long long res;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		b[i] = a[i] - a[i - 1];
	}
	
	l = 1;
	r = 1;
	while (l <= r && r <= n) {
		if (res <= m) {
			ans = max(r - l + 1, ans);
			++r;
			res += b[r] * (r - l);
		} else {
			++l;
			res -= a[r] - a[l - 1];
		}
	}
	cout << ans;
	return 0;
}
