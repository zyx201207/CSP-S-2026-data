#include <bits/stdc++.h>
#define File(x) (freopen(x".in", "r", stdin), freopen(x".out", "w", stdout))
#define N 1000006
using namespace std;

int n, k;
vector<int> sd[N];

namespace bf {
	int ans;
	int seq[30];
	bool vis[30];
	void dfs(int u) {
		vis[u] = 0;
		for(int v : sd[u]) if(vis[v]) dfs(v);
	}
	int mi[30];
	void dfs2(int u, int fa, int dh) {
		mi[u] = min(mi[u], dh);
		for(int v : sd[u]) if(v != fa) dfs2(v, u, dh+1);
	}
	void dfsbf(int t, int lst) {
		if(t > k) {
			memset(mi, 0x3f, sizeof mi);
			int cnt = 0;
			for(int i=1 ; i<=k ; i++) vis[seq[i]] = 1;
			for(int i=1 ; i<=k ; i++) if(vis[seq[i]]) dfs(seq[i]), cnt++;
			if(cnt > 2) return;
			for(int i=1 ; i<=k ; i++) dfs2(seq[i], seq[i], 0);
			ans = min(ans, *max_element(mi+1, mi+1+n));
			return;
		}
		for(int i=lst+1 ; i<=n ; i++) seq[t] = i, dfsbf(t+1, i);
	}
	void atri() {
		ans = INT_MAX;
		dfsbf(1, 0);
		printf("%d\n", ans);
	}
}

namespace subA {
	bool check(int x) {
		int l = x, r = n/2+1-x;
		return r-l+1 <= k + 2*x;
	}
	void atri() {
		if(k == n) return void(puts("0"));
		int bl = 1, br = n, ba = n;
		while(bl <= br) {
			int bm = (bl+br) >> 1;
			if(check(bm)) ba = bm, br = bm-1;
			else bl = bm+1;
		}
		printf("%d\n", ba);
	}
}

int main() {
	File("hub"), ios::sync_with_stdio(0), cin.tie(0);
	int TC, T; cin >> TC >> T;
	while(T--) {
		cin >> n >> k;
		for(int i=1 ; i<=n ; i++) sd[i] = {};
		for(int i=1,u,v; i<n ; i++) cin >> u >> v, sd[u].push_back(v), sd[v].push_back(u);
		if(TC == 13 || TC == 14) subA::atri();
		else bf::atri();
	}
	return 0;
}