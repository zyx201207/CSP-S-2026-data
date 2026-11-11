#include<bits/stdc++.h>
#define int long long
using namespace std;
char buf[1<<21],*p1,*p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1<<20,stdin),p1 == p2) ? 0 : *p1++)
template <typename T>
inline void read(T& x){
	x = 0;
	int f = 1;
	char ch = gc();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = gc();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = gc();
	}
	x *= f;
}
const int INF = 1e18 + 7;
int c,T,n,k;
struct edge{
	int to,nxt;
}e[2000010];
int nE = 1,hd[1000010];
void add(int u,int v){
	e[++nE] = (edge){v,hd[u]};
	hd[u] = nE;
}
int dis[1000010],rt = -1,X,Y,p[1000010];
int D = 0,oo[1000010];
int id[1000010];
void dfsrt(int u,int fa){
	if(rt == -1 || dis[rt] < dis[u]) rt = u;
	for(int i = hd[u]; i; i = e[i].nxt){
		int v = e[i].to;
		if(v == fa) continue;
		dis[v] = dis[u] + 1;
		p[v] = u;
		dfsrt(v,u);
	}
}
int f[1000010],g[1000010],lim,lft;
void dfs(int u,int fa){
	f[u] = g[u] = 0;
	for(int i = hd[u]; i; i = e[i].nxt){
		int v = e[i].to;
		if(v == fa || id[v]) continue;
		dfs(v,u);
		f[u] = max(f[u],f[v] + 1);
		g[u] += g[v];
	}
	if(f[u] >= lim) g[u]++;
}
int stk[1000010],tp = 0;
bool ok[1000010];
void dfsok(int u,int fa,int dd){
	if(dd <= lim) ok[u] = 1;
	else ok[u] = 0;
	for(int i = hd[u]; i; i = e[i].nxt){
		int v = e[i].to;
		if(v == fa || id[v]) continue;
		dfsok(v,u,dd + 1);
	}
}
void dfspre(int u,int fa){
	f[u] = (ok[u] ? -INF : 0),g[u] = 0;
	for(int i = hd[u]; i; i = e[i].nxt){
		int v = e[i].to;
		if(v == fa || id[v]) continue;
		dfspre(v,u);
		f[u] = max(f[u],f[v] + 1);
		g[u] += g[v];
	}
	if(f[u] >= lim) g[u]++;
}
bool flag = 0;
int spec = -1;
void solve(int u,int fa){
	int tmpf = g[u] - (f[u] >= lim) + 1;
	if(tmpf <= lft){
		flag = 1;
		return;
	}
	vector<int>tmp,pre,nxt;
	int sz = 0;
	for(int i = hd[u]; i; i = e[i].nxt){
		int v = e[i].to;
		if(id[v] && v != spec) continue;
		sz++;
	}
	tmp.resize(sz + 2),pre.resize(sz + 2),nxt.resize(sz + 2);
	pre[0] = nxt[sz + 1] = (ok[u] ? -INF : 0);
	int p = 0;
	for(int i = hd[u]; i; i = e[i].nxt){
		int v = e[i].to;
		if(id[v] && v != spec) continue;
		p++;
		tmp[p] = v;
		pre[p] = max(pre[p - 1],f[v] + 1);
	}
	for(int i = sz; i >= 1; i--) nxt[i] = max(nxt[i + 1],f[tmp[i]] + 1);
	p = 0;
	for(int i = hd[u]; i; i = e[i].nxt){
		int v = e[i].to;
		if(id[v] && v != spec) continue;
		p++;
		if(v == fa || id[v]) continue;
		int fu = f[u],gu = g[u],fv = f[v],gv = g[v];
		g[u] -= g[v];
		g[u] -= (f[u] >= lim);
		f[u] = max(pre[p - 1],nxt[p + 1]);
		g[u] += (f[u] >= lim);
		g[v] -= (f[v] >= lim);
		f[v] = max(f[v],f[u] + 1);
		g[v] += g[u];
		g[v] += (f[v] >= lim);
		solve(v,u);
		f[u] = fu,g[u] = gu,f[v] = gv,g[v] = gv;
		if(flag) return;
	}
}
int pre[1000010],nxt[1000010];
vector<int>vc[2000010];
bool check(int l){
	if(l + 1 >= D - l) return 1;
	lim = l;
	int x = l + 1,y = D - l;
	tp = 0;
	int sum = 0;
	for(int i = x; i <= y; i++){
		int u = oo[i];
		dfs(u,0);
		if(i == x || i == y) stk[++tp] = i;
		else{
			if(g[u]) stk[++tp] = i,sum += g[u] - 1;
		}
	}
	int mn = INF;
	for(int i = x; i <= y; i++) vc[f[oo[i]] + i].clear(),vc[i + l + 1].clear();
	for(int i = y; i >= x; i--){
		for(auto oo : vc[i + l + 1]) mn = min(mn,oo);
		nxt[i] = max(i,mn - 1);
		if(f[oo[i]] + i > i + l) mn = min(mn,i);
		else vc[f[oo[i]] + i].push_back(i);
	}
	int mx = -INF;
	for(int i = x; i <= y; i++) vc[f[oo[i]] + n - i].clear(),vc[l - i + n + 1].clear();
	for(int i = x; i <= y; i++){
		int v = f[oo[i]] + n - i;
		int lim = l - i + n;
		for(auto oo : vc[lim + 1]) mx = max(mx,oo);
		pre[i] = min(i,mx + 1);
		if(v > lim) mx = max(mx,i);
		else vc[v].push_back(i);
	}
	int summ = 0;
	for(int i = x; i <= y; i++){
		summ += max(1LL,g[oo[i]]);
	}
	int lim = y + 1;
	for(int i = y; i >= x; i--){
		while(lim - 1 > i && summ + max(1LL,g[oo[lim - 1]]) <= k){
			lim--;
			summ += max(1LL,g[oo[lim]]);
		}
		if(summ <= k && lim <= y){
			if(nxt[i] + 1 >= pre[lim]) return 1;
		}
		summ -= max(1LL,g[oo[i]]);
	}
	if(y - x + 1 > k) return 0;
	int llft = k - (y - x + 1);
	int ALL = 0;
	for(int i = x; i <= y; i++){
		if(g[oo[i]] > 1) ALL += g[oo[i]] - 1;
	}
	flag = 0;
	for(int i = x; i <= y; i++){
		int u = oo[i];
		int qqqq = ALL;
		if(g[oo[i]] > 1) qqqq -= g[oo[i]] - 1;
		if(llft < qqqq) continue;
		lft = llft - qqqq;
		spec = u;
		dfsok(u,0,0);
		dfspre(u,0);
		solve(u,0);
		if(flag) return 1;
	}
	return 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(c),read(T);
	while(T--){
		read(n),read(k);
		nE = 1;
		for(int i = 1; i <= n; i++) hd[i] = 0,id[i] = 0,dis[i] = f[i] = g[i] = nxt[i] = pre[i] = oo[i] = stk[i] = 0,ok[i] = 0;
		for(int i = 1,u,v; i < n; i++) read(u),read(v),add(u,v),add(v,u);
		dis[1] = 0;
		rt = -1;
		dfsrt(1,0);
		X = rt;
		rt = -1;
		dis[X] = 0;
		dfsrt(X,0);
		Y = rt;
		D = 0;
		int x = Y;
		while(x != X){
			oo[++D] = x;
			x = p[x];
		}
		oo[++D] = x;
		reverse(oo + 1,oo + D + 1);
		for(int i = 1; i <= D; i++) id[oo[i]] = i;
		int l = 0,r = n;
		while(l < r){
			int mid = (l + r) >> 1;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%lld\n",l);
	}
	return 0;
} 
