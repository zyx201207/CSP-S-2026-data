#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e6 + 5, mod1 = 998244353, mod2 = 1e9 + 7;

int c, t, n, d, x[N], lst[N], nxt[N];

signed cnt1[N], cnt2[N];

struct Node {
	signed len, s1, s2;
};

Node f[N];

signed h[N], ne[N * 10], to[N * 10], idx;
int To[N * 10];

void add (int u, int v, int w) {
	to[ ++ idx] = v;
	To[idx] = w;
	ne[idx] = h[u];
	h[u] = idx;
	return;
}

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> c >> t;
	while (t -- ) {
	    cin >> n >> d;
	//    d = n / 10;
	    for (int i = 1; i <= n; ++ i ) cin >> x[i];
	    if (c <= 10) {
	    	int res = 0;
	    	for (int l = 1; l <= n; ++ l ) {
	    		f[l] = {0, 1, 1};
	    		for (int i = 0; i <= n; ++ i ) cnt1[i] = cnt2[i] = 0;
	    		cnt1[0] = cnt2[0] = 1;
	    		for (int r = l + 1, i = l; r <= n; ++ r ) {
	    			if (x[r] - x[r - 1] > d) break;
					while (x[r] - x[i] > d) {
						(cnt1[f[i].len] -= f[i].s1 - mod1) %= mod1;
						(cnt2[f[i].len] -= f[i].s2 - mod2) %= mod2;
						++ i;
					}
					int now = f[i].len;
					f[r] = {f[i].len + 1, cnt1[now], cnt2[now]};
					(cnt1[f[r].len] += f[r].s1) %= mod1;
					(cnt2[f[r].len] += f[r].s2) %= mod2;//cout << l << ' ' << r << ' ' << f[r].len << ' ' << f[r].s1 << ' ' << f[r].s2 << endl;
					if (f[r].s1 == 2 && f[r].s2 == 2) ++ res;
				}
 			}
 			cout << res << '\n';
 			continue;
		}
		if (c <= 12) {
			int res = 0;
	    	for (int l = 1; l <= 1; ++ l ) {
	    		f[l] = {0, 1, 1};
	    		for (int i = 0; i <= n; ++ i ) cnt1[i] = cnt2[i] = 0;
	    		cnt1[0] = cnt2[0] = 1;
	    		for (int r = l + 1, i = l; r <= n; ++ r ) {
	    			if (x[r] - x[r - 1] > d) break;
					while (x[r] - x[i] > d) {
						(cnt1[f[i].len] -= f[i].s1 - mod1) %= mod1;
						(cnt2[f[i].len] -= f[i].s2 - mod2) %= mod2;
						++ i;
					}
					int now = f[i].len;
					f[r] = {f[i].len + 1, cnt1[now], cnt2[now]};
					(cnt1[f[r].len] += f[r].s1) %= mod1;
					(cnt2[f[r].len] += f[r].s2) %= mod2;//cout << l << ' ' << r << ' ' << f[r].len << ' ' << f[r].s1 << ' ' << f[r].s2 << endl;
					if (f[r].s1 == 2 && f[r].s2 == 2) res += (n - (r - l));
				}
 			}
 			cout << res << '\n';
 			continue;
		}
		for (int i = 1, j = 1; i <= n; ++ i ) {
		    while (x[i] - x[j] > d) ++ j;
			lst[i] = j;	
		}
		for (int i = n, j = n; i >= 1; -- i ) {
			while (x[j] - x[i] > d) -- j;
			nxt[i] = j;
		}
		unordered_map <signed, int> cnt[15];
		int res = 0, ct = 0;
	//	for (int i = 1; i <= n; ++ i ) g[i].clear();
		for (int i = 1; i <= n; ++ i ) h[i] = 0;
		idx = 0;
		for (int i = 1; i <= n; ++ i ) {
			int x = i;
			int len = 0, sum = 0;
			while (nxt[x] != x) {
				add(x + 1, len, sum);
			//	g[x + 1].push_back({len, sum});
			//	++ cnt[len][sum];
			//	cout << "K" << i << ' ' << x << ' ' << len << ' ' << sum << endl;
				++ len;
				sum += nxt[x];
				x = nxt[x];// ++ ct;
			//	if (len > 10) cout << "KKK" << endl;
			}
		}
		for (int i = 1; i <= n; ++ i ) {
			for (int j = h[i]; j; j = ne[j] ) {
				++ cnt[to[j]][To[j]];
			}
			int x = i;
			int len = 0, sum = 0;
			while (lst[x] != x) {//cout << "I" << i << ' ' << x << ' ' << len << ' ' << sum << endl;
				res += cnt[len].count(sum + 1) ? cnt[len][sum + 1] : 0;
				++ len;
				sum += lst[x];
				x = lst[x];//++ ct;
			}//cout << "KKK" << res << endl;
		}
		cout << res << '\n';//cout << ct << endl;
	}
	
	return 0;
}
