#include <bits/stdc++.h>
using namespace std;
int a[100005];
long long n, m;
long long ans = 2147483647;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, greater<int>());
	for (int i = 1; i <= m; i++) {
		ans &= a[i];
	}
	cout << ans;
	return 0;
}