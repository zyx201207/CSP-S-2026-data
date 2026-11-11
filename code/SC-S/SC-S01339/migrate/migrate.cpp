#include <bits/stdc++.h>
#define int long long
#define inf (int)1e18
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
//#define i128 __int128_t
const int N = 5000 + 5, M = 1e6 + 5;
//vector<int> g[N];
//int dfn[N], low[N], tdfn;
//int stk[N], tp;
//int bcccnt, bccsz[N];
//void tarjan(int u, int fa){
//	low[u] = dfn[u] = ++ tdfn;
//	stk[++ tp] = u;
//	for(auto v : g[u]){
//		if(v == fa)continue;
//		if(!dfn[v]){
//			tarjan(v, u);
//			low[u] = min(low[u], low[v]);
//			if(low[v] == dfn[u]){
//				bcccnt ++;
//				bccsz[bcccnt] = 0;
//				while(stk[tp + 1] != v)bccsz[bcccnt] ++, -- tp;
//				bccsz[bcccnt] ++;
//			}
//		}else low[u] = min(low[u], dfn[v]);
//	}
//}
vector<int> dag[N];
int n, d, x[N], lst[N], nxt[N];
int dist[N], dp[N];
int q[M], ql, qr;
bool vis[N][N];
int ind[N];
//struct Seg{
//	int tr[N << 2], tag[N << 2];
//	void build(int o, int l, int r, int v){
//		tr[o] = tag[o] = v;
//		if(l == r){
//			return ;
//		}
//		int mid = (l + r) >> 1, ls = o << 1, rs = ls | 1;
//		build(ls, l, mid, v);
//		build(rs, mid + 1, r, v);
//	}
//	void push_down(int o, bool op){
//		int ls = o << 1, rs = ls | 1;
//		if(op == 0){
//			if(tag[o] == -inf)return ;
//			tag[ls] = max(tag[ls], tag[o]);
//			tag[rs] = max(tag[rs], tag[o]);
//			tr[ls] = max(tr[ls], tag[o]);
//			tr[rs] = max(tr[rs], tag[o]);
//			tag[o] = -inf;
//			return ;
//		}else{
//			if(tag[o] == inf)return ;
//			tag[ls] = min(tag[ls], tag[o]);
//			tag[rs] = min(tag[rs], tag[o]);
//			tr[ls] = min(tr[ls], tag[o]);
//			tr[rs] = min(tr[rs], tag[o]);
//			tag[o] = inf;
//			return ;
//		}
//	}
//	void update(int o, int l, int r, int L, int R, int v, bool op){
//		if(L <=	l && r <= R){
//			if(op == 0){
//				tr[o] = max(tr[o], v);
//				tag[o] = max(tag[o], v);
//			}else{
//				tr[o] = min(tr[o], v);
//				tag[o] = min(tag[o], v);
//			}
//			return ;
//		}
//		push_down(o, op);
//		int mid = (l + r) >> 1, ls = o << 1, rs = ls | 1;
//		if(L <= mid)update(ls, l, mid, L, R, v, op);
//		if(R > mid)update(rs, mid + 1, r, L, R, v, op);
//		if(op == 0)tr[o] = max(tr[ls], tr[rs]);
//		else tr[o] = min(tr[ls], tr[rs]);
//	}
//	int query(int o, int l, int r, int pos, bool op){
//		if(l == r)return tr[o];
//		int mid = (l + r) >> 1, ls = o << 1, rs = ls | 1;
//		push_down(o, op);
//		if(pos <= mid)return query(ls, l, mid, pos, op);
//		else return query(rs, mid + 1, r, pos, op);
//	}
//}tr1, tr2;
pair<int, int> his[N];
int hsz;
void _std(){
	cin >> n >> d;
	for(int i = 1;i <= n;i ++)cin >> x[i];
//	tdfn = tp = bcccnt = 0;
//	for(int i = 1;i <= n;i ++)dfn[i] = low[i] = 0, g[i].clear();
	int it = 1, ans = 0;
	for(int i = 1;i <= n;i ++){
		while(x[i] - x[it] > d)++ it;
//		for(int j = i - 1;j >= it;j --){
//			g[i].push_back(j), g[j].push_back(i);
//			cout << i << " " << j << " edge \n";
//		}
		lst[i] = it;
//		int j = it;
//		cout << it << " ";
//		while(j > 1){
//			if(lst[j] == lst[j + 1]){
//				ans += j - 1;
//				break;
//			}
//			if(j == lst[j])break;
//			j = lst[j];
//		}
	}
	it = n;
	for(int i = n;i >= 1;i --){
		while(x[it] - x[i] > d)-- it;
		nxt[i] = it;
	}
//	tr1.build(1, 1, n, -inf);
//	tr2.build(1, 1, n, inf);
	for(int i = 1;i <= n;i ++){
//		tr1.update(1, 1, n, lst[i], nxt[i], nxt[i], 0);
//		tr2.update(1, 1, n, lst[i], nxt[i], lst[i], 1);
//		cout << lst[i] << " " << nxt[i] << "\n";
	}
	for(int i = 1;i <= n;i ++){
//		lst[i] = tr2.query(1, 1, n, i, 1);
//		nxt[i] = tr1.query(1, 1, n, i, 0);
//		cout << lst[i] << " " << nxt[i] << "\n";
	}
	for(int i = 1;i <= n;i ++){
		ql = 1, qr = 0;
		q[++ qr] = i;
//		fill(vis + 1, vis + n + 1, false);
		fill(dist + 1, dist + n + 1, inf);
		dist[i] = 0;
//		vis[i] = true;
		
		while(ql <= qr){
			auto u = q[ql ++];
			for(int v = lst[u];v <= nxt[u];v ++){
//				if(u == 2)cout << v << "u == 2\n";
				if(dist[v] > dist[u] + 1){
					dist[v] = dist[u] + 1;
					q[++ qr] = v;
				}
			}
		}
		ql = 1, qr = 0;
		fill(dp + 1, dp + n + 1, 0);
		fill(ind + 1, ind + n + 1, 0);
		for(int j = 1;j <= n;j ++)dag[j].clear();
		dp[i] = 1;
		q[++ qr] = i;
		hsz = 0;
		while(ql <= qr){
			auto u = q[ql ++];
			for(int v = lst[u];v <= nxt[u];v ++){
				if(dist[v] == dist[u] + 1 && !vis[u][v]){
					dag[u].push_back(v);
//					cout << u << " " << v << "---\n";
					vis[u][v] = true;
					his[++ hsz] = {u, v};
					++ ind[v];
					q[++ qr] = v;
				}
			}
		}
		for(int j = 1;j <= hsz;j ++){
			auto [u, v] = his[j];
			vis[u][v] = false;
		}
		ql = 1, qr = 0;
		q[++ qr] = i;
		while(ql <= qr){
			auto u = q[ql ++];
			for(auto v : dag[u]){
				dp[v] += dp[u];
				if(-- ind[v] == 0)q[++ qr] = v;
			}
		}
//		cout << "start " << i << "\n";
		for(int j = i + 1;j <= n;j ++){
			if(dp[j] == 2){
				++ ans;
//				cout << i << " " << j << "\n";
//				cout << dist[j] << "dij--\n";
			}
//			cout << "dist " << dist[j] << " dp" << dp[j] << " ";
		}
//		if(i == 1){
//			cout << dp[5] << "\n";
//		}
//		if(i == 5){
//			cout << dp[1] << "\n";
//		}
//		cout << "\n";
	}
//	for(int i = 1;i <= n;i ++)if(!dfn[i])tarjan(i, 0);
//	int ans = 0;
//	for(int i = 1;i <= bcccnt;i ++){
//		cout << i << " " << bccsz[i] << "\n";
//		ans += bccsz[i] * (bccsz[i] + 1) / 2;
//	}
	cout << ans << "\n";
	
}
signed main(){
	ios;
//	freopen("data.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int _c; cin >> _c;
	int T; cin >> T;
	while(T --){
		_std();
	}
	return 0;
}
// g++ std.cpp -o -O2 std