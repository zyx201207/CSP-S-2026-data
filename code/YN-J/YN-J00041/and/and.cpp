#include <bits/stdc++.h>
using namespace std;
int n, m;
typedef long long ll;
const int MAXN = 2e5 + 10;
ll a[MAXN];

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	ll ans = a[1];
	for (int i = 2; i <= m; i++) {
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}