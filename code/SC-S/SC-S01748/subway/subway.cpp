#include<bits/stdc++.h>
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
#define int long long
#define code using
#define by namespace
#define plh std
code by plh;
namespace fastio
{
	int read()
	{
		int z=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9')
		{
			if(c=='-')
			{
				f=-1;
			}
			c=getchar();
		}
		while(c>='0'&&c<='9')
		{
			z=z*10+c-'0';
			c=getchar();
		}
		return z*f;
	}
	void write(int x)
	{
		if(x<0)
		{
			putchar('-');
			x=-x;
		}
		static int top=0,stk[106];
		while(x)
		{
			stk[++top]=x%10;
			x/=10;
		}
		if(!top)
		{
			stk[++top]=0;
		}
		while(top)
		{
			putchar(char(stk[top--]+'0'));
		}
	}
	void read(int *st,int *ed)
	{
		for(;st!=ed;st++)
		{
			(*st)=read();
		}
	}
	void write(int *st,int *ed)
	{
		for(;st!=ed;st++)
		{
			write(*st);
			putchar(' ');
		}
	}
}
using namespace fastio;
const int N=506,M=5e5+6;
int n,m,d,q,a[M],mp[N][N],dis[N][N];
bool vis[N];
vector<pair<int,int>>v[N];
vector<int>vv[M],v1[M];
void dijkstra(int st,int *dis)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=2e18;
		vis[i]=0;
	}
	dis[st]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push(make_pair(dis[st],st));
	while(!pq.empty())
	{
		pair<int,int>p=pq.top();
		pq.pop();
		int u=p.second;
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(auto i:v[u])
		{
			if(dis[i.first]>dis[u]+i.second)
			{
				dis[i.first]=dis[u]+i.second;
				pq.push(make_pair(dis[i.first],i.first));
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C=read();
	n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			mp[i][j]=2e18;
		}
	}
	read(a+1,a+m+1);
	for(int i=1,k;i<=n;i++)
	{
		k=read();
		for(int j=1,x,y;j<=k;j++)
		{
			x=read(),y=read();
			int len=vv[x].size();
			for(int l=0;l<len;l++)
			{
				mp[vv[x][l]][i]=mp[i][vv[x][l]]=min(mp[i][vv[x][l]],v1[x][l]+y);
			}
			v1[x].push_back(y);
			vv[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[i][j]<=(int)(1e18))
			{
				v[i].push_back(make_pair(j,mp[i][j]));
				v[j].push_back(make_pair(i,mp[i][j]));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dijkstra(i,dis[i]);
	}
	while(q--)
	{
		int x=read(),y=read(),ans=2e18;
		int len1=vv[x].size(),len2=vv[y].size();
		for(int i=0;i<len1;i++)
		{
			for(int j=0;j<len2;j++)
			{
				ans=min(ans,a[x]+a[y]+v1[x][i]+v1[y][j]+dis[vv[x][i]][vv[y][j]]);
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}