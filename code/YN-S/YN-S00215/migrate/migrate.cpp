#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
#define ll long long
struct node {
	ll sum;
	int fi;
} a[N];
int c, t, n, point;
ll d, x[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		ll ans = 0;
		point = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		for (int i = 1; i <= n; i++) {
			point = 0;
			for (int j = i; j <= n; j++) {
				if (x[j] - x[j - 1] > d)
					break;
				if (!point)
					point++, a[point].fi = j;
				else if (x[j] - x[j - 1] + a[point].sum <= d) {
					a[point].sum += (x[j] - x[j - 1]), a[point].fi = j;
				} else {
					point++, a[point].sum += (x[j] - x[j - 1]), a[point].fi = j;
				}
				if (point <= 1)
					continue;
				int temp = 1;
				if (a[point].sum + x[a[point - 1].fi] <= d)
					temp++;
				else continue;
				if (a[point - 1].fi - a[point - 2].fi >= 2)
					if (a[point].sum + x[a[point - 1].fi] + x[a[point - 1].fi - 1] <= d)
						temp++;
				if (point >= 2)
					if (a[point - 1].sum - x[a[point - 1].fi] + x[a[point - 2].fi] <= d)
						temp++;
				if (temp == 2)
					ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
