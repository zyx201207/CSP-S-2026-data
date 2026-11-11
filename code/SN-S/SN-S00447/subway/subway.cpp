//SN-S00447 陈博煜 西安交通大学附属中学 
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 5e2 + 5;
const int MAXM = 5e5 + 5;
const int MAXD = 25;
struct Station{
	int rail[MAXD], rcnt;
	long long tim[MAXD];
	inline void add(int u, long long w){
		rail[++rcnt] = u, tim[rcnt] = w;
	}
}st[MAXM];
long long dis[MAXN][MAXN], val[MAXM], tu, tv;
int c, n, m, d, q, u, v;

inline long long read(){
	long long num = 0, sign = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
		sign = (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= '0' && ch <= '9')
		num = (num << 1) + (num << 3) + ch - 48,
		ch = getchar();
	return sign > 0 ? num : -num;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i++) val[i] = read();
	for(int i = 1, k, x, t; i <= n; i++){
		k = read();
		for(int j = 1; j <= k; j++)
			x = read(), t = read(), st[x].add(i, t);
	}
	memset(dis, INF, sizeof(dis));
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= st[i].rcnt; j++)
			for(int k = j + 1; k <= st[i].rcnt; k++){
				u = st[i].rail[j], v = st[i].rail[k];
				tu = st[i].tim[j], tv = st[i].tim[k];
				dis[u][v] = min(dis[u][v], tu + tv);
				dis[v][u] = min(dis[v][u], tv + tu);
			}
	for(int k = 1; k <= n; k++)
		for(int u = 1; u <= n; u++)
			for(int v = 1; v <= n; v++)
				dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
	while(q--){
		int x = read(), y = read();
		long long ans = INF;
		for(int i = 1; i <= st[x].rcnt; i++)
			for(int j = 1; j <= st[y].rcnt; j++){
				u = st[x].rail[i], v = st[y].rail[j];
				tu = st[x].tim[i], tv = st[y].tim[j];
				ans = min(ans, tu + dis[u][v] + tv);
			}
		cout<< ans + val[x] + val[y]<< "\n";
	} 
	fclose(stdin), fclose(stdout);
	return 0;
}
