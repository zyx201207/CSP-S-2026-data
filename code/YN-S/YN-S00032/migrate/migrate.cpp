#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2014514;
ll n, d, ans;
ll a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i < n; i++)
			for (int j = i + 2; j <= n; j++) {
				if ((a[j] - a[i] + 1) == d * 2)
					ans++;
			}
		cout << ans << "\n";
	}
	return 0;
}
