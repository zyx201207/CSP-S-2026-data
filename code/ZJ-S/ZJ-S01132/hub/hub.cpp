#include <bits/stdc++.h>
#define N 1000010
using namespace std;
int c,t;
int n,k;
vector<int> nxt[N];
namespace D
{
	int x,l,y;
	int F;
	void init(int u,int f,int dep)
	{
		if(dep>l) l=dep,x=u;
		for(int i=0;i<nxt[u].size();i++)
		{
			int v=nxt[u][i];
			if(v!=f&&v!=F)
				init(v,u,dep+1);
		}
	}
	vector<int> res;
	bool mak(int u,int f)
	{
		if(u==x) return res.push_back(u),1;
		for(int i=0;i<nxt[u].size();i++)
		{
			int v=nxt[u][i];
			if(v!=f&&v!=F)
				if(mak(v,u))
					return res.push_back(u),1;
		}
		return 0;
	}
	void sol(int r,int rf)
	{
		F=rf;
		res.clear();
		l=-1;
		init(r,0,0);
		l=-1,y=x;
		init(y,0,0);
		mak(y,0);
	}
}
int ans;
int f[N],g[N];
int F;
int mxd[N];
bool fg[N];
void dfs(int u,int f)
{
	mxd[u]=-1,fg[u]=0;
	for(int i=0;i<nxt[u].size();i++)
	{
		int v=nxt[u][i];
		if(v!=f&&v!=F)
			dfs(v,u),mxd[u]=max(mxd[u],mxd[v]);
	}
	mxd[u]++;
}
priority_queue<pair<int,int> > q;
void gts(int r,int rf,int* v)
{
	F=rf;
	D::sol(r,rf);
	for(int i=1;i<=k;i++) v[i]=0;
	int l=D::res.size()/2;
	int b=D::res[l];
	dfs(b,0),q.push({mxd[b],b});
	for(int i=1;i<=k;i++)
	{
		int u=q.top().second;q.pop();
		fg[u]=1;
		for(int i=0;i<nxt[u].size();i++)
		{
			int v=nxt[u][i];
			if(!fg[v]&&v!=F) q.push({mxd[v],v});
		}
		if(q.empty()) break;
		v[i]=q.top().first+1;
	}
	while(!q.empty()) q.pop();
}
void sol(int x,int y)
{
	gts(x,y,f);
	gts(y,x,g);
	for(int i=1;i<k;i++) ans=min(ans,max(f[i],g[k-i]));
}
void cac(int u,int f)
{
	if(f) sol(u,f);
	for(int i=0;i<nxt[u].size();i++)
	{
		int v=nxt[u][i];
		if(v!=f)
			cac(v,u);
	}
}
inline void Main()
{
	cin>>n>>k;ans=1e9;
	for(int i=1;i<=n;i++) nxt[i].clear();
	static int u,v;
	for(int i=1;i<n;i++) cin>>u>>v,nxt[u].push_back(v),nxt[v].push_back(u);
	cac(1,0);
	gts(1,0,g);
	ans=min(ans,g[k]);
	cout<<ans<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--) Main();
	return 0;
}
