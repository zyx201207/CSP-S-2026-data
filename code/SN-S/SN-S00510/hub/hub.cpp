//徐语瞳 SN-S00510 西安翱翔中学
#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<int> G[4005];
int fu[4005][4005],u[4005],v[4005],ls[4005];//ls存储选中的点
int f[4004],deep[4004],h[4005],tp[4005],siz[4005];//父亲，深度，重儿子编号，重链顶点，子树大小 
int ans,n,k;
void dfs1(int x,int fa)
{
	f[x]=fa;
	deep[x]=deep[fa]+1;
	siz[x]=1;
	h[x]=0;
	int mx=0;
	for(auto &it:G[x])
	{
		if(it!=fa)
		{
			dfs1(it,x);
			siz[x]+=siz[it];
			if(siz[it]>mx)
			{
				mx=siz[it];
				h[x]=it;
			}
		}
	}
}
void dfs2(int x,int top)
{
	tp[x]=top;
	for(auto &it:G[x])
	{
		if(it!=f[x])
		{
			if(it==h[x]) dfs2(it,top);
			else dfs2(it,it);
		}
	}
}
int lca(int x,int y)
{
	while(tp[x]!=tp[y])
	{
		if(deep[tp[x]]>deep[tp[y]]) x=f[tp[x]];
		else y=f[tp[y]];
	}
	if(deep[x]>deep[y]) return y;
	return x;
}
//考虑搜索时使选中点的编号递增，优化复杂度
//考虑搜索时查询连通块数量，进行剪枝 
void dfsA(int num,int cnt)//num:当前选中的点的数量，cnt:当前形成的连通块数量
{
	if(num==k)
	{
		int mx=0;
		for(int i=1;i<=n;i++)
		{
			int mn=1e9;
			for(int j=1;j<=num;j++)
			{
				int LCA=lca(i,ls[j]);
				mn=min(mn,deep[i]-deep[LCA]+deep[ls[j]]-deep[LCA]);
			}
			mx=max(mn,mx);
		}
		ans=min(ans,mx);
		return ;
	}
	for(int i=ls[num]+1;i<=n;i++)
	{
		if(n-i+1<k-num) break;
		int flag=1;
		for(int j=1;j<=num;j++)
		{
			if(fu[i][ls[j]])
			{
				flag=0;
				break;
			}
		}
		if(cnt+flag>2) continue;
		ls[num+1]=i;
		dfsA(num+1,cnt+flag);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>u[i]>>v[i];
			G[u[i]].push_back(v[i]);
			G[v[i]].push_back(u[i]);
			fu[u[i]][v[i]]=1;
			fu[v[i]][u[i]]=1;
		}
		ans=1e9;
		dfs1(1,0);
		dfs2(1,1);
		dfsA(0,0);
		cout<<ans<<"\n";
		for(int i=1;i<n;i++)
		{
			G[i].clear();
			fu[u[i]][v[i]]=0;
			fu[v[i]][u[i]]=0;
		}
		G[n].clear();
	}
	return 0;
}
