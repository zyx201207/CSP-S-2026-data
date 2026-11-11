#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, T, n, d, a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 1)
				cha[i] = a[i] - [i - 1];
		}
		if (d < cha[n])
			cout << "0";
		else
			cout << "2";
		cout << '\n';
	}
	return 0;
}