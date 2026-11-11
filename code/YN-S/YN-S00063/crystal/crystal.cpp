#include <bits/stdc++.h>
using namespace std;
long long a[500001];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long d = a[2] - a[1];
	long long t = 1;
	long long sum = 0;
	int ans = 1;
	for (int i = n - 1; i >= 1; i--) {
		if ((sum + t * d) > m) {
			break;
		} else {
			sum += t * d;
			t++;
			ans++;
		}
	}
	cout << ans;
	return 0;
}