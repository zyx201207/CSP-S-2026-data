// 84-100 pt.(expected so) 18:00.
// n <= 500? Yes!
#include <cctype>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;
#define gc getchar

template <typename T>
void read(T &x) {
	x=0; char c;
	T f=1;
	while(!isdigit(c=gc())) if(c=='-') f=-1;
	while(isdigit(c)) x=x*10+c-'0', c=gc();
	x*=f;
	return ;
}

template <typename T>
T read() {
	T x; read(x); return x;
}

int c;
int m, n, d, q;
long long w[500005];
vector<pair<int, long long> > e[500005];
long long f[505][505];

int main(void) {
	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "wb", stdout);
	freopen("subway.out", "w", stdout);
	read(c);
	read(n); read(m);
	read(d); read(q);
//	puts("!");
	for(int i = 1; i <= m; ++i) read(w[i]);
	for(int i = 1; i <= n; ++i) {
		int k; read(k);
		while(k--) {
			int a; long long t;
			read(a); read(t);
			e[a].push_back(make_pair(i, t));
		}
	}
	memset(f, 0x3f, sizeof f);
	for(int i = 1; i <= n; ++i) f[i][i]=0;
	for(int i = 1; i <= m; ++i) {
		int s=e[i].size();
		for(int j = 0; j < s-1; ++j) {
			for(int k = j+1; k < s; ++k) {
				int u=e[i][j].first, v=e[i][k].first;
				long long w1=e[i][j].second, w2=e[i][k].second;
				if(w1+w2<f[u][v]) f[u][v]=f[v][u]=w1+w2
//				, printf("%d = %d %d : %d %d -> %lld\n", i, j, k, u, v, f[u][v])
				;
			}
		}
	}
//	for(int i = 1; i <= n; ++i) {
//		for(int j = 1; j <= n; ++j) {
//			printf("%lld ", f[i][j]);
//		}
//		puts("");
//	}
//	puts("");
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i = 1; i <= n; ++i) {
//		for(int j = 1; j <= n; ++j) {
//			printf("%lld ", f[i][j]);
//		}
//		puts("");
//	}
	while(q--) {
		int x, y; read(x); read(y);
		if(x==y) {
			puts("0"); continue;
		}
		int s1=e[x].size(), s2=e[y].size();
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i = 0; i < s1; ++i) {
			for(int j = 0; j < s2; ++j) {
				ans=min(ans, f[e[x][i].first][e[y][j].first]+e[x][i].second+e[y][j].second);
			}
		}
		printf("%lld\n", ans+w[x]+w[y]);
	}
	
	return 0;
}
