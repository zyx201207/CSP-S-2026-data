#include <bits/stdc++.h>
using namespace std;
#define int long long

// --------------------------------------------------------------------------- Global variable
const int N = 5e5 + 2;
int n, m, a[N], s[N];

// --------------------------------------------------------------------------- Input
void Input() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
}

// --------------------------------------------------------------------------- Solve
int cost(int l, int r, int i) {
	return (s[r] - s[i] - (r - i) * a[i]) + ((i - l) * a[i] - (s[i - 1] - s[l - 1]));
}

void Solve() {
	int l = 1, ans = 0;
	for (int r = 1; r <= n; ++r) {
		while (cost(l, r, r) > m) ++l;
		ans = max(ans, r - l + 1);
	}
	cout << ans;
}

// --------------------------------------------------------------------------- Main function
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	Input(); Solve();
	
	return 0;
}