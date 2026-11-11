#include <bits/stdc++.h>
#define N 2000005
#define ll long long
using namespace std;
int c, t;
int n;
ll m, xx[N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> xx[i];
	ll d = xx[2] - xx[1];
	m /= d;
	cout << n - m * 2 + 1 << endl;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--)
		solve();
	return 0;
}
