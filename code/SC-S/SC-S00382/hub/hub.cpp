#include <bits/stdc++.h>
using namespace std;
#define fir(i, l, r) for(int i = (l); i <= (int) r; i++)
#define fpr(i, r, l) for(int i = (r); i >= (int) l; i--)
const int maxn = 3050;
int dp[maxn], n, k, ndp[maxn], dis[maxn];
vector <int> T[maxn];
mt19937 rnd(time(0));
bitset <maxn> vis, cand;
void dfs(int u, int fa){
//	cout << u << endl;
	vis[u] = 1;
	for(auto v : T[u]){
		if(v == fa) continue ;
		if(cand[v]) dfs(v, u);
	}
}
void dfs2(int u, int fa, int dep){
	dis[u] = min(dis[u], dep);
//	if(dis[u] > dep) dis[u] = dep;
//	else return ;
	for(auto v : T[u]){
		if(v == fa) continue ;
		dfs2(v, u, dep + 1);
	}
}
vector <int> st;
const double alpha = 0.99;
int calc(){
	fir(i, 1, n) dis[i] = INT_MAX;
	for(auto i : st){
		dis[i] = 0;
		dfs2(i, 0, 0);
	}
	int ans = 0;
	fir(i, 1, n) ans = max(ans, dis[i]);
	return ans;
}
signed main(){
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		int ans = INT_MAX;
		fir(i, 1, n) T[i].clear();
		fir(i, 1, n - 1){
			int u, v;
			cin >> u >> v;
			T[u].push_back(v);
			T[v].push_back(u);
		}
		fir(i, 1, (1 << n) - 1){
			if(__builtin_popcount(i) != k) continue ;
			st.clear();
			fir(j, 1, n) cand[j] = vis[j] = 0;
			fir(j, 0, n - 1){
				if(i >> j & 1) cand[j + 1] = 1, st.push_back(j + 1);
			}
			int block = 0;
//			cout << "set = ";
//			for(auto i : st) cout << i << ' ';
//			cout << endl;
			for(auto i : st){
				if(! vis[i]) dfs(i, 0), block++;
				if(block > 2) break ;
			}
			if(block > 2) continue ;
//			cout << "answer = " << calc() << endl;
			ans = min(ans, calc());
		}
		cout << ans << endl;
	}
	return 0;
	
}