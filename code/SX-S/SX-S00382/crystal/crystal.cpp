#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];

bool qiu(long long mid) {
	long long s = 0;
	int f = 0;
	//cout << mid << endl;
	for (int i = 1; i <= n - mid + 1; i++) {
		s = 0;
		f = 0;
		//cout << i << endl;
		for (int j = i; j <= i + mid - 1; j++) {
			s += a[i + mid - 1] - a[j];
			if (s > m) {
				f = 1;
				break;
			}
			//cout << a[i + mid - 1] << " " << a[j] << endl;
		}
		if (s <= m && f == 0) {
			return 1;
		}
	}

	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	scanf("%d%ld", &n, &m);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	long long l = 1, r = n, mid;
	while (l <= r) {
		mid = (r - l) / 2 + l;
		if (qiu(mid) == 1) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << r  ;
	return 0;
}