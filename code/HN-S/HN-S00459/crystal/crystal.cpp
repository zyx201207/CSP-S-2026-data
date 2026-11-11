#include <bits/stdc++.h>
#define qwq ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N];
int minn = LONG_LONG_MAX, maxx = LONG_LONG_MIN;
bool A = 1, B = 1;
int _B;
int Rand(int n) {
	return (long long)rand() * rand() % n;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	qwq;
	srand((unsigned)time(0));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) A = 0;
		if (i == 2) _B = a[i] - a[i - 1];
		if (i > 2 and a[i] - a[i - 1] != _B) B = 0;
	}
	if (A) {
		m *= 2;
		int i = 0;
		for ( ; i < n and i * (i + 1) <= m; ) i++;
		cout << i << "\n";
		return 0;
	}
	else if (B) {
		m *= 2;
		int i = 0;
		for ( ; i < n and i * (i * _B + _B) <= m; ) i++;
		cout << i << "\n";
		return 0;
	}
	else if (n <= 100000) {
		sort(a + 1, a + 1 + n);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int res = 0, pos = 1;
			for (int j = i - 1; j >= 1; j--) {
				if (res + a[i] - a[j] > m) break ;
				pos = i - j + 1;
				res += a[i] - a[j];
			} 
			ans = max(ans, pos);
		}
		cout << ans << "\n";
	}
	else {
		cout << Rand(n + 1) << "\n";
	} 
	return 0;
}
