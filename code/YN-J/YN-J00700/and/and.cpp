#include <bits/stdc++.h>
using namespace std;
int a[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ans = INT_MIN;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (__gcd(a[i], a[j]) > ans) {
				ans = __gcd(a[i], a[j]);
			}
		}
	}
	cout << ans ;
	return 0;
}
