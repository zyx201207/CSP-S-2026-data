#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
ll n, m, a[maxn], ans;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)

		cin >> a[i];
	sort(a + 1, a + n + 1);
	ll j = n;

	for (int i = 1; i < m; i++) {

		ans = a[j] & a[j - 1];
		j--;
	}

	cout << ans;
	return 0;
}
