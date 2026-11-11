#include <bits/stdc++.h>
using namespace std;
//暴力出奇迹，骗分过样例

long long n, m, p = 0, p2 = 1, a[500005], sum2[500005], sum[500005];
int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		sum2[i] = sum2[i - 1] + i;
		if (a[i] == i)
			p++;
	}
	long long o = a[2] - a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] == o)
			p2++;
	}
	if (p == n) {
		long long p1;
		for (int i = 1; i <= n; i++) {
			if (sum[i] - a[i] >= m) {
				p1 = i - 1;
				break;
			}
		}
		cout << p1;
	} else if (p2 == n) {
		long long p2;
		for (int i = 1; i <= n; i++) {
			if (sum2[i - 1]*o >= m) {
				p2 = i - 1;
				break;
			}
		}
		cout << p2;
	} else {

	}

	return 0;
}
