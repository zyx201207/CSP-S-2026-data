#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int N, a[200005], m = 0, ans = 0;
	char c[200005], b[200005];
	cin >> N;
	string s[20005];
	for (int i = 1; i <= N; i++) {
		cin >> a[i] >> c[i];
		if (c[i] == c[i - 1]) {
			m++;
		}
	}
	if (m == N - 1) {
		cout << 0 << endl;
		return 0;
	}
	m = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= a[i]; j++) {
			b[m] = c[i];
			m++;
		}
	}
	for (int i = 0; i <= m / 2; i++) {
		if (b[i] != b[m - i]) {
			ans += 1;
		}
	}
	cout << ans << endl;
	return 0;
}