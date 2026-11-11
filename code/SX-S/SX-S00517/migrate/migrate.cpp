#include <bits/stdc++.h>

#define ll long long
#define i128 __int128
#define pb push_back
#define pq priority_queue
#define pii pair<int,int>
#define fi first
#define se second
#define In(x) freopen(x".in","r",stdin)
#define Out(x) freopen(x".out","w",stdout)
#define File(x) (In(x),Out(x))
using namespace std;
const int N = 2e6+5;
int n, nxt[N], f[N], g[N], h[N];
ll x[N], d, ans;

void solve() {
	cin >> n >> d, ans = 0, nxt[n] = n, nxt[0] = 0;
	for (int i = 1; i <= n; i++)
		f[i] = g[i] = h[i] = 0;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = n - 1; i >= 1; i--) {
		nxt[i] = nxt[i + 1];
		while (x[nxt[i]] - x[i] > d)
			nxt[i]--;
	}
	for (int i = n; i >= 2; i--) {
		if (nxt[i] == i)
			continue;
		if (nxt[i] == nxt[i - 1]) {
			if (nxt[i - 1] == nxt[i - 2]) {
				ans += g[nxt[i]] + h[nxt[i]];
				f[i] = 0;
				g[i] = 0;
				h[i] = 0;
			} else {
				ans += g[nxt[i]] + h[nxt[i]];
				f[i] = 0;
				h[i] += f[nxt[i]];
				h[i] += max(nxt[i - 1], i) - max(nxt[i - 2], i);
			}
		} else {
			ans += g[nxt[i]] + h[nxt[i]];
			f[i] += f[nxt[i]];
			f[i] += nxt[i] - max(nxt[i - 1], i);
			if (nxt[i - 1] != nxt[i] - 1 || nxt[i - 1] == i)
				g[i] += h[nxt[i]];
			g[i] += g[nxt[i]];
			h[i] += max(nxt[i - 1], i) - max(nxt[i - 2], i);
		}
//		cout << ans << endl;
	}
//	for (int i = 1; i <= n; i++)
//		cout << f[i] << ' ' << g[i] << ' ' << h[i] << ' ' << nxt[i] << endl;
	ans += g[nxt[1]] + h[nxt[1]];
	cout << ans << endl;
}

signed main() {
	File("migrate");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	signed c, T = 1;
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}

/*
0 1
8 19
20 28 37 42 54 62 62 81
0 1
12 22
9 13 26 33 36 42 50 57 72 80 94 96
0 1
12 28
8 14 23 26 47 48 54 61 70 76 81 92
0 1
8 24
34 42 49 61 68 81 89 100
fc /W migrate1.ans migrate1.out
fc /W migrate2.ans migrate2.out
fc /W migrate3.ans migrate3.out
fc /W migrate4.ans migrate4.out
fc /W migrate5.ans migrate5.out
fc /W migrate6.ans migrate6.out
*/
