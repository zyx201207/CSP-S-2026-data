#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000010
#define M 21
int x[N], nxt[N][M], p2[M], c, t, n, d;
void solveA() {
	while(t--) {
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		int dis = x[2] - x[1];
		if(d < 2 * dis) cout << 0 << "\n";
		else {
			cout << max(0ll, n - d / dis * 2 + 1) << "\n";
		}
	}
}
void solveB() {
	while(t--) {
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		for(int i = 1; i <= n; i++) {
			int l = i, r = n;
			while(l < r) {
				int mid = (l + r + 1) / 2;
				if(x[i] + d >= x[mid]) l = mid;
				else r = mid - 1;
			}
			nxt[i][0] = r;
		}
		for(int i = 1; i <= n; i++)
			if(nxt[i][0] >= 3) ans += nxt[nxt[i][0] - 1][0] - nxt[nxt[i][0] - 2][0];
		cout << ans << "\n";
	}
}
int dis(int l, int r) {
	int res = 0;
	for(int i = 20; i >= 0; i--)
		if(nxt[l][i] <= r) l = nxt[l][i], res += p2[i];
	return (res + (l != r));
}
int nxtt(int pos, int num) {
	int cur = 0;
	while(num) {
		if(num & 1) pos = nxt[pos][cur];
		cur++, num >>= 1;
	}
	return pos;
}
void solveBF() {
	p2[0] = 1;
	for(int i = 1; i <= 20; i++) p2[i] = p2[i - 1] * 2;
	while(t--) {
		int ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		for(int i = 1; i <= n; i++) {
			int l = i, r = n;
			while(l < r) {
				int mid = (l + r + 1) / 2;
				if(x[i] + d >= x[mid]) l = mid;
				else r = mid - 1;
			}
			if(r == i) r = n + 1;
			nxt[i][0] = r;
		}
		nxt[n + 1][0] = n + 1;
		for(int i = 1; i <= 20; i++)
			for(int j = 1; j <= n + 1; j++)
				nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
		
		cout << ans << "\n";
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	if((c == 11) || (c == 12)) solveA();
	else if((c == 13) || (c == 14)) solveB();
	else solveBF();
	return 0;
}

