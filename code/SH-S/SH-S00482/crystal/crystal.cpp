#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005], sum[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		sum[i] = (long long)((a[i] - a[i - 1]) * (i - 1) + sum[i - 1]);
	}
	for (int i = n; i >= 1; i--) {
		if (sum[i] <= m) {
			cout << i;
			break;
		}
	}
	return 0; 
}
