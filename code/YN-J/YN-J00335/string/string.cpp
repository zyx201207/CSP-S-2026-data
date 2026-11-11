#include <bits/stdc++.h>
using namespace std;
char a[200000];
long long p[200000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	long long num = 0;

	for (int i = 0; i < n; i++) {

		cin >> p [i] >> a[i];
		num += p[i];
	}

	int l = 0, r = n - 1;
	long long le = 0, re = 0;
	long long cnt = 0;
	int y = p[l], x = p[r];

	while ( r != l && le < (num / 2 + num % 2 ) && re < ( num / 2 + num % 2)) {
		if (a[r] != a[l]) {
			cnt += min(y, x);
		}

		le += min(y, x);
		re += min(y, x);
		y -= min(y, x);
		x -= min(y, x);

		if (y  == 0) {
			l++;
			y = p[l];
		}

		if (x == 0) {
			r--;
			x = p[r] ;
		}
	}

	cout << cnt;
	return 0;
}