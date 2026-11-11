#include<bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = (l); i <= (r); ++ i)
#define per(i, r, l) for(int i = (r); i >= (l); -- i)
#define pb push_back
#define endl '\n'
using namespace std;
const int N = 2e6 + 10;
int d, a[N], b[N], to[N], ans, h[N];
void solve(int n) {
	if(n == 1) return ;
	rep(i, 0, n) to[i] = 0;
	to[n] = n;
	per(i, n - 1, 1) {
		to[i] = to[i + 1];
		while(a[to[i]] - a[i] > d) to[i] --;
	}
	to[n] = n + 1;
	rep(s, 1, n - 1) {
		int t = to[s], cnt = 0;
		while(t < n) {
			int nxt = to[t];
			rep(p, t + 1, nxt) {
				if(cnt == 0) {
					if(to[t - 1] >= p && to[t - 2] < p) ++ ans;
				}
				if(cnt == 1) {
					if(to[t - 1] < p) ++ ans;
				}
			}
			if(to[t] == to[t - 1] && to[t] != to[t - 2]) ++ cnt;
			if(cnt > 1) break;
			t = nxt;
		}
	}
}
void sub(int n) {
	if(n == 1) return ;
	rep(i, 0, n) to[i] = 0;
	to[n] = n;
	per(i, n - 1, 1) {
		to[i] = to[i + 1];
		while(b[to[i]] - b[i] > d) to[i] --;
	}
	to[n] = n + 1;
	int s = 1;
	int t = to[s], cnt = 0;
	while(t < n) {
		int nxt = to[t];
		rep(p, t + 1, nxt) {
			if(cnt == 0) {
				if(to[t - 1] >= p && to[t - 2] < p) ans += n - p + 1;
			}
			if(cnt == 1) {
				if(to[t - 1] < p) ans += n - p + 1;
			}
		}
		if(to[t] == to[t - 1] && to[t] != to[t - 2]) ++ cnt;
		if(cnt > 1) break;
		t = nxt;
	}
}
vector<int> cut;
void Jail() {
	int n;
	cut.clear();
	ans = 0;
	cin >> n >> d;
	rep(i, 1, n) {
		cin >> b[i];
	}
	if(n == 1) {
		cout << 0 << endl;
		return ;
	}
	int flag = 1, e = b[2] - b[1];
	rep(i, 1, n - 1) {
		if(b[i + 1] - b[i] > d) cut.pb(i);	
		if(b[i + 1] - b[i] != e) flag = 0;
	}
	if(flag && n > 5000) {
		if(d < e) {
			cout << 0 << endl;
			return ;
		}
		sub(n);
		cout << ans << endl;
		return ;
	}
	cut.pb(n);
	int pos = 0;
	for(auto x : cut) {
		rep(i, pos + 1, x) a[i - pos] = b[i];
		solve(x - pos);
		pos = x;
	}
	cout << ans << endl;
}
signed main() {
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Id, T = 1;
	cin >> Id >> T;
	while(T --) Jail();
	return 0;
}
/*
0 5
10 2
1 3 5 7 9 11 13 15 17 19
10 3
1 3 5 7 9 11 13 15 17 19
10 5
1 3 5 7 9 11 13 15 17 19
10 7
1 3 5 7 9 11 13 15 17 19

10 15
-10 -5 0 5 10 15 20 25 30 35
*/
