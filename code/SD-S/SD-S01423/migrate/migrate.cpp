#include <bits/stdc++.h>
char buf[1000010], obuf[1000010], *p1, *p2, *p3=obuf;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf, 1, 1000000, stdin), p1==p2) ? EOF : *p1++)
#define pc(x) (p3==obuf+1000000&&fwrite(p3=obuf, 1, 1000000, stdout), *p3++=(x))
#define LF pc('\n')
#define SP pc(' ')
#define ll long long
#define ui unsigned int
#define N 1000005
#define M 5000
#define K 20
#define INF 0x3f3f3f3f
#define mod 100000007
#define tT template<typename T>
#define tA template<typename T, typename... Ts>
#define TX for(ui i=head[u]; i; i=edge[i].nxt)
using namespace std;
const ui _2[31]= { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824 } ;
namespace FastIO {
	tT inline void read(T& x) {
		x=0; char ch=gc; bool f=0; while(ch<'0'||ch>'9') { if(ch=='-') f=1; ch=gc; }
		while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48), ch=gc; if(f) x=-x;
	}
	tA inline void read(T& x, Ts&... args) { read(x); read(args...); }
	tT inline void write(T x) {
		if(x==0) return (void)pc('0'); if(x<0) x=-x, pc('-');
		static ui a[40]; ui t=0; while(x) a[++t]=x%10, x/=10; while(t) pc(a[t--]|48);
	}
	tA inline void write(T x, Ts... args) { write(x); if(sizeof...(args)!=0) { SP; write(args...); } }
}
using namespace FastIO;
tT inline T Ad(const T x) { return x<mod ? x : x%mod; }
tT inline T ad(const T x) { return x<mod ? x : x-mod; }
tT inline void S(T& a, T& b) { a^=b, b^=a, a^=b; }
namespace M_K_W_ {
	tT inline T max(const T a, const T b) { return a>b ? a : b; }
	tT inline T min(const T a, const T b) { return a<b ? a : b; }
	ui n, step[M][M];
	ll m, a[N], ans;
	bool vis[M][M];
	vector<ui> b[M], l[M];
	inline void solvedengchashulie() {
		read(n, m);
		for(ui i=1; i<=n; ++i)
			read(a[i]);
		if(n<4||m<a[3]-a[1]||m>=a[4]-a[1]) pc('0'), LF;
		else write(n-3), LF;
	}
	inline void solvefzjruaphy() {
		read(n, m);
		ans=0;
		for(ui i=1; i<=n; ++i)
			read(a[i]);
		ui I=1;
		for(; a[I]-a[1]>m||a[n]-a[I]>m; ++I) ;
		if(I<2) pc('0'), LF;
		else {
			const ui X=upper_bound(a+I+1, a+n+1, a[I-1]+m)-a;
			if(X==I+2) ans+=n-X+1;
			for(ui i=1; i+1<I; ++i) {
				const ui t=upper_bound(a+I+1, a+n+1, a[i]+m)-a;
				if(t==I+2) ans+=n-X+1;
				else if(i+2==I) ans+=X-I-1;
				else {
					const ui j=upper_bound(a+I+1, a+n+1, a[I-2]+m)-a;
					ans+=X-j;
				}
			} write(ans), LF;
		}
	}
	inline void solve() {
		read(n, m);
		ans=0;
		for(ui i=1; i<=n; ++i)
			read(a[i]);
		write(n), LF;
	}
	inline void main() {
		ui gunmu, T;
		read(gunmu, T);
		while(T--) {
			if(gunmu==11||gunmu==12)
				solvedengchashulie();
			else if(gunmu==13||gunmu==14)
				solvefzjruaphy();
			else
				solve();
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	M_K_W_ :: main();
	fwrite(obuf, 1, p3-obuf, stdout);
	return 0;
}
