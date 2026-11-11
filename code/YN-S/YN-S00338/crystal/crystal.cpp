#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
long long b[500005];
long long cnt[500005];
long long avr, sum, minb = INT_MAX, g;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	avr = sum / n;
	for (int i = 1; i <= n; i++) {
		b[i] = abs(a[i] - avr);
		minb = min(minb, b[i]);
	}
	g = avr + minb;
	for (int i = 1; i <= n; i++) {
		cnt[i] = a[i] - g;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] <= 0 && cnt[i] + m >= 0) {
			ans++;
			m += cnt[i];
		}
	}
	cout << ans;
	return 0;
}