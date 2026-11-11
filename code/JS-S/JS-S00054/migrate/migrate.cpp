#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1000010;

int n, d, x[N];

void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}