#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp(Tx, Ty) make_pair(Tx, Ty)
#define For(Ti, Ta, Tb) for(auto Ti = (Ta); Ti <= (Tb); Ti++)
#define Dec(Ti, Ta, Tb) for(auto Ti = (Ta); Ti >= (Tb); Ti--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define range(Tx) begin(Tx),end(Tx)
typedef long long ll;
const int N = 2e6 + 5;
int n;
ll a[N], d;
int L[N], R[N];
int mp[N], mpr[N], Mp[N], Mpr[N];
int f[N], g[N];
int main() {
	assert(freopen("migrate.in", "r", stdin));
	assert(freopen("migrate.out", "w", stdout));
	cin.tie(nullptr)->sync_with_stdio(false);
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		For(i, 1, n) cin >> a[i];
		For(i, 1, n) mp[i] = n + 5, Mpr[i] = -1, L[i] = R[i] = 0, f[i] = g[i] = 0, Mp[i] = n + 5, mpr[i] = -1; 
		int l = 1;
		For(i, 1, n) {
			while (l < i && a[i] - a[l] > d) l++;
			L[i] = l;
			if (mp[L[i]] == n + 5) mp[L[i]] = i;
			mpr[L[i]] = i;
		}
		int r = n;
		Dec(i, n, 1) {
			while (r > i && a[r] - a[i] > d) r--;
			R[i] = r;
			if (Mpr[R[i]] == -1) Mpr[R[i]] = i;
			Mp[R[i]] = i;
		}
		For(i, 1, n) {
			if (R[L[i]] == i) f[i] = f[L[i]];
			f[i]++;
			int r1 = min(Mpr[i], i - 1), l1 = max(L[i] + 1, Mp[i]);
			f[i] += max(0, r1 - l1 + 1);
		}
		Dec(i, n, 1) {
			if (L[R[i]] == i) g[i] = g[R[i]];
			g[i]++;
			int r1 = min(mpr[i], R[i] - 1), l1 = max(i + 1, mp[i]);
			g[i] += max(0, r1 - l1 + 1);
		}
//		For(i, 1, n) cout << g[i] << ' ';
//		cout << '\n';
		ll ans = 0;
		For(i, 1, n) {
			int jp = R[i];
			if (jp <= i + 1) continue;
			int jp_ = jp - 1;
			if (L[jp_] == i) {
				int jp2 = R[jp_];
				if (jp2 <= jp) continue;
				if (L[jp2] != jp_) {
					assert(L[jp2] != jp);
					continue;
				}
				int w = max(jp + 1, mp[jp_]);
//				cout << i << ' ' << jp2 << '\n';
				if (R[jp] == jp2) {
					ll now = g[jp2] + max(0, jp2 - w);
					ans += 1ll * now * f[i];
				} else {
					ll now = max(0, jp2 - w + 1);
					ans += 1ll * now * f[i];
				}
//				cout << ans << '\n';
			} else {
				assert(L[jp_] < i);
				int jp2 = R[jp_];
				if (jp2 <= jp) continue;
				if (L[jp2] != jp_) continue;
				int w = max(jp + 1, mp[jp_]);
				if (R[jp] == jp2) {
					ll now = g[jp2] + max(0, jp2 - w);
					ans += now;
				} else {
					ll now = max(0, jp2 - w + 1);
					ans += now;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 1
6 3
1 2 4 6 7 8 
*/
