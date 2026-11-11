#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
	T s = 0; int st = 1; char c = getchar();
	while(c < '0' || c > '9') (c == '-') && (st = -1), c = getchar();
	while(c >= '0' && c <= '9') s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
	x = s * st;
}
template<typename T, typename... Args> inline void read(T &x, Args &...args){
	read(x), read(args...);
}
template<typename T> inline void write(T x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
//#define int long long 
#define LL long long
#define PII pair<int, int>
#define ull unsigned long long
const int N = 505, M = 5e5 + 5;
struct node{
	int v, w;
	node(int i = 0, int j = 0): v(i), w(j){}
}bel[M][25];
int a[M], cnt[M];
LL dis[N][N];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("subway7.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
	int c, n, m, d, q;
	read(c, n, m, d, q);
	for(int i = 1; i <= m; ++i){
		read(a[i]);
	}
	for(int i = 1, len; i <= n; ++i){
		read(len);
		for(int j = 1; j <= len; ++j){
			int u, w;
			read(u, w);
			bel[u][cnt[u]++] = {i, w};
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; ++i) dis[i][i] = 0;
	for(int i = 1, u, v; i <= m; ++i){
		for(int j = 0; j < cnt[i]; ++j){
			for(int k = 0; k < j; ++k){
				u = bel[i][j].v, v = bel[i][k].v;
				dis[u][v] = dis[v][u] = min(dis[u][v], (LL)bel[i][j].w + bel[i][k].w);
			}
		}
	}
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
//	for(int i = 1; i <= n; ++i){
//		for(int j = 1; j <= n; ++j){
//			cerr << dis[i][j] << ' ';
//		}
//		cerr << '\n';
//	}
	while(q--){
		int s, t;
		read(s, t);
		LL ans = 1e18;
		node i, j;
		for(int ii = 0; ii < cnt[s]; ++ii){
			for(int jj = 0; jj < cnt[t]; ++jj){
				i = bel[s][ii], j = bel[t][jj];
				ans = min(ans, dis[i.v][j.v] + a[s] + a[t] + i.w + j.w);
			}
		}
		write(ans), putchar('\n');
	}
	return 0;
}