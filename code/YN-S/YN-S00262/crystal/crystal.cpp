#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

long long int a[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	long long int n, m;
	cin >> n >> m;

	long long sum = 0;

	for (long long int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	sum /= n;
//	cout << sum << endl;
	sort(a, a + n);
	long long int tmp;
	for (long long int i = n - 2; i >= 0; i--) {
		if (abs(a[i] - sum) <  abs(a[i + 1] - sum)) {
			tmp = i;
		}
	}
	long long ans = 1;
	long long l = tmp - 1, r = tmp + 1;

	bool l1 = 1, r1 = 1;
	while (m > 0) {
		if ((m -= abs(a[l] - a[l + 1]) >= 0) && ((!r1 || (abs(a[l] - a[l + 1]) < (abs(a[r] - a[r - 1]) * (r - l)))) && l1 )) {

			m -= abs(a[l] - a[l + 1]);
			a[l] = a[l + 1];
			ans++;
			if (l >= 0) {
				l--;
			} else {
				l1 = 0;
			}
		} else if (((m - (abs(a[r] - a[r - 1]) * (r - l))) >= 0) &&
		           (!l1 || ((abs(a[l] - a[l + 1]) >= (abs(a[r] - a[r - 1]) * (r - l))) && r1))   ) {
			m -= abs(a[r] - a[r - 1]) * (r - l);
			a[r - 1] = a[r];
			a[l] = a[r];
			ans++;
			if (r <= n) {
				r++;
			} else {
				r1 = 0;
			}
		}
		if ((!r1 && !l1) || ( r  >= n  && l <= 0)) {
			break;
		}
	}

	cout << ans << endl;
	return 0;
}



