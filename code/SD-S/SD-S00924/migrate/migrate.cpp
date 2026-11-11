#include<bits/stdc++.h>
#define int long long
#define rd read()
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int c,T;
struct edge{
	int v;
	int w;
};
const int N=1000005;
vector <edge> e[N];
int dis[N],cnt[N];
bool vis[N];
struct node{
	int dis,u;
	bool operator>(const node& a)const
	{
		return dis>a.dis;
	}
};
priority_queue <node,vector<node>,greater<node>> q;
void dij(int s)
{
	while(!q.empty())
	{
		q.pop();
	} 
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=true;
		for(auto eg:e[u])
		{
			int v=eg.v,w=eg.w;
			if(dis[v]==dis[u]+w)
			{
				cnt[v]++;
			}
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd,T=rd;
	while(T--)
	{
		int n=rd,d=rd;
		int a[n+5];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=rd;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					e[i].push_back({j,a[j]-a[i]});
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			memset(dis,0x3f3f3f3f,sizeof(dis));
			memset(cnt,0,sizeof(cnt));
			memset(vis,false,sizeof(vis));
			dis[i]=0;
			dij(i);
			for(int i=1;i<=n;i++)
			{
				if(cnt[i]==2)
				{
					ans++;
				}
			}		
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}
/*
0 1
4 2
1 2 3 4
*/ 
