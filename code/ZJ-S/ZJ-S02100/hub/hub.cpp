#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define rep_(i,l,r) for(int i=(l); i>=(r); --i)
constexpr int N=1000100;
int n,k,rt,mx,sum2,a[N],a2[N],a3[N],id[N],b[N]; vector<int> v[N];
void dfs0(int u,int fa)
{
	a[u]=0,a2[u]=a3[u]=-n;
	for(int to:v[u]) if(to!=fa)
	{
		dfs0(to,u);
		if(a[to]>=a[u]) id[u]=to,a3[u]=a2[u],a2[u]=a[u],a[u]=a[to];
		else if(a[to]>=a2[u]) a3[u]=a2[u],a2[u]=a[to];
		else if(a[to]>=a3[u]) a3[u]=a[to];
	}
	++a[u],++a2[u],++a3[u];
}
void dfs1(int u,int fa)
{
	for(int to:v[u]) if(to!=fa)
	{
		b[to]=b[u]+1;
		if(to==id[u]) b[to]=max(b[to],a2[u]);
		else b[to]=max(b[to],a[u]);
		dfs1(to,u);
	}
}
int fa[N],w[N],son[N],lim,tot,mx2,mx3,vis[N];
int val[N],q[N],lft[N],rgt[N],s[N];
void dfs(int u)
{
	++tot;
	for(int to:v[u]) if(to!=fa[u])
	{
		if(a[to]<=lim) { w[u]=max(w[u],a[to]); continue; }
		++son[u],fa[to]=u;
	}
	for(int to:v[u]) if(to!=fa[u]&&a[to]>lim) dfs(to);
	if(u!=rt&&son[u]<=1&&!vis[u])
	{
		int uu=u,cnt=0; while(uu!=rt&&son[uu]<=1)
			vis[uu]=1,val[++cnt]=w[uu],uu=fa[uu];
		{
			int hd=1,tl=0,cur=1;
			rep(i,1,cnt)
			{
				while(hd<=tl&&val[i]+i>=val[q[tl]]+q[tl]) --tl;
				q[++tl]=i;
				while(cur<=cnt&&hd<=tl&&val[q[hd]]+q[hd]>=lim+cur)
				{
					rgt[cur]=q[hd]-1,++cur;
					if(q[hd]<cur) ++hd;
				}
			}
			rep(i,cur,cnt) rgt[i]=cnt;
		}
		{
			int hd=1,tl=0,cur=cnt;
			rep_(i,cnt,1)
			{
				while(hd<=tl&&val[i]+cnt-i+1>=val[q[tl]]+cnt-q[tl]+1) --tl;
				q[++tl]=i;
				while(cur>=1&&hd<=tl&&val[q[hd]]+cnt-q[hd]+1>=lim+cnt-cur+1)
				{
					lft[cur]=q[hd],--cur;
					if(q[hd]>cur) ++hd;
				}
			}
			rep_(i,cur,1) lft[i]=1;
		}
		rep(i,1,cnt) s[i]=0;
		rep(i,1,cnt) if(lft[i]<=rgt[i]) ++s[lft[i]],--s[rgt[i]+1];
		rep(i,1,cnt) s[i]+=s[i-1];
		if(son[u]==0) rep(i,1,rgt[1]) --s[i];
		int tmp=0; rep(i,1,cnt) tmp=max(tmp,s[i]);
		mx2=max(mx2,tmp);
	}
}
int chk(int d)
{
	rep(i,1,n) w[i]=son[i]=vis[i]=0;
	lim=d,tot=mx2=mx3=0,fa[rt]=0;
	dfs(rt);
	if(d>=mx) return k>=tot-(d<<1);
	return tot-mx2<=k;
}
void Solve()
{
	cin>>n>>k;
	rep(i,1,n) v[i].clear();
	rep(i,1,n-1)
	{
		int x,y; cin>>x>>y;
		v[x].emplace_back(y),v[y].emplace_back(x);
	}
	dfs0(1,0),b[1]=0,dfs1(1,0),rt=1,mx=0;
	rep(i,1,n) if((int)v[i].size()>=3)
	{
		int x=a2[i],y=a3[i],z=b[i]+1;
		if(z>y) swap(y,z); if(y>x) swap(x,y);
		if(y>=mx) mx=y,rt=i;
	}
	dfs0(rt,0); int l=0,r=n-1,mid,ans=n;
	while(l<=r) mid=l+r>>1,chk(mid)? (ans=mid,r=mid-1):l=mid+1;
	cout<<ans<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T; cin>>T>>T;
	while(T--) Solve();
	return 0;
}