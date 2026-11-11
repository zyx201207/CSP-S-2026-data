#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,d,Q,T,s,e,ans;
int w[500005],k[505];
vector<int> g[505];
struct edge
{
	int cnt,val;
} change[505][505];
struct node
{
	int id,t;
};
vector<node> p[500005];
void dfs(int id,int u,int res,int st)
{
	if(u==e)
	{
		int a,b;
		for(int i=0;i<p[s].size();i++)
		{
			if(p[s][i].id==st) { a=p[s][i].t;break; }
		}
		for(int i=0;i<p[e].size();i++)
		{
			if(p[e][i].id==id) { b=p[e][i].t;break; }
		}
		res=res+w[s]+a+w[e]+b;
		ans=min(ans,res);
		return ;
	}
	if(res>=ans) return ;
	bool flag=false;
	for(int i=0;i<g[id].size();i++)
	{
		int v=g[id][i];
		if(!flag)
		{
			if(u==v) flag=true;
			continue;
		}
		dfs(id,v,res,st);
		for(int j=1;j<=n;j++)
		{
			if(id==j) continue;
			if(change[id][j].cnt!=u) continue;
			dfs(j,u,res+change[id][j].val,st);
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	bool fa=true,fb=true;
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		if(fa && k[i]>2) fa=false;
		int a,t;
		for(int j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			g[i].push_back(a);
			p[a].push_back({i,t});
			if(T==0) T=t;
			if(fb && T!=t) fb=false;
			
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(p[i].size()==1) continue;
		for(int u=1;u<p[i].size();u++)
		{
			for(int v=0;v<u;v++)
			{
				int x=p[i][u].id,y=p[i][v].id;
				int cst=p[i][u].t+p[i][v].t;
				if(change[x][y].val==0)
				{
					change[x][y].val=change[y][x].val=cst;
					change[x][y].cnt=change[y][x].cnt=i;
					continue;
				}
				if(change[x][y].val <= cst) continue;
				else
				{
					change[x][y].val=change[y][x].val=cst;
					change[x][y].cnt=change[y][x].cnt=i;
				}
			}
		}
	}
	while(Q--)
	{
		cin>>s>>e;
		ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<g[s].size();i++) dfs(p[s][i].id,s,0,p[s][i].id);
		cout<<ans<<endl;
	}
	return 0;
} 
