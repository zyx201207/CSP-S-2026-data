#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=505;
const int M=5e5+5;
int cid,n,m,d,q;
int w[M],k,a[M],t[M],x,y;
int dis[N][N];
const int inf=1e18;
struct node
{
	int idx,t;
};
vector<node> sta[M];
int read()
{
	char c=getchar_unlocked();
	int f=1,x=0;
	while(c<'0' or c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar_unlocked();
	}
	while(c>='0' and c<='9')
	{
		x=x*10+c-'0';
		c=getchar_unlocked();
	}
	return x*f;
}
void write(int x)
{
	if(x<0) x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cid=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j) dis[i][i]=0;
			else dis[i][j]=inf;
		}
	for(int i=1;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)
			a[j]=read(),t[j]=read(),sta[a[j]].push_back({i,t[j]});
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<sta[i].size();j++)
		{
			node u=sta[i][j];
			for(int k=j+1;k<sta[i].size();k++)
			{
				node v=sta[i][k];
				dis[u.idx][v.idx]=dis[v.idx][u.idx]=min(dis[u.idx][v.idx],u.t+v.t);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		cin>>x>>y;
		int ans=inf;
		for(auto u:sta[x])
			for(auto v:sta[y])
				ans=min(ans,u.t+v.t+dis[u.idx][v.idx]);
		write(ans+w[x]+w[y]);
		putchar('\n');
	}
	// cout<<clock()<<'\n';
	return 0;
}