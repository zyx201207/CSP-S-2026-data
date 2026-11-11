#include <bits/stdc++.h>
char buf[1000010], obuf[1000010], *p1, *p2, *p3=obuf;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf, 1, 1000000, stdin), p1==p2) ? EOF : *p1++)
#define pc(x) (p3==obuf+1000000&&fwrite(p3=obuf, 1, 1000000, stdout), *p3++=(x))
#define LF pc('\n')
#define ll unsigned long long
#define ui unsigned int
#define N 505
#define M 500005
#define K 25
#define INF 0x3f3f3f3f3f3f3f3f
#define tT template<typename T>
#define tA template<typename T, typename... Ts>
#define TX for(ui i=head[u]; i; i=edge[i].nxt)
using namespace std;
namespace M_K_W_ {
	tT inline void read(T& x) {
		x=0; char ch=gc; while(ch<'0'||ch>'9') ch=gc;
		while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48), ch=gc;
	}
	tA inline void read(T& x, Ts&... args) { read(x); read(args...); }
	tT inline void write(T x) {
		if(x==0) return (void)pc('0');
		static ui a[40]; ui t=0; while(x) a[++t]=x%10, x/=10; while(t) pc(a[t--]|48);
	}
	inline ll min(const ll a, const ll b) { return a<b ? a : b; }
	ui n, m, d, q, w[M], k[N], x, y, b[M][K], e[M][K], c[M];
	ll f[N][N];
	vector<ui> a[N], t[N];
	inline void solve() {
		read(c[0], n, m, d, q);
		for(ui i=1; i<=m; ++i)
			read(w[i]);
		for(ui i=1; i<=n; ++i) {
			read(k[i]);
			a[i].reserve(k[i]+5), t[i].reserve(k[i]+5);
			a[i].emplace_back(0), t[i].emplace_back(0);
			for(ui j=1; j<=k[i]; ++j) {
				read(x, y);
				a[i].emplace_back(x), t[i].emplace_back(y);
				b[x][++c[x]]=i, e[x][c[x]]=y;
			}
		} for(ui i=1; i<=n; ++i)
			for(ui j=1; j<=n; ++j)
				f[i][j]=INF;
		for(ui i=1; i<=n; ++i) f[i][i]=0;
		for(ui u=1; u<=n; ++u) {
			for(ui j=1; j<=k[u]; ++j) {
				const ui x=a[u][j];
				const ll y=t[u][j];
				for(ui i=1; i<=c[x]; ++i)
					f[u][b[x][i]]=f[b[x][i]][u]=min(f[u][b[x][i]], y+e[x][i]);
			}
		} for(ui k=1; k<=n; ++k)
			for(ui i=1; i<=n; ++i)
				for(ui j=1; j<=n; ++j)
					f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
		while(q--) {
			read(x, y);
			ll ans=INF;
			for(ui i=1; i<=c[x]; ++i)
				for(ui j=1; j<=c[y]; ++j)
					ans=min(ans, f[b[x][i]][b[y][j]]+e[x][i]+e[y][j]);
			write(ans+w[x]+w[y]), LF;
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	M_K_W_ :: solve();
	fwrite(obuf, 1, p3-obuf, stdout);
	return 0;
}
