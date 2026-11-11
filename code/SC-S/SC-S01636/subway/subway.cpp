#include <stdio.h>
#define get getchar_unlocked
#define put putchar_unlocked
#define min(x,y) ((x) < (y) ? (x) : (y))
using namespace std;
using ll = long long;
int c,n,m,q,d,w[500005],sz[500005];
ll g[505][505];
const ll tb[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,
	100000000000,1000000000000,10000000000000,100000000000000,1000000000000000,
	10000000000000000,100000000000000000,1000000000000000000};
int read(){
	char c = get();
	int res = 0;
	while ('0' > c || '9' < c) c = get();
	while ('0' <= c && c <= '9'){
		res = res * 10 + (c - '0');
		c = get();
	}
//	int res;
//	cin >> res;
	return res;
}
struct edge{
	int first,second;
};
edge g0[25][500005];
void out(ll x){
	printf("%lld\n",x);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for (int i = 1;i <= n;++i) for (int j = 1;j <= n;++j) if (i != j) g[i][j] = 1e18;
	for (int i = 1;i <= m;++i) w[i] = read();
	for (int i = 1,u,w,k;i <= n;++i){
		k = read();
		while (k--){
			u = read();
			w = read();
			g0[++sz[u]][u] = {i,w};
		}
	}
	for (int i = 1;i <= m;++i)
		for (int j = 1;j <= sz[i];++j)
			for (int k = 1;k <= sz[i];++k)
				g[g0[j][i].first][g0[k][i].first] = min(g[g0[j][i].first][g0[k][i].first], g0[j][i].second + g0[k][i].second);
//	for (int i = 1;i <= n;++i)
//		g[i][i] = 0;
	for (int k = 1;k <= n;++k)
		for (int i = 1;i <= n;++i)
			for (int j = 1;j <= n;++j)
				g[i][j] = min(g[i][k] + g[k][j],g[i][j]);
	while (q--){
		int u = read(),v = read();
		ll minn = 1e18;
		for (int i = 1;i <= sz[u];++i)
			for (int j = 1;j <= sz[v];++j)
#define c g0[i][u]
#define d g0[j][v]
				minn = min(minn,c .second + d .second + g[c .first][d .first]);
//		cout << minn + w[u] + w[v] << '\n';
		out(minn + w[u] + w[v]);
	}
	return 0;
}