#include <bits/stdc++.h>
char buf[1000010], obuf[1000010], *p1, *p2, *p3=obuf;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf, 1, 1000000, stdin), p1==p2) ? EOF : *p1++)
#define pc(x) (p3==obuf+1000000&&fwrite(p3=obuf, 1, 1000000, stdout), *p3++=(x))
#define LF pc('\n')
#define SP pc(' ')
#define ll unsigned long long
#define ui unsigned int
#define N 1000005
#define M 1000005
#define K 20
#define INF 0x3f3f3f3f
#define tT template<typename T>
#define tA template<typename T, typename... Ts>
#define TX for(ui i=head[u]; i; i=edge[i].nxt)
using namespace std;
const ui _2[31]= { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824 } ;
namespace FastIO {
	tT inline void read(T& x) {
		x=0; char ch=gc; while(ch<'0'||ch>'9') ch=gc;
		while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48), ch=gc;
	}
	tA inline void read(T& x, Ts&... args) { read(x); read(args...); }
	tT inline void write(T x) {
		if(x==0) return (void)pc('0');
		static ui a[40]; ui t=0; while(x) a[++t]=x%10, x/=10; while(t) pc(a[t--]|48);
	}
	tA inline void write(T x, Ts... args) { write(x); if(sizeof...(args)!=0) { SP; write(args...); } }
}
using namespace FastIO;
namespace M_K_W_ {
	tT inline T max(const T a, const T b) { return a>b ? a : b; }
	tT inline T min(const T a, const T b) { return a<b ? a : b; }
	struct Edge { ui to, nxt; } edge[N<<1];
	ui n, m, x, y, head[N], idx, dep[N], fa[N], rt, rt2, rt3, cnt, delx, dely, mxd[N], siz, siz2, ans, Siz;
	inline void add(const ui u, const ui v) {
		edge[++idx].to=v, edge[idx].nxt=head[u], head[u]=idx;
	}
	inline void dfs(const ui u, ui& rt) {
		TX {
			const ui v=edge[i].to;
			if(v==fa[u]||u==delx&&v==dely||v==delx&&u==dely) continue;
			dep[v]=dep[fa[v]=u]+1;
			dfs(v, rt);
		} if(dep[u]>dep[rt]) rt=u;
	}
	inline void init(const ui u) {
		mxd[u]=0; TX {
			const ui v=edge[i].to;
			if(v==fa[u]||u==delx&&v==dely||v==delx&&u==dely) continue;
			dep[v]=dep[fa[v]=u]+1;
			init(v);
			mxd[u]=max(mxd[u], mxd[v]+1);
		}
	}
	inline bool check(const ui x) {
		cnt=2;
		for(ui i=1; i<=n; ++i)
			if(i!=rt&&i!=rt2&&mxd[i]>=x)
				++cnt;
		return cnt>m;
	}
	inline void solve() {
		read(n, m);
		idx=delx=dely=0;
		for(ui i=1; i<=n; ++i)
			head[i]=0;
		for(ui i=1; i<n; ++i)
			read(x, y), add(x, y), add(y, x);
		if(m==n) return pc('0'), LF, void();
		dep[1]=fa[1]=0;
		dfs(1, rt);
		dep[rt]=fa[rt]=0;
		dfs(rt, rt2);
		ui l=1, r=Siz=dep[rt2];
		rt3=rt2;
		dep[rt3]=fa[rt3]=0;
		init(rt3);
		while(l<=r) {
			const ui mid=l+r>>1;
			if(check(mid)) l=mid+1;
			else r=mid-1;
		} ans=l;
		l=1, r=n;
		dep[1]=fa[1]=0;
		dfs(1, rt);
		dep[rt]=fa[rt]=0;
		dfs(rt, rt2);
		for(ui j=dep[rt2]>>1; j; rt2=fa[rt2], --j) ;
		delx=fa[rt2], dely=rt2, fa[rt2]=0;
		fa[rt]=dep[rt]=0;
		dfs(rt, rt);
		siz=dep[rt];
		for(ui j=siz>>1; j; rt=fa[rt], --j) ;
		dep[rt2]=fa[rt2]=0;
		dfs(rt2, rt2);
		siz2=dep[rt2];
		for(ui j=siz2>>1; j; rt2=fa[rt2], --j) ;
		dep[rt]=dep[rt2]=fa[rt]=fa[rt2]=0;
		init(rt);
		init(rt2);
		while(l<=r) {
			const ui mid=l+r>>1;
			if(check(mid)) l=mid+1;
			else r=mid-1;
		} write(min(l, ans)), LF;
	}
	inline void main() {
		ui gunmu, T;
		read(gunmu, T);
		while(T--)
			solve();
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	M_K_W_ :: main();
	fwrite(obuf, 1, p3-obuf, stdout);
	return 0;
}
/*
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/
