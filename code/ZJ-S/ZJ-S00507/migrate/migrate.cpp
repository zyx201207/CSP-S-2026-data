#include <bits/stdc++.h>
#define ED cerr<<'\n';
#define TS cerr<<"I AK IOI\n";
#define cr(x) cerr<<x<<'\n';
#define cr2(x,y) cerr<<x<<" "<<y<<'\n';
#define cr3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<'\n';
#define cr4(x,y,z,w) cerr<<x<<" "<<y<<" "<<z<<" "<<w<<'\n';
#define pr(a,l,r) for(int ii=l;ii<=r;++ii) cerr<<a[ii]<<" ";ED
#define int long long
using namespace std;
const int N=2e6+5,M=2e5+5,INF=3e18;
int c,t,n,d;
int a[N],pre[N],suf[N];
int f[N],g[N];

void sol() {
	scanf("%lld%lld",&n,&d);
	for(int i=0;i<=n+1;++i) {
		pre[i]=suf[i]=f[i]=g[i]=0;
	}
	for(int i=1;i<=n;++i) {
		scanf("%lld",&a[i]);
	}
	a[0]=-INF,a[n+1]=INF;
	for(int i=0;i<=n+1;++i) {
		pre[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
		suf[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
	}
	for(int i=1;i<=n;++i) {	
		if(pre[i+1]==i) f[i]=f[pre[i]]+pre[i+1]-pre[i];
		else f[i]=0;
	}
	for(int i=n;i>=1;--i) {
		if(suf[i-1]==i) g[i]=g[suf[i]]+suf[i]-suf[i-1];
		else g[i]=0;
	}
	for(int i=1;i<=n;++i) {
		f[i]+=f[i-1];
	}
	for(int i=n;i>=1;--i) {
		g[i]+=g[i+1];
	}
	//pr(pre,1,n)
	//pr(suf,1,n)
	//pr(f,1,n)
	//pr(g,1,n)
	int ans=0;
	for(int i=1;i<n;++i) {
		int L1=suf[i-1],R1=suf[i];
		int L2=pre[i+1],R2=pre[i+2];
		//cr4(L1,R1,L2,R2)
		if(R1>i+1&&L2<i&&R1>L1&&L2<R2) {
			ans+=(R1-L1+g[L1+1]-g[R1+1])*(R2-L2+f[L2-1]-f[R2-1]);
		}
		//cr2(i,ans)
	}
	printf("%lld\n",ans);
}

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--) {
		sol();
	}
	return 0;
}
/*
0 1
8 15
0 6 10 16 21 27 33 35 

2
 
 
 for(int i=1;i<=n;++i) {	
		f[i]=f[pre[i]]+pre[i+1]-pre[i];
	}
	for(int i=n;i>=1;--i) {
		g[i]=g[suf[i]]+suf[i]-suf[i-1];
	}
*/