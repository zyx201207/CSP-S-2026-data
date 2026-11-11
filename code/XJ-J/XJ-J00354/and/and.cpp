#include <bits/stdc++.h>
using namespace std;

const int N = 2 *1e5 + 5;
long long n, m, a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	int maxn = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] > maxn) {
			maxn = a[i];
		}
	}
	int sum = a[1];
	for (int i = 2; i <= n; ++i) 
		sum = sum & a[i];
	
	if (m == 1) {
		cout << maxn;
		return 0;
	} else if (m == n) {
		cout << sum;
		return 0;
	} else if (m == 2){
		long long ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = i + 1; j <= n; ++j) {
				ans = max(ans, (a[i] & a[j]));
			}
		}
		cout << ans;
		return 0;
	} else {
		sort(a + 1, a + 1 + n, greater<long long>());
		int sum1 = a[1];
		for (int i = 2; i <= m; ++i) {
			sum1 = sum1 & a[i];
		}
		cout << sum1;
	}
	return 0;
}
