#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",out);
	int n;
	cin >> n;
	long long a[n];
	string s[n];
	long long z = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> s[i];
		z += a[i];
	}
	string c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++) {
			c += s[i];
		}
	}
	if (z % 2 == 0) {
		long long half = z / 2;
		string qb[half], hb[half];
		for (long long i = 0; i < half; i++) {
			qb[i] = c[i];
		}
		for (long long i = z; i > half; i--) {
			hb[z - i] = c[i];
		}
		for (long long i = 0; i < half; i++) {
			if (qb[i] != hb[i]) {
				cnt++;
			}
		}
		long long ls = half - cnt;
		if (ls > cnt && ls != 0) {
			cout << cnt;
		}
		if (ls < cnt && ls != 0) {
			cout << ls;
		}
		if (cnt == 0) {
			cout << cnt;
		} else {
			cout << cnt;
		}
	} else {
		long long half = (z - 1) / 2;
		string qb[half], hb[half];
		for (long long i = 0; i < half; i++) {
			qb[i] = c[i];
		}
		for (long long i = z; i > half; i--) {
			hb[z - i] = c[i];
		}
		for (long long i = 0; i < half; i++) {
			if (qb[i] != hb[i]) {
				cnt++;
			}
		}
		long long ls = half - cnt;
		if (ls > cnt && ls != 0) {
			cout << cnt;
		}
		if (ls < cnt && ls != 0) {
			cout << ls;
		}
		if (cnt == 0) {
			cout << cnt;
		} else {
			cout << cnt;
		}
	}
	return 0;
}