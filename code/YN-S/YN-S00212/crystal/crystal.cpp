#include <bits/stdc++.h>
using namespace std;
long long cnt = 0;
long long pj = 0;

long long mincha[5000005] = {INT_MAX};


int main() {
	freopen("srystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long a[n + 5];
	for (long long i = 1; i < n; i++) {
		cin >> a[i];
		pj += a[i];
	}
	bool flag[5000005] = {false};
	pj = ceil(pj * 1.0 / n);
	sort(a + 1, a + n + 1);
	long long tempm = m;
	for (int i = 1; i <= tempm; i++) {
		for (int j = 1; j <= n; j++) {
			long long cha = a[j] - a[j - 1];
			mincha[j] = min(mincha[j - 1], cha);
			if (a[j - 1] != a[j]) {
				if (m - cha < 0) {
					break;
				}
				a[j - 1] += mincha[j];
				m -= mincha[j];
				cnt++;

			}
			tempm = m;
//			cout << tempm << endl;
		}
//		if (flag[i]) {
//			break;
//		}
	}
	cout << cnt;
	return 0;
}