#include <bits/stdc++.h>
using namespace std;

using i32 = int; using i64 = long long;

#define For(i, l, r) for (i32 i = (l); i <= (r); i++)
#define Fep(i, l, r) for (i32 i = (l); i >= (r); i--)

const i32 N = 1 << 22;
const i32 M = 22;

i32 nex[N][M];
i32 sum[N][M];

i32 nxt[N][M];
i32 cnt[N][M];

i32 n, R[N];
i64 d, x[N];

i64 ans = 0;

inline void solve() {
	cin >> n >> d; ans = 0;
	For (i, 1, n) cin >> x[i]; x[0] = -3e18;

	For (i, 1, n + 1) {
		nex[i][0] = sum[i][0] = nex[i + n][0] = sum[i + n][0] = 0;
		nxt[i][0] = cnt[i][0] = 0;
	}

	for (i32 i = n, j = n; i >= 1; i--) {
		while (x[j] - x[i] > d) j--;
		R[i] = j;
	}

	// cout << "R:-------------------\n";
	// For (i, 1, n) cout << R[i] << " \n"[i == n];

	nex[n * 2 + 1][0] = n * 2 + 1;
	nxt[n + 1][0] = n + 1;


	For (i, 1, n) {
		if (R[i] == R[i - 1]) nex[i][0] = nex[i + n][0] = n * 2 + 1;
		else {
			nex[i][0] = nex[i + n][0] = (R[i - 1] + 1 == R[i]) ? (R[i] + n) : (R[i]);
			sum[i][0] = max(R[i - 1], i) - max(R[i - 2], i);
			sum[i + n][0] = 0;
		}

		if (R[i] == R[i - 1]) nxt[i][0] = n + 1, cnt[i][0] = 0;
		else nxt[i][0] = R[i], cnt[i][0] = R[i] - max(R[i - 1], i);
	}

	// cout << "(nex, sum):--------------\n";
	// For (i, 1, n) cout << "(" << nex[i][0] << ' ' << sum[i][0] << ") "; cout <<'\n';
	// For (i, 1, n) cout << "(" << nex[i + n][0] << ' ' << sum[i + n][0] << ") "; cout <<'\n';

	// cout << "nxt:----------------\n";
	// For (i, 1, n) cout << "(" << nxt[i][0] << ' ' << cnt[i][0] << ") "; cout << '\n';

	For (j, 1, 21) For (i, 1, 2 * n + 1) {
		nex[i][j] = nex[nex[i][j - 1]][j - 1];
		sum[i][j] = sum[i][j - 1] + sum[nex[i][j - 1]][j - 1];
		
		nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
		cnt[i][j] = cnt[i][j - 1] + cnt[nxt[i][j - 1]][j - 1];
	}

	For (u, 1, n) {
		// if (u > 1) continue;					//modify

		i32 p = R[u]; if (p == u) continue;
		i32 s = 0;
		Fep (j, 21, 0) if (nex[p][j] <= n * 2) {
			s += sum[p][j], p = nex[p][j];
		}

		// cout << s << ' ' << p << endl;
		
		i32 v = (p - 1) % n + 1, chk = p > n;
		if (R[v] == v) { ans += s; continue; }	//跳不了了，否则说明R[v] == R[v - 1]
		//现在，若到R[v]的方案>2，则直接ans+=s
		//否则，一直跳直到，下一次R[p]=R[p-1]

		i32 q = R[v];
		if (chk || R[v - 2] == R[v - 1]) { ans += s; continue; }
		
		s += R[v - 1] - max(R[v - 2], v);				//Because chk = 0
		// cout << s << endl;

		Fep (j, 21, 0) if (nxt[q][j] <= n) {
			s += cnt[q][j], q = nxt[q][j];
		}

		ans += s;
	}

	cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(), cin.tie(), cout.tie();
	
	i32 c, t; cin >> c >> t;
	while (t--) solve();

	return 0;
}