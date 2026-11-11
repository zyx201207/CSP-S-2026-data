#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int inf=1e18,N=1e6+6,M=505;
int read()
{
	int x=0,fl=1;char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-'){fl=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*fl;
}
vector<pii>vec[N];
int dis[M][M],n,m,Q,w[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();n=read();m=read();read();Q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int K=read();
		for(int j=1;j<=K;j++)
		{
			int t=read(),v=read();
			vec[t].push_back({i,v});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=(i!=j)*inf;
	for(int i=1;i<=m;i++)
	{
		int len=vec[i].size();
		for(int j=0;j<len;j++)
			for(int k=j+1;k<len;k++)
			{
				int x=vec[i][j].fi,y=vec[i][k].fi,v=vec[i][j].se+vec[i][k].se;
				dis[x][y]=min(dis[x][y],v);
				dis[y][x]=min(dis[y][x],v);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=Q;i++)
	{
		int x=read(),y=read(),ans=inf;
		int lenx=vec[x].size(),leny=vec[y].size();
		for(int i=0;i<lenx;i++)
			for(int j=0;j<leny;j++)
				ans=min(ans,vec[x][i].se+vec[y][j].se+dis[vec[x][i].fi][vec[y][j].fi]);
		cout<<ans+w[x]+w[y]<<'\n'; 
	}
	return 0;
}
