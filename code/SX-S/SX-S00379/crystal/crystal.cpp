#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long sum = 0;
long long cnt = 0;
long long ma = INT_MIN;
long long mj = 0;
long long a[1000005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	long long ant = m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long z = 1;
	for (int j = 2; j <= n; j++) {
		long long x = a[j] - a[z];
		if (x == 0)
			cnt = cnt - 1;
		if (ant - x >= 0) {
			ant = ant - x;
			cnt += x;
			sum++;
		} else if (ant - x < 0) {
			break;
		}
		cnt = cnt + mj;
		if (sum > ma) {
			ma = sum;
			mj = cnt;
		}
		z++;
		cnt = 0;
	}
	cout << mj;
	return 0;
}

