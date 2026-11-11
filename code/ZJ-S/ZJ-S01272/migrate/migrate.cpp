#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6 + 10;
int c, n;
ll d, x[N], a[N], b[N];
bool is_pair[N];

int qr(int s) {
	return upper_bound(x + 1, x + n + 1, x[s] + d) - x - 1;
}

int ql(int s) {
	return lower_bound(x + 1, x + n + 1, x[s] - d) - x;
}

void solve() {
	cin >> n >> d;
	ll cnt = 0;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i < n; i++) {
		int j = qr(i), k = qr(j);
		if (j != k and j >= i + 2 and x[k] - x[j - 1] <= d and x[k] - x[j - 2] > d) is_pair[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (is_pair[i] == 1) {
			int v1 = qr(i), j = qr(v1), v2 = v1 - 1;
			int l = i, r = j, cntl = 1, cntr = 1, il, ir;
			a[0] = v1, a[1] = r;
			for (ir = 2; ir <= n; ir++) {
				a[ir] = qr(a[ir - 1]);
				if (a[ir] == a[ir - 1]) break;
				if (x[a[ir]] - x[a[ir - 1] - 1] <= d) break;
				cntr += qr(a[ir - 1]) - qr(a[ir - 1] - 1);
			}
			b[0] = v2, b[1] = l;
			for (il = 2; il <= n; il++) {
				b[il] = ql(b[il - 1]);
				if (b[il] == b[il - 1]) break;
				if (x[b[il - 1] + 1] - x[b[il]] <= d) break;
				cntl += ql(b[il - 1] + 1) - ql(b[il - 1]);
			}
			cnt += cntl * cntr;
			
			for (int k = 0; k <= ir; k++) a[k] = 0;
			for (int k = 0; k <= il; k++) b[k] = 0;
		}
	}
	
	//cout << cnt << '\n';
	
	for (int i = 1; i < n; i++) {
		int v1 = qr(i), j = qr(v1);
		if (j != v1 and v1 - i > 1) cnt += qr(v1 - 1) - qr(v1 - 2) - is_pair[i];
	}
	
	cout << cnt << '\n';
	
	for (int i = 1; i <= n; i++) x[i] = 0;
	for (int i = 1; i <= n; i++) is_pair[i] = 0;
}

void solve1() {
	cin >> n >> d;
	ll cnt = 0;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i < n; i++) {
		for (int j = i + 3; j <= n; j++) {
			int l = 0, now = i;
			a[0] = now;
			bool can = 1;
			while (now != j) {
				l++;
				a[l] = min(j, qr(now));
				now = a[l];
				if (now != j and x[now + 1] - x[now] > d) {
					can = 0;
					break;
				}
			}
			if (!can) continue;
			bool flag = 1;
			int num = 0;
			for (int k = 1; k < l; k++) {
				if (x[a[k + 1]] - x[a[k] - 1] <= d) {
					num++;
					if (a[k] >= 3 and x[a[k + 1]] - x[a[k] - 2] <= d) flag = 0;
				}
			}
			if (flag and num == 1) cnt++;
		}
	}
	cout << cnt << '\n';
	
	for (int i = 1; i <= n; i++) x[i] = 0;
}

void solve2() {
	cin >> n >> d;
	ll cnt = 0;
	for (int i = 1; i <= n; i++) cin >> x[i];
	if (a[2] - a[1] >= d) cout << "0\n";
	else if (3 * (a[2] - a[1]) > d and 2 * (a[2] - a[1]) <= d) cout << max(0, n - 3) << '\n';
	else cout << "0\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int T; cin >> c >> T;
	while (T--) {
		if (c <= 6) solve1();
		else if (c == 11 or c == 12) solve2();
		else solve();
	}
	
	return 0;
}
