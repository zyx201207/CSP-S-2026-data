#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
long long n, m;
bool check(long long len) {
	for (long long l = 0; l <= n - len; l++) {
		long long r = l + len - 1;
		long long tmp = 0;
		for (long long i = l; i <= r; i++) {
			tmp += a[r] - a[i];
		}
		if (tmp <= m) {
			return true; 
		}
	}
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	a.resize(n);
	for (long long i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	long long l = 0, r = n;
	while (l <= r) {
		long long mid = l + (r - l) / 2;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
