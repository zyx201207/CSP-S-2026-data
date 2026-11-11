#include<bits/stdc++.h>
using namespace std;
namespace Hoks
{
	#define int long long
	#define ls (p<<1)
	#define rs (ls|1)
	#define mid ((l+r)>>1)
	namespace Fast_IO
	{
		static char buf[1000000],ot[1000000],*paa=buf,*pd=buf;int length=0;
		#define getchar() paa==pd&&(pd=(paa=buf)+fread(buf,1,1000000,stdin),paa==pd)?EOF:*paa++
		inline int read()
		{
			char c(getchar());int x(0),t(1);
			while(!isdigit(c)){if(c=='-') t=-t;c=getchar();}
			while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
			return x*t;
		}
		inline void flush(){fwrite(ot,1,length,stdout);length=0;}
		inline void put(char c){if(length==999999) flush();ot[length++]=c;}
		inline void put(string s){for(char c:s) put(c);}
		inline void print(int x)
		{
			if(x<0) put('-'),x=-x;
			if(x>9) print(x/10);
			put((char)(x%10+(int)'0'));
		}
	}
	using namespace Fast_IO;
	const int N=1e6+10,INF=0x3f3f3f3f3f3f3f3f;
	int n,k,c,p,mx,rt,fa[N],dep[N];vector<int>e[N],g[N],h[N];
	int a[N],b[N],rtg,rth;
	inline void dfslen1(int u,int f,int d)
	{
		if(d>mx) p=u,mx=d;
		for(int v:e[u]) if(v!=f) dfslen1(v,u,d+1);
	}
	inline void dfs(int u,int ff)
	{
		fa[u]=ff;dep[u]=dep[ff]+1;
		for(int v:e[u]) if(v!=ff) dfs(v,u);
	}
	inline void solve2()
	{
		int len=n/2+1,m=n/2;
		if(k==1) return print((len+1)>>1),put('\n');
		p=m/2+3;print(max((p-(k+1)/2+1)/2,(p-k/2)/2)),put('\n');
	}
	inline void getg(int u,int nt)
	{
		for(int v:e[u])
		{
			if(v==nt||v==fa[u]) continue;
			g[u].emplace_back(v),g[v].emplace_back(u);
			getg(v,nt);
		}
	}
	inline void geth(int u,int nt)
	{
		for(int v:e[u])
		{
			if(v==nt||v==fa[u]) continue;
			h[u].emplace_back(v),h[v].emplace_back(u);
			geth(v,nt);
		}
	}
	inline void init()
	{
		if(mx&1)
		{
			int x=p;
			for(int i=mx/2;i>=1;i--) x=fa[x];
			getg(x,fa[x]);geth(rt,x);rtg=x;rth=rt;
		}
		else
		{
			int x=p;
			for(int i=mx/2;i>1;i--) x=fa[x];
			getg(fa[x],0);geth(rt,x);rtg=fa[x];rth=rt;
		}
	}
	inline void dfslen2(int u,int f,int d)
	{
		if(d>mx) p=u,mx=d;
		for(int v:g[u]) if(v!=f) dfslen2(v,u,d+1);
	}
	inline void dfslen3(int u,int f,int d)
	{
		if(d>mx) p=u,mx=d;
		for(int v:h[u]) if(v!=f) dfslen3(v,u,d+1);
	}
	inline void dfs2(int u,int ff)
	{
		fa[u]=ff;dep[u]=dep[ff]+1;
		for(int v:g[u]) if(v!=ff) dfs2(v,u);
	}
	inline void dfs3(int u,int ff)
	{
		fa[u]=ff;dep[u]=dep[ff]+1;
		for(int v:h[u]) if(v!=ff) dfs3(v,u);
	}
	inline void gtgm(int u,int ff)
	{
		for(int v:g[u]) if(v!=ff) gtgm(v,u),a[u]=max(a[u],a[v]+1);
	}
	inline void gthm(int u,int ff)
	{
		for(int v:h[u]) if(v!=ff) gthm(v,u),b[u]=max(b[u],b[v]+1);
	}
	inline bool check(int x)
	{
		int s=0;
		for(int i=1;i<=n;i++) 
//			s+=(a[i]>=x)+(b[i]>=x);
			if(a[i]>=x||b[i]>=x) s++;
		return s<=k;
	}
	inline int please(int x1,int x2)
	{
		p=mx=0;dfslen2(rtg,0,0);
		rtg=p;p=mx=0;dfslen2(rtg,0,0);
		dfs2(rtg,0);rtg=p;
		for(int i=(mx+x1)/2;i>=1;i--) rtg=fa[rtg];
		p=mx=0;dfslen3(rth,0,0);
		rth=p;p=mx=0;dfslen3(rth,0,0);
		dfs3(rth,0);rth=p;
		for(int i=(mx+x2)/2;i>=1;i--) rth=fa[rth];
		gtgm(rtg,0);gthm(rth,0);
		int l=0,r=n,res=0;
		while(l<=r)
			if(check(mid)) res=mid,r=mid-1;else l=mid+1;
		return res;
	}
	inline void solve()
	{
		for(int i=1;i<=n;i++) e[i].clear(),g[i].clear(),h[i].clear(),a[i]=b[i]=dep[i]=fa[i]=0;
		n=read(),k=read();rtg=rth=0;
		for(int i=1,x,y;i<n;i++) x=read(),y=read(),e[x].emplace_back(y),e[y].emplace_back(x);
		if(c==13||c==14) return solve2();
		p=mx=0;dfslen1(1,0,0);
		rt=p;p=mx=0;dfslen1(rt,0,0);
		dfs(rt,0);init();
		int res=please(0,0);
		res=min(res,please(0,1));
		res=min(res,please(1,0));
		res=min(res,please(1,1));
//		cout<<rtg<<" "<<rth<<endl;
		print(res);put('\n');
	}
	inline void main()
	{
		int T=1;
		c=read();
		T=read();
		while(T--) solve();
		flush();return;
	}
}
signed main()
{
//	system("fc hub2.ans hub.out");
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	Hoks::main();
	genshin:;return 0;
}
