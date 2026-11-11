#include <bits/stdc++.h>
#define ll long long
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define req(i, r, l) for(int i = r; i >= l; i--)
#define pb push_back
#define int ll
#define mkp make_pair
#define fir first
#define sec second
#define PII pair<int, int>
inline int rd() {
	int res = 0, f = 1; char ch;
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) { res = (res << 3) + (res << 1) + (ch ^ 48); ch = getchar(); }
	return f * res;
}
using namespace std;
const int N = 2e6 + 8;
int n, d;
int a[N];
PII f[N];
PII operator +(PII x, PII y) {
	if(x.fir == y.fir) return mkp(x.fir, min(x.sec + y.sec, 3ll));
	return x.fir < y.fir? x: y;
}
struct BIT {
#define lb(x) x&-x
	PII c[N];
	void upd(int pos, PII v) {
		while(pos <= n) {
			c[pos] = c[pos] + v;
			pos += lb(pos);
		}
	}
	PII qry(int pos) {
		PII res = mkp(1e18, 0);
		while(pos) {
			res = res + c[pos];
			pos -= lb(pos);
		}
		return res;
	}
}fenwick;
void solve() {
	n = rd(); d = rd();
	rep(i, 1, n) a[i] = rd();
	ll ans = 0;
	rep(s, 1, n) {
//		cout << s << ":\n";
		rep(i, 1, n) fenwick.c[i] = mkp(1e18, 0);
		rep(i, 1, s - 1) f[i] = mkp(1e18, 0);
		f[s] = mkp(0, 1);
		fenwick.upd(n - s + 1, f[s]);
		rep(i, s + 1, n) {
			int j = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
			if(j < i) f[i] = fenwick.qry(n - j + 1);
			f[i].fir++;
			if(f[i].sec == 2) ans++;
			fenwick.upd(n - i + 1, f[i]);
			if(f[i].fir == 1e18) break;
		}
	}
	cout << ans << "\n";
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);	
	rd(); int T = rd();
	while(T--) solve();
	return 0;
}
/*
15:36 100 + 100 + 0 + 0
17:13 100 + 100 + 0 + eps
17:49 100 + 100 + 24 + eps
17:56 100 + 100 + 40 + eps
17:59 发现其实是 100 + [92,100] + 40 + eps，不过CCF少爷机1s 1e8 还跑不满，应该能过吧

T4我怀疑是蓝。

感觉这场不咋难啊。我说要7勾了有感觉吗

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/