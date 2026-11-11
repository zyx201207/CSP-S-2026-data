#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5;
long long f[M];
long long a[M];
long long ans[M];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		f[i] = a[i] - a[i - 1];

//		cout << f[i] << " ";
	}
//	cout << endl;
	for (int i = 2; i <= n; i++)
		ans[n] += f[i] * (i - 1);
	for (int i = n - 1; i >= 1; i--)
		ans[i] = ans[i + 1] - f[i + 1] * i;
	for (int i = 1; i <= n; i++)

//		cout << ans[i] << " ";
		ans[1] = 0;
	if (m >= ans[n]) {
		cout << n;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		if (ans[i] > m) {
			cout << i - 1;
			break;
		}
	}
	return 0;
}
