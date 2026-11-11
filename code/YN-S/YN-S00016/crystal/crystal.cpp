#include <iostream>
using namespace std;

int n, a[500005], cnt, m, a1[100005];
long long x;
int main() {
	freopen("crystal2.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		x += a[i];
		a1[a[i]]++;
	}

	x /= n;
	cnt += a1[x];
	for (int i = 1; m > 0; i++) {
		if (a[i] <= x && m - x + a[i] >= 0) {
			m = m - x + a[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}