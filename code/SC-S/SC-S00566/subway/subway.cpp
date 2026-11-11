#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
int read()
{
	char c=getchar();
	int f=1,x=0;
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}
void print(LL x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
const int N=505,M=5e5+5;
const LL inf=1e18;
int n,m,a[M];
vector<pair<int,int>> vec[M];
LL dis[N][N];
int main()
{
//	freopen("subway7.in","r",stdin);
//	freopen("cdo.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cout<<(sizeof(a)+sizeof(dis)+sizeof(vec))/1024/1024;
	int _,d,q;
	_=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dis[i][j]=(i==j?0:inf);
		int k=read();
		for(int j=1;j<=k;j++)
		{
			int x,y;
			x=read(),y=read();
			vec[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=m;i++)
	{
		int k=vec[i].size();
		for(int x=0;x<k;x++)
		{
			int u=vec[i][x].first,l=vec[i][x].second;
			for(int y=0;y<k;y++)
			{
				int v=vec[i][y].first,r=vec[i][y].second;
				dis[u][v]=min(dis[u][v],(LL)l+r);
				//cout<<u<<' '<<v<<' '<<l+r<<endl;
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++) cout<<i<<' '<<j<<':'<<dis[i][j]<<endl;
	while(q--)
	{
		int x,y;
		x=read(),y=read();
		LL ans=inf;
		int S=vec[x].size(),T=vec[y].size();
		for(int i=0;i<S;i++)
		{
			int u=vec[x][i].first,l=vec[x][i].second;
			for(int j=0;j<T;j++)
			{
				int v=vec[y][j].first,r=vec[y][j].second;
				ans=min(ans,dis[u][v]+l+r);
			}
		}
		ans+=a[x],ans+=a[y];
		print(ans),putchar('\n');
	}
	return 0;
}
