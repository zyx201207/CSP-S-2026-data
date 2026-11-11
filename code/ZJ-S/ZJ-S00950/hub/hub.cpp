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
long long c,t,n,k,u,v,p[200],fa[10010],ans=LLONG_MAX,dis[200][200];
bool vis[2000];
vector<long long> g[10010];
long long find(long long x)
{
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return fa[x];
}
void dfs(long long x)
{
	if(x==k+1)
	{
		for(long long i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		long long cnt=0;
		for(long long i=2;i<=k;i++)
		{
			long long uu=find(p[i]);
			long long vv=find(p[i-1]);
			if(uu!=vv)
			{
				fa[uu]=vv;
				cnt++;
			}
		}
		if(cnt>2) return ;
		long long maxx=0;
	//	cout<<"114514"<<endl;
		for(long long i=1;i<=n;i++)
		{
			long long sum=LLONG_MAX;
			for(long long j=1;j<=k;j++)
			{
				sum=min(sum,dis[i][p[j]]);
			}
			maxx=max(maxx,sum);
		}
		ans=min(ans,maxx);
//		for(long long i=1;i<=k;i++)
//		{
//			cout<<p[i]<<" ";
//		}
//		cout<<endl;
//		cout<<ans<<endl;
		return ;
	}
	for(long long i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			p[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
void fun(long long x,long long step,long long st)
{
//	cout<<x<<endl;
	for(long long i=0;i<g[x].size();i++)
	{
		long long to=g[x][i];
		if(vis[to]) continue;
		dis[st][to]=step;
		vis[to]=1;
		fun(to,step+1,st);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		n=read();k=read();
		for(long long i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		ans=LLONG_MAX;
		for(long long i=1;i<n;i++)
		{
			u=read();
			v=read();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(long long i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			fun(i,1,i);
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				cout<<dis[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		memset(vis,0,sizeof(vis));
		dfs(1);
		if(ans==INT_MAX) ans=1;
		cout<<ans<<endl;
	}
}
//0 2
//5 2
//1 2
//2 3
//3 4
//4 5
//10 3
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//3 8
//7 9
//9 10
//啊，酸酸甜甜，31357，57981