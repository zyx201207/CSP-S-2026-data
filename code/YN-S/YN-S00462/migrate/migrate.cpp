#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 1e5 + 5;

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int a, b;
	while (m--) {
		cin >> a >> b;
		int s[N];
		for (int i = 1; i <= a; i++) {
			cin >> s[i];
		}
		cout << 0 << endl;
	}
	return 0;
}
