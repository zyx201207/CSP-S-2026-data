#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2000005

int c, t, n, to[MAXN];
ll d, x[MAXN];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		int ans = 0;
		vector <vector <int> > v(n, vector<int>(n, 0));
		for (int i=1; i<=n; i++) cin >> x[i];
		for (int l=1, r=1; r<=n; r++) {
			to[r] = lower_bound(x+r+1, x+n+1, x[r]+d) - x;
			while (to[l] < r) l++;
			for (int i=l; i<r; i++)
				for (int j=r+1; j<=to[r]; j++) {
					v[j][i]++;
					if (v[j][i] == 2) ans++;
					if (v[j][i] == 3) ans--;
				}
		}
		cout << ans << '\n';
	}
	return 0;
}
