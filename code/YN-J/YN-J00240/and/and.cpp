#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int a[N];
long long n, m;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0, x;
	for (int i = 1; i <= n; i++) {
		int x = 0;
		for (int j = 1; j <= n; j++) {
			auto p = a[i] & a[j];
			for (int o = 1; o <= n; o++) {
				auto q = p & a[o];
				x = q;
			}
		}
		ans = max(ans, x);
	}
	cout << ans;
	return 0;
}