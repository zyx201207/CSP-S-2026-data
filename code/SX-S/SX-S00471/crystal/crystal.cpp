#include <bits/stdc++.h>
using namespace std;

bool cmp(long long i, long long j) {
	return i > j;
}
long long n, m;
long long maxx = 0;
vector<long long> a;
vector<long long> b;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	a.resize(n + 1, 0);
	b.resize(n + 1, 0);
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a.begin() + 1, a.begin() + n + 1, cmp);
	for (long long i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[1] - a[i];
		//cout << b[i] << ' ';
	}
	for (long long i = 1; i <= n; i++) {
		long long l = i, r = n;
		while (l < r) {
			long long mid = ceil((l + r) / 2.0);
			if (b[mid] - b[i] - (mid - i) * (a[1] - a[i]) <= m) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		maxx = max(maxx, l - i + 1);
	}
	cout << maxx  ;
	return 0;
}
