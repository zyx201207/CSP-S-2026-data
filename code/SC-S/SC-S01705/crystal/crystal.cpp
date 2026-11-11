#include<bits/stdc++.h>
using namespace std;
long long a[500001], b[500001];
long long n, m;
long long go(long long int x) {
	long long int minx;
	for (long long int i = x; i <= n; i++)
		if (i == x)
			minx = a[i] * x - b[i] + b[i - x - 1];
		else
			minx = min(a[i] * x - b[i] + b[i - x - 1], minx);
	return minx;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i];
	long long int l = 1, r = n;
	while (r >= l) {
		long long mid = (l + r) / 2;
		if (go(mid) > m)r = mid - 1;
		else l = mid + 1;
	}
	cout << r;
}//J:100+60+80+40=280
//hoping S 100+20=120
//jshuzudounengkaixiaozhengfuleqwq