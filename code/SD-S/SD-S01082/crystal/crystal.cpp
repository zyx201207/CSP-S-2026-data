#include <bits/stdc++.h>

using namespace std;


const int N = 5e5 + 10;


long long n, m, a[N];
long long c[N], ans, mx = -1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	long long x = a[2] - a[1];
	bool v = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] - a[i - 1] != x) {
			v = 0;
			break;
		}
	}
	if (v == 1) {
		for (int i = n; i >= 1; i--) {
			int s = a[n] - a[i];
			if (m - s >= 0) {
				ans++;
				m -= s;
			}
			else
				break;
		}
		cout << ans;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		long long s = m;
		for (int j = i; j >= 1; j--) {
			long long x = a[i] - a[j];
			if (s >= x) {
				s -= x;
				ans++;
			}
		}
		mx = max(ans, mx);
		ans = 0;
	}
	cout << mx;
	return 0; 
}
