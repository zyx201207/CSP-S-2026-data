#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
long long c,n,m,d,q,x,y,ans;
long long w[500050],k[500050];
vector<pair<long long,long long> > sub[5005],g[5005];
bool vis[50005],used[50005];
//每条地铁到的站台/站台到站厅的时间 每个站厅可以去的地铁线/从站厅到站点的时间
void dfs(long long u,long long goal,long long line,long long step)
{
//	cout<<u<<endl;
	if(step>ans) return ;
	if(u==goal&&line==0) 
	{
	//	cout<<"step="<<step<<endl;
		ans=min(ans,step);
		return ;
	}
	if(line==0)
	{
		for(long long i=0;i<g[u].size();i++)
		{
			pair<long long,long long> tmp=g[u][i];
			long long xian=tmp.first;
			long long tim=tmp.second;
			if(used[xian]) continue;
		//	cout<<"1:  "<<u<<" "<<xian<<" "<<tim<<endl;
			for(long long j=0;j<sub[xian].size();j++)
			{
				pair<long long,long long> tmpp=sub[xian][j];
				if(tmpp.first==u)
				{
		//			cout<<"2:  "<<u<<" "<<xian<<" "<<step+tmpp.second<<endl;
					dfs(u,goal,xian,step+tmpp.second);
				}
			}
		}
	}
	else
	{
		for(long long i=0;i<sub[line].size();i++)
		{
			long long to=sub[line][i].first;
			long long tim=sub[line][i].second;
			if(to==u||vis[to]) continue;
			vis[to]=1;
		//	cout<<"3:  "<<to<<" "<<line<<" "<<step<<endl;
			used[line]=1;
			dfs(to,goal,0,step+tim);
			vis[to]=0;
			used[to]=0;
			vis[to]=1;
			dfs(to,goal,line,step);	
			vis[to]=0;
			used[to]=0;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(long long i=1;i<=m;i++)
	{
		w[i]=read();
	}
	for(long long i=1;i<=n;i++)
	{
		k[i]=read();
		for(long long j=1;j<=k[i];j++)
		{
			x=read();y=read();
			sub[i].push_back({x,y});
			g[x].push_back({i,y});
		}
	}
	while(q--)
	{
		memset(vis,0,sizeof(vis));
		memset(used,0,sizeof(used));
		x=read();
		y=read();
		ans=LLONG_MAX;
		vis[x]=1;
		dfs(x,y,0,0);
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
}//12pts
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
//0 1 2 10 2
//1 2
//2 1 1 2 2
//1 2