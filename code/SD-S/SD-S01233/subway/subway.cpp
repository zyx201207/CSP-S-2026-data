#include<bits/stdc++.h>
using namespace std;
const int mx=5e5;
int w[mx+10];
vector<int> g[mx+10],lenn[mx+10];
long long f[510][510];
inline int read()
{
	int v=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		v=(v<<1)+(v<<3)+(ch^48);
		ch=getchar();
	}
	return v;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j,k,cc,n,m,d,q,cnt,cmt,x,y;
	long long ans;
	cc=read();n=read();
	m=read();d=read();q=read();
	for(i=1;i<=m;++i) w[i]=read();
	for(i=1;i<=n;++i)
	{
		cnt=read();
		while(cnt--)
		{
			x=read();y=read();
			g[x].push_back(i);
			lenn[x].push_back(y);
		}
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(i!=j) f[i][j]=1e18;
	for(i=1;i<=m;++i)
	{
		cnt=g[i].size();
		for(j=0;j<cnt;++j)
		for(k=0;k<cnt;++k)
		{
			x=g[i][j];y=g[i][k];
			f[x][y]=min(f[x][y],(long long)
			lenn[i][j]+lenn[i][k]);
			f[y][x]=min(f[y][x],(long long)
			lenn[i][j]+lenn[i][k]);
		}
	}
	for(k=1;k<=n;++k)
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		x=read();y=read();ans=1e18;
		cnt=g[x].size();cmt=g[y].size();
		for(i=0;i<cnt;++i)
		for(j=0;j<cmt;++j)
			ans=min(ans,f[g[x][i]][g[y][j]]
			+lenn[x][i]+lenn[y][j]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
