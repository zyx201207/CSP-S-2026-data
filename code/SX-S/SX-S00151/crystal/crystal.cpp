#include <bits/stdc++.h>
using namespace std;
int n, m, a[5005], tong[100005], r, mmax = INT_MIN, mmax1 = INT_MIN, mmin = INT_MAX;

signed main() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tong[a[i]]++;
		mmin = min(a[i], mmin);
		mmax1 = max(a[i], mmax1);
	}
	for (int i = mmin; i <= mmax1; i++) {
		mmax = max(tong[i], mmax);
		cout << mmax << " ";
		if (tong[i] >= tong[i + 1])
			r = i;
		if (tong[i + 1] > tong[i])
			r = i + 1;
	}
	for (int i = r - 1; i > mmin; i--) {
		if (tong[i] == 0)
			continue;
		if (m > r - i) {
			while (tong[i]) {
				if (m > r - i) {
					mmax++;
					m -= r - i;
					tong[i]--;
				}
			}
		}
	}
	cout << mmax;
	return 0;
}