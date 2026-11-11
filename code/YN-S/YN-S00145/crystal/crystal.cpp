#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(".in", "r", stdin);
	freopen("out", "w", stdout);
	long long n, k, a[100005];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long x = a[n / 2], num = 0;
	for (int i = 1; i <= n; i++) {
		if (num - a[i] == 0) {
			cout << num;
			break;
		} else {
			num++;
			x -= a[i];
		}
	}
	return 0;
}
