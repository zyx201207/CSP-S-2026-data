#include <bits/stdc++.h>
char buf[1000010], obuf[1000010], *p1, *p2, *p3=obuf;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf, 1, 1000000, stdin), p1==p2) ? EOF : *p1++)
#define pc(x) (p3==obuf+1000000&&fwrite(p3=obuf, 1, 1000000, stdout), *p3++=(x))
#define ll long long
#define ui unsigned int
#define N 1000005
#define INF 0x3f3f3f3f
#define tT template<typename T>
#define tA template<typename T, typename... Ts>
using namespace std;
namespace M_K_W_ {
	tT inline void read(T& x) {
		x=0; char ch=gc; bool f=0; while(ch<'0'||ch>'9') { if(ch=='-') f=1; ch=gc; }
		while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48), ch=gc; if(f) x=-x;
	}
	tA inline void read(T& x, Ts&... args) { read(x); read(args...); }
	tT inline void write(T x) {
		if(x==0) return (void)pc('0');
		static ui a[40]; ui t=0; while(x) a[++t]=x%10, x/=10; while(t) pc(a[t--]|48);
	}
	ui n;
	ll m, a[N];
	inline bool check(const ui x) {
		ll sum=0;
		for(ui i=1; i<x; ++i)
			sum+=a[x]-a[i];
		if(sum<=m) return true;
		for(ui i=1, j=x; j<n; ++i, ++j)
			if((sum+=(a[j+1]-a[j])*(x-1)+a[i]-a[j])<=m)
				return true;
		return false;
	}
	inline void solve() {
		read(n, m);
		for(ui i=1; i<=n; ++i)
			read(a[i]);
		sort(a+1, a+1+n);
		ui l=1, r=n;
		while(l<=r) {
			const ui mid=l+r>>1;
			if(check(mid)) l=mid+1;
			else r=mid-1;
		} write(r);
	}
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	M_K_W_ :: solve();
	fwrite(obuf, 1, p3-obuf, stdout);
	return 0;
}
