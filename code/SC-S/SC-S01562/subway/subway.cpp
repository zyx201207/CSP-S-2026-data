#include <bits/stdc++.h>

using namespace std;

const int Maxn = 505; // lines
const int Maxm = 5e4 + 5; // stations ***
const long long Inf = 0x1e1e1e1e1e1e1e1e;

long long c, n, m, d, q;
long long minDst[Maxn][Maxn];
long long h[Maxn][Maxn];
long long stp[Maxm][Maxn]; // Station to platform
long long ets[Maxm]; // Exit to station

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q;
	// n: line, m: station
	memset(h, 0x1e, sizeof(h));
	memset(stp, 0x1e, sizeof(stp));
	memset(minDst, 0x1e, sizeof(minDst));
		
	for (int i = 1; i <= m; i++)
		cin >> ets[i];
	for (int i = 1; i <= n; i++) {
		long long k; cin >> k;
		for (int j = 1; j <= k; j++) {
			long long a, t; cin >> a >> t;
			stp[a][i] = t;
		}
	}
	
	for (int i = 1; i <= n; i++)
		minDst[i][i] = 0;
	
	for (int i = 1; i <= m; i++) {
		for (int a = 1; a <= n; a++) {
			if (stp[i][a] == Inf) continue;
			for (int b = 1; b <= n; b++) {
				if (a == b || stp[i][b] == Inf) continue;
				if (stp[i][a] + stp[i][b] < minDst[a][b]) {
					minDst[a][b] = minDst[b][a] = stp[i][a] + stp[i][b];
					h[a][b] = h[b][a] = i;
				}
			}
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i != k) for (int j = 1; j <= n; j++) {
				if (i != j && j != k && h[i][k] != Inf && h[j][k] != Inf)
					minDst[i][j] = minDst[j][i] = min(minDst[i][j],
						stp[h[i][k]][i] + stp[h[i][k]][k] +
						stp[h[j][k]][j] + stp[h[j][k]][k]);
				if (i != j && j != k &&
					minDst[i][k] != Inf && minDst[j][k] != Inf)
						minDst[i][j] = minDst[j][i] = min(minDst[i][j],
						minDst[i][k] + minDst[j][k]);
			}
		}
	}
	
	while (q--) {
		long long x, y; cin >> x >> y;
		long long ans = Inf;
		for (int i = 1; i <= n; i++) {
			if (stp[x][i] == Inf) continue;
			for (int j = 1; j <= n; j++) {
				if (stp[y][j] == Inf) continue;
				ans = min(ans, stp[x][i] + stp[y][j] + minDst[i][j]);
			}
		}
		ans += ets[x]; ans += ets[y];
		cout << ans << endl;
	}
	
	return 0;
}