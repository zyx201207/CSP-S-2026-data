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
int c,n,m,d,Q;
const int N=1000005;
const int M=10000;
int w[N];
struct edge{
	int v;
	int w;
};
vector <edge> e[N];
int ans[M][M];
int dis[N];
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
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd,n=rd,m=rd,d=rd,Q=rd;
	for(int i=1;i<=m;i++)
	{
		w[i]=rd;
	}
	for(int i=1;i<=n;i++)
	{
		int k=rd;
		struct nd{
			int v;
			int w;
		};
		vector <nd> st;
		for(int j=1;j<=k;j++)
		{
			int vv=rd,ww=rd;
			if(!st.empty())
			{
				for(auto eg:st)
				{
					int u=eg.v,w1=eg.w;
					e[u].push_back({vv,w1+ww});
					e[vv].push_back({u,w1+ww});
				}
			}
			st.push_back({vv,ww});
		}
	}
	for(int i=1;i<=m;i++)
	{
		memset(dis,0x3f3f3f3f,sizeof(dis));
		memset(vis,false,sizeof(vis));
		dis[i]=0;
		dij(i);
		for(int j=1;j<=m;j++)
		{
			if(i==j)
			{
				ans[i][j]=0;
				continue;
			}
			ans[i][j]=dis[j]+w[i]+w[j];
		}
	}
	while(Q--)
	{
		int i=rd,j=rd;
		cout<<ans[i][j]<<"\n";
	}
	return 0;
}
/*
大概仅通过样例1~8
预计32pts
性质B未打(32pts)
*/
