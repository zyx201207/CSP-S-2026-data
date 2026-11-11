// SN-S00515 王铂涵 西安市铁一中
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define pq priority_queue
#define ull unsigned long long
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int C; int n, k;
vector<int> vc[N];
int siz[N], mxsiz[N], All; bool vis[N];
int st[N][21], dep[N];
//void dfs(int x = 1, int fa = 1){
//	st[x][0] = fa; dep[x] = dep[fa] + 1;
//	rep(i, 1, 20) st[x][i] = st[st[x][i - 1]][i - 1];
//	for(int y : vc[x]) if(y ^ fa) dfs(y, x);
//}
//int LCA(int x, int y){
//	if(dep[x] < dep[y]) swap(x, y);
//	dep(i, 20, 0) if(dep[st[x][i]] >= dep[y]) x = st[x][i];
//	if(x == y) return x;
//	dep(i, 20, 0) if(st[x][i] ^ st[y][i]) x = st[x][i], y = st[y][i];
//	return st[x][0];
//}
//int dis(int x, int y){return dep[x] + dep[y] - dep[LCA(x, y)] * 2;}
//void get_siz(int x, int fa){
//	siz[x] = 1; mxsiz[x] = 1;
//	for(int y : vc[x]) if(!vis[x] && fa != y){
//		get_siz(y, x); siz[x] += siz[y]; mxsiz[x] = max(mxsiz[x], siz[y]);
//	}
//}
//int get_rt(int x, int fa){
//	if(max(mxsiz[x], All - siz[x]) <= All / 2) return x;
//	for(int y : vc[x]) if(!vis[x] && fa != y){
//		int tmp = get_rt(y, x);
//		if(~tmp) return tmp;
//	} return -1;
//}
//int ret, mx; bool spl;
//void sol(int x = 1){
//	get_siz(x, x); if((All = siz[x]) == 1) return ; int rt = get_rt(x, x); vis[rt] = 1;
//	if(dis(x, rt) + ret >= k) spl = 1, ret -= mx;
//	
//}
void solve(){
	cin >> n >> k; rep(i, 1, n) vc[i].clear();
	rep(i, 1, n - 1){int u, v; cin >> u >> v; vc[u].pb(v); vc[v].pb(u);}
	int len = n; k /= 2; cout << (len - k) / 3 +2 << "\n";
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T = 1;
	cin >> C >> T;
	while(T--) solve();
}

