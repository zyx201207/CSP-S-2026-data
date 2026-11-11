#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s = 0, f = 1;
	signed c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -f;
	for(; isdigit(c); c = getchar()) s = (s * 10) + (c ^ 48);
	return s * f;
}
void write(int x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar('0' + x % 10);
}
const int N = 5e5 + 10, M = 505;
int ID, n, m, d, q, w[N], dis[M][M];
struct node{
	int id, t;
	node(int id = 0, int t = 0) : id(id), t(t){}
};
vector<node> a[N];
void opt(int id){
	int u, v, uw, vw;
	for(int i = 0; i < a[id].size(); ++ i){
		for(int j = 0; j < a[id].size(); ++ j){
			if(i == j) continue;
			u = a[id][i].id, v = a[id][j].id;
			uw = a[id][i].t, vw = a[id][j].t;
			dis[u][v] = min(dis[u][v], uw + vw);
		}
	}
}
int qry(int u, int v){
	int res = 1e18;
	for(node x : a[u])
		for(node y : a[v])
			res = min(res, w[u] + x.t + dis[x.id][y.id] + y.t + w[v]);
	return res;
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));
	ID = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; ++ i) w[i] = read();
	for(int i = 1, k; i <= n; ++ i){
		dis[i][i] = 0;
		k = read();
		for(int j = 1, id, t; j <= k; ++ j){
			id = read(), t = read();
			a[id].emplace_back(i, t);
		}
	}
	for(int i = 1; i <= m; ++ i) opt(i);
	for(int k = 1; k <= n; ++ k)
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= n; ++ j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for(int u, v; q --;){
		u = read(), v = read();
		write(qry(u, v)), puts("");
	}
	return 0;
}