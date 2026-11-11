#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::min;
using std::max;
using std::vector;

#define int long long
static constexpr int inf = (int)(1e16);

#define fst first
#define scd second
#define pr std::pair<int,int>
#define ep emplace
#define eb emplace_back

int testid;

int n, k, x;
void solve() {
	cin >> n >> k;
	for (int i = 1; i < n; i++)
		cin >> x >> x;
	if (k == n)
		cout << 0 << '\n';
	else if (k >= n / 2)
		cout << 1 << '\n';
	else
		cout << 2 << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	int n0;
	cin >> n0;
	while (n0--)
		solve();

	return 0;
}