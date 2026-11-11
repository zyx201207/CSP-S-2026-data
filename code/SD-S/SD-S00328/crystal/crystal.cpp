#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
int n;
long long m;
long long a[MAXN];
__int128 s[MAXN];
int ans = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crysatl.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	s[0] = 0;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	for (int i = 1; i <= n; i++) {
		int pos = i;
		for (int j = 30; j >= 0; j--) {
			if (pos + (1 << j) <= n && s[pos + (1 << j)] - s[i - 1] - (i - 1) * (a[pos + (1 << j)] - a[i - 1]) <= m) pos += (1 << j);
		}
		ans = max(ans, pos - i + 1);
	}
	cout << ans << '\n';
}
