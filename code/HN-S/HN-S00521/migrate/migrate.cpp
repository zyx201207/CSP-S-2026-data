#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 2e6 + 1;
int a[N];
unordered_map<int, int> mp;
int minn = INT_MAX;

void dfs(int u, int v, int d, int step = 0) {
	if(u == v) {
		mp[step] ++;
		minn = min(minn, step);
		return ;
	}
	for(int i = u + 1; i <= v; i ++) {
		if(a[i] - a[u] <= d) {
			dfs(i, v, d, step + 1);
		}
	}
}

void dfs2(int u) {

}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	if(c == 11 or c == 12) {
		while(t --) {
			int n, d;
			cin >> n >> d;
			for(int i = 1; i <= n; i ++) cin >> a[i];
			if(d < a[2] - a[1] or n == 1) cout << 0 << endl;
			if(d == a[2] - a[1]) cout << n - 2 << endl;
		}
	} else {
		while(t --) {
			int n, d;
			cin >> n >> d;
			for(int i = 1; i <= n; i ++) cin >> a[i];
			int answer = 0;
			for(int u = 1; u <= n; u ++) {
				for(int v = u + 2; v <= n; v ++) {
					minn = INT_MAX;
					dfs(u, v, d);
					answer += (mp[minn] == 2);
					for(auto &i : mp) i.second = 0;

				}
			}
			cout << answer << endl;
		}
	}
	return 0;
}

