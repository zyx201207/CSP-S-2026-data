#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>G[N];
int dep[N],anc[20][N];
int f[N],vis[N];
int n,k,ans;
int c,T;
void dfs(int u,int fa)
{
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)
		{
			continue;
		}
		dep[v]=dep[u]+1;
		anc[0][v]=u;
		dfs(v,u);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])
	{
		swap(x,y);
	}
	for(int i=20;i>=0;i--)
	{
		if(dep[anc[i][x]]>=dep[y])
		{
			x=anc[i][x];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(int i=20;i>=0;i--)
	{
		if(dep[anc[i][x]]!=dep[anc[i][y]])
		{
			x=anc[i][x];
			y=anc[i][y];
		}
	}
	
	return anc[0][x];
}
void dfs2(int x)
{
	vis[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		if(f[G[x][i]]&&!vis[G[x][i]])
		{
			dfs2(G[x][i]);
		}
	}
}
void dfs1(int x,int num)
{
	if(x==n+1)
	{
		if(num!=0)
		{
			return;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(f[i]&&!vis[i])
			{
				dfs2(i);
				cnt++;
			}
		}
		if(cnt>2)
		{
			return;
		}
		int ret=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]!=1)
			{
				int minn=1e9;
				for(int j=1;j<=n;j++)
				{
					if(f[j]==1)
					{
						minn=min(minn,dep[i]+dep[j]-2*dep[lca(i,j)]);
					}
				}
				ret=max(ret,minn);
			}
		}
		ans=min(ans,ret);
		return;
	}
	if(num>=1)
	{
		f[x]=1;
		dfs1(x+1,num-1);
		f[x]=0;
	}
	dfs1(x+1,num);
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		G[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=n;j++)
		{
			anc[i][j]=anc[i-1][anc[i-1][j]];
		}
	}
	ans=1e9;
	dfs1(1,k);
	cout<<ans<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
/*
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
froepen("hub.in","w",stdin);
froepen("hub.out","r",stdout);
int mian()
你被骗了(此处应有never gonna give you up，但是我不记得网址) 
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
如果你看上面这些  是斜着的，说明你发现了这是注释区 
你说得对，但是我写不出T3T4（？！区区？！） 
T3好像是个dp？但是我只会n^3，还有1.5h，应该能打出n^2的
话说今年T2是不是太简单了
T4看一眼就丧失阅读欲望了。
唉，像我这样的人拿个NOIP 1=都是奢望啊，人生真是越活越没希望了
之前初一初二时还知道拿S 1=，现在感觉NOIP 1=也没啥用了
可是，突然还想...再玩几把...扫雷...啊...
你知道吗，中文输入法真是太好用了，似乎有些地方没有
赛前我押题贪心+码量+dp+请输入文本，应该算押中了吧
话说T2其实也没啥码量？ 
我知道你很想知道我的luogu uid但是我忘了
这波卡了
我要上ZJ CSP-S迷惑行为大赏
NOIP迷惑行为大赏会有体验选手吗，有的话我也会来的
T4刚开始没看题面，打了个lca谁能绷住
不对还真要用lca，我都删了
T4暴力打了1h之人，成功写不了T3
*/
