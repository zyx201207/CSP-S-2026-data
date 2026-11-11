#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 10;
ll n, m, a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int Id, T;
	cin >> Id >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		cout << n << '\n';
	}
	return 0;
}
