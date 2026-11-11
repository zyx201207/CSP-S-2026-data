#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int ans = 0;
int minn = 10000;
int p;
long long n, m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sum /= n;
	for (int i = 1; i <= n; i++) {
		b[i] = abs(a[i] - sum);
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] <= minn) {
			minn = b[i];
			p = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (minn <= m) {
			ans++;
			m -= minn;
			b[p] = 100000;
			minn = 100000;
			for (int j = 1; j <= n; j++) {
				if (b[j] <= minn) {
					minn = b[j];
					p = j;
				}
			}
		} else {
			cout << ans;
			return 0;
		}
	}
	cout << ans;
	return 0;
}