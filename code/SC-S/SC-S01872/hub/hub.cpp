#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int read()
{
	int f=1,k=0,c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+(c^48);
	return k*f;
}
int c,t,n,k,head[N],tot,f[N],g[N],vis[N],dep[N];
//f:最远的未覆盖点，g:最近研究室 
struct edge{int v,nxt;}eg[2*N];
void add(int u,int v)
{
	eg[++tot].v=v;
	eg[tot].nxt=head[u];
	head[u]=tot;
}
void init()
{
	tot=0;
	for(int i=1;i<=n;i++) head[i]=0;
}
int cnt,sum,cnt1,siz[N],mxdep[N];
int dfs2(int u,int fa,int upmx,int lim)
{
	if(vis[u]||upmx>lim) return 0;
//	cout<<"iegbe";
	int gsum=0,re=0;
	for(int i=head[u];i;i=eg[i].nxt)
	{
		int v=eg[i].v;
		if(v==fa) continue;
		if(g[v]<=n) gsum++,re=v;
	}
	pair<int,int> mx={upmx,0},mx1={0,0};
	for(int i=head[u];i;i=eg[i].nxt)
	{
		int v=eg[i].v;
		if(v==fa) continue;
		pair<int,int> qwq={f[v]+1,v};
		if(qwq>mx) swap(qwq,mx);
		if(qwq>mx1) swap(qwq,mx1);	
	}
	if(mx1.first==lim||mx.first>lim) return u;
	int mxx=u;
	for(int i=head[u];i;i=eg[i].nxt)
	{
		int v=eg[i].v;
		if(v==fa||g[v]>n) continue;
		int qwq=dfs2(v,u,(mx.second==v?mx1.first+1:mx.first+1),lim);
		if(dep[qwq]>dep[mxx]) mxx=qwq;
	}
	return mxx;
}
void dfs(int u,int fa,int lim)
{
	dep[u]=dep[fa]+1;
	vis[u]=f[u]=mxdep[u]=0;
	g[u]=1e9;
	int gsum=0;
	for(int i=head[u];i;i=eg[i].nxt)
	{
		int v=eg[i].v;
		if(v==fa) continue;
		dfs(v,u,lim);
		f[u]=max(f[u],f[v]+1);
		g[u]=min(g[u],g[v]+1);
		mxdep[u]=max(mxdep[u],mxdep[v]+1);
		if(g[v]<=n) gsum++;
	}
	if(f[u]+g[u]<=lim)
	{
//		if(u==1) cout<<" iefe "<<f[u]<<" "<<g[u]<<"\n";
		f[u]=-1;
	}
	else if(u==1)
	{
		int qwq=dfs2(1,0,0,lim);
		vis[qwq]=1,cnt++;
//		if(gsum!=1) vis[u]=1,g[u]=0,f[u]=-1,cnt++;
	}
	else if(f[u]==lim) vis[u]=1,g[u]=0,f[u]=-1,cnt++;
}
int dfs1(int u,int fa) //离u点最近的染色点的距离（子树内） 
{
	siz[u]=vis[u];
//	if(vis[u]) cout<<"sifw "<<u<<"\n";
	int mx=-1e9,mx1=-1e9,cnt2=0;
	for(int i=head[u];i;i=eg[i].nxt)
	{
		int v=eg[i].v;
		if(v==fa) continue;
		int qwq=dfs1(v,u)+1;
		if(qwq>=0) cnt2++;
		if(qwq>mx) swap(qwq,mx);
		if(qwq>mx1) swap(qwq,mx1);
		siz[u]+=siz[v];
	}
	if((cnt-siz[u]!=0&&siz[u]!=0||mx>=0&&mx1>=0)&&!vis[u]) cnt1++;
	if(vis[u]||cnt2>=3||cnt-siz[u]!=0&&cnt2>=2)
	{
		sum=max(sum,mx-1);
		mx=0;
	}
	else sum=max({sum,mx-1,mx+mx1-1});
	return mx;
}
int check(int x)
{
	cnt=sum=cnt1=0;
	dfs(1,0,x);
	int _=dfs1(1,0);
//	cout<<cnt<<" "<<cnt1<<" "<<sum<<"\n";
	cnt+=cnt1;
	return cnt-sum;
}
void solve()
{
	n=read();k=read();
	init();
	for(int i=1,u,v;i<n;i++)
	{
		u=read();v=read();
		add(u,v);
		add(v,u);
	}
	int l=0,r=n,ans=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)<=k) ans=mid,r=mid-1;
		else l=mid+1;
	}
//	cout<<check(2)<<"\n";
//	cout<<check(9)<<"\n";
//	cout<<check(10)<<"\n";
	cout<<ans<<"\n";
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--) solve();
	return 0;
}