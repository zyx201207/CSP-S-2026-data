#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, a[500005], cnt, nt, m_st[500005], m_l[500005], bfa[500005];
int st[21][500005];
vector<pair<long long, int> >g[500005];
int root = -1, deep[500005], df = 0;
long long dep[500005];
struct ln{
	int u, v;
	long long w;
	bool operator < (const ln &y)const{
		return w < y.w;
	}
}l[500005];
int getfa(int x){
	if(bfa[x] == x)return x;
	return bfa[x] = getfa(bfa[x]);
}
void mdf(int x, int y){
	int zx = getfa(x), zy = getfa(y);
	if(zx != zy){
		bfa[zx] = zy;
	}
}
void frt(int x, int ffa){
	for(auto nxt:g[x]){
		int y = nxt.second, w = nxt.first;
		if(y != ffa){
			dep[y] = dep[x] + w;
			deep[y] = deep[x] + 1;
			st[0][y] = x;
			frt(y, x);
		}
	}
}
int lca(int x, int y){
	if(deep[x] < deep[y])swap(x, y);
	for(int k = 20;k >= 0;k--){
		if(deep[st[k][x]] >= deep[y])x = st[k][x];
	}
	if(x == y)return x;
	for(int k = 20;k >= 0;k--){
		if(!(st[k][x] && st[k][y]))continue;
		if(st[k][x] != st[k][y])x = st[k][x], y = st[k][y];
	}
	return st[0][x];
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for(int i = 1;i <= m;i++){
		scanf("%d", &a[i]);
		m_st[i] = ++nt;
	}
	for(int i = 1;i <= n;i++){
		int k;
		scanf("%d", &k);
		m_l[i] = ++nt;
		for(int j = 1;j <= k;j++){
			int a;
			long long t;
			scanf("%d %lld", &a, &t);
			l[++cnt] = {m_l[i], m_st[a], t};
		}
	}
	for(int i = 1;i <= nt;i++)bfa[i] = i;
	sort(l + 1, l + 1 + cnt);
	deep[0] = -1;
	dep[0] = -1;
	for(int i = 1;i <= cnt;i++){

		int u = l[i].u, v = l[i].v;
		long long w = l[i].w;
		if(u > v)swap(u, v);
		int fu = getfa(u), fv = getfa(v);
		if(fu != fv){
			mdf(fu, fv);
			g[u].push_back({w, v});
			g[v].push_back({w, u});
		}
	}
	root = 1;
	frt(1, 0);
	for(int k = 1;k <= 20;k++){
		for(int i = 1;i <= nt;i++){
			st[k][i] = st[k - 1][st[k - 1][i]];
		}
	}
	while(q--){
		int u, v;
		scanf("%d %d", &u, &v);
		long long ans = a[u] + a[v];
		int t = lca(m_st[u], m_st[v]);
		printf("%lld\n",ans + dep[m_st[u]] + dep[m_st[v]] - 2 * dep[t]);
	}
	return 0;
} 
