#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; i++)
int n, d, a[2000005];
int f[2000005], g[2000005], r[2000005], sm[2000005];
void solve() {
	cin >> n >> d;
	rep(i, 1, n) cin >> a[i];
	int l, ans = 0;
	rep(s, 1, n) {
		l = s;
		f[s] = 1, g[s] = 0, sm[s] = 1, r[0] = s, sm[s - 1] = 0;
		int last = 0;
		rep(i, s + 1, n) {
			while(a[i] - a[l] > d) l++;
			if(i != l) g[i] = g[l] + 1;
			else break;
			if(g[i] != g[i - 1]) r[last++] = i - 1;
			f[i] = sm[r[g[l]]] - sm[l - 1];
			sm[i] = sm[i - 1] + f[i];
			if(f[i] == 2) ans++;
		}
	}
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
