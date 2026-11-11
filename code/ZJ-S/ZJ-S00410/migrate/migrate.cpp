#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
const int N = 2e6 + 5;
const int inf = 0x3f3f3f3f;

int c, T;
ll n, D, x[N];

int d[N], cnt[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> D;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cnt[j] = 0, d[j] = inf;
			}
			for (int j = 1; j <= i; j++) {
				d[j] = 0;
			}
			cnt[i] = 1;
			for (int j = i + 1; j <= n; j++) {
				auto it = lb(x + 1, x + 1 + n, x[j] - D);
				int pos = max(1ll * i, it - x);
				if (pos == j) {
					break;
				}
				for (int k = pos; k < j; k++) {
					if (d[k] > d[pos]) {
						break;
					}
					cnt[j] += cnt[k];
				}
				d[j] = d[pos] + 1;
				ans += (cnt[j] == 2);
			}
		}
		cout << ans << endl;
	}
	return 0;
} // wzHzm 4:10 24pts
