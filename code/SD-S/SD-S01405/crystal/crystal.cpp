#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 5E5 + 10;

int n;
i64 m;
i64 a[N], b[N];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; i ++)
		b[i] = a[i] + b[i - 1];
	int res = 0;
	for (int i = 1; i <= n; i ++) {
		int lo = 1, ro = i;
		while (lo <= ro) {
			int mid = lo + ro >> 1;
			if (a[i] * (i - mid + 1) - (b[i] - b[mid - 1]) <= m) ro = mid - 1;
			else lo = mid + 1;
		}
		res = max(res, i - ro);
	}
	
	cout << res << '\n';
	
	return 0;
}

