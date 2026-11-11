#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 5;
ll n, m, ans1 = 0;
ll a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ans1 = max(ans1, a[i]);
	}
	if (m == 1) {
		cout << ans1;
		return 0;
	}
	return 0;
}