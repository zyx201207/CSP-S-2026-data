#include <bits/stdc++.h>
using namespace std;
long long sj[1000005], dsj[1000005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, sum = 1, bj = 0;
	cin >> n >> m;
	int flag = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> sj[i];
	}
	int sj111 = sj[1];
	for (long long i = 1; i <= n; i++) {
		if (sj[i] != sj111) {
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << n;
		return 0;
	}
	sort(sj + 1, sj + n + 1);
	for (long long x = 1; x <= n; x++) {
		dsj[x] = sj[x];
		long long p = 0, p1 = 0;
		long long qdsj = sj[x];
		while (m) {
			p++;
			if (dsj[x] < sj[x + 1]) {
				if (dsj[x] == sj[x]) {
					dsj[x] = dsj[x] + 1;
					qdsj = dsj[x];
					p1 = p;
				} else {
					dsj[x] = dsj[x] + 1;
					p = p + p1 - 1;
				}
			} else if (dsj[x] == sj[x + 1]) {
				sum++;
				break;
			}
		}
		m = m - p;
		if (m == 0) {
			break;
		}
	}
	long long sum1 = sum + 1;
	for (int i = sum1; i <= n; i++) {
		if (sj[sum1 - 1] == sj[i]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}