#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pli pair<long long,int>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define fi first
#define se second
#define pb push_back
#define cntbit(a) __builtin_popcountll((a));
#define d(a) cerr<<#a<<":"<<a<<" ";
#define dn cerr<<"\n";
#define dl cerr<<"---------------------------------------\n";
template<class _T>
void ckmax(_T &x, _T y) {
	x = max(x, y);
}
template<class _T>
void ckmin(_T &x, _T y) {
	x = min(x, y);
}
bool MST;
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL
#define mod 998244353
#define N 5010
int c, n, len, sum = 0;
int a[N];
pii dp[N][N];
queue<pii>p;
bool check(int ft, int ed) {
	int res = 0;
	while (!p.empty())p.pop();
	p.push({0, ft});
	while (!p.empty()) {
		pii now = p.front();
		p.pop();
		int u = now.se, op = now.fi;
		if (op == 0) {
			rep(i, u + 1, ed) {
				if (a[i] - a[u] <= len) {
					p.push({1, i});
				} else break;
			}
		} else {
			if (a[ed] - a[u] <= len)res++;
		}
		if (res > 2)return false;
	}
	if (res == 2)return true;
	return false;
}
void solve_() {
	cin >> n >> len;
	sum = 0;
	rep(i, 1, n) cin >> a[i];
	int l = 1, r = 2;
	rep(i, 1, n) {
		while (a[r + 1] - a[i] <= len * 2 && r + 1 <= n)r++;
		while (a[l] - a[i] <= len && l + 1 <= n)l++;
		d(i)d(l)d(r)dn;
		rep(j, i + 1, r) {
			if (a[j] - a[i] <= len)continue;
			if (check(i, j)) {
				sum++;
			}
		}
	}
	cout << sum << "\n";
}
bool MED;
signed main() {
//	cerr << abs(&MST - &MED) / 1024 / 1024 << "MB\n";
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> c >> T;
	while (T--) {
		solve_();
	}
	return 0;
}
