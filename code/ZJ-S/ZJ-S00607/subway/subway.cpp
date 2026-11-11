#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=510,inf=1e18;
int n,m,d,q,x,y;
struct edge{int to,cost;};
vector<edge>g[N];
int mp[M][M],h[N],w[N];
int xx,f;
char ch;
inline int read()
{
	f=1;
	do{ch=getchar();}
	while((ch<'0' || ch>'9') && ch!='-');
	if(ch=='-')f=-1,ch=getchar();
	xx=0;
	while(ch>='0' && ch<='9')
	{
		(xx*=10)+=ch-'0';
		ch=getchar();
	}
	return xx*f;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mp[i][j]=(i==j?0:inf);
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++)
	{
		h[i]=read();
		for(int j=1;j<=h[i];j++)
		{
			x=read();y=read();
			if(g[x].size()>=1)
				for(edge k:g[x])
					mp[i][k.to]=mp[k.to][i]=y+k.cost;
			g[x].push_back({i,y});
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	int ans=inf;
	while(q--)
	{
		ans=inf;
		x=read();y=read();
		for(edge u:g[x])for(edge v:g[y])
			ans=min(ans,mp[u.to][v.to]+u.cost+v.cost);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
/*
Fast read hurray!!!
It can run within 0.8 seconds!!!
(Before:1.3s)
*/
