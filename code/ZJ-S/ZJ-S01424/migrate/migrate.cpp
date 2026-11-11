#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;

// freopen()
// 40pts on 18:03
// 关注 luogu@jackzhangcn2013 谢谢喵

int n, d;
int x[N], f[N], cnt[N], fc[N];
deque<int> dq;
map<int, int> c;
void add(int x) {
	while(!dq.empty() && f[x] < f[dq.back()]) {
		dq.pop_back();
	}
	dq.push_back(x);
}
void cls(int l) {
	while(!dq.empty() && x[dq.front()] < l) {
		dq.pop_front();
	}
}
int qry() {
	return dq.front();
}
void clean() {
	c.clear();
	while(!dq.empty()) {
		dq.pop_back();
	}
}
void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		clean();
		f[i] = 0;
		cnt[i] = 1;
		fc[i] = 1;
		c[f[i]] += fc[i];
		add(i);
		for(int j = i + 1, l = i; j <= n; j++) {
			f[j] = 1e18;
			cnt[j] = 0;
			while(x[j] - x[l] > d) {
				c[f[l]] -= fc[l];
				l++;
			}
			cls(x[j] - d);
			if(!dq.empty()) {
				f[j] = f[qry()];
			}
			fc[j] = c[f[j]];
			if(fc[j] == 2) {
				ans++;
			}
			f[j]++;
			c[f[j]] += fc[j];
			add(j);
		}
	}
	cout << ans << '\n';
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--) {
		solve();
	}
	return 0;
}