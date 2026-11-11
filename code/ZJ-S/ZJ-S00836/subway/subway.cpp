#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5,M=5e5+5,INF=0x3f3f3f3f3f3f3f3f;
int dis[N][N],n,m,p,d,q,w[M];
vector<pair<int,int> > v[M];
inline void read(int& x)
{
	char c;x=0;
	c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') x=x*10+c-'0',c=getchar();
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(p),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++)
		read(w[i]);
	for(int i=1;i<=n;i++)
	{
		int cnt;
		read(cnt);
		for(int j=1;j<=cnt;j++)
		{
			int x,y;
			read(x),read(y);
			v[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=m;k++)
		for(int i=0;i<v[k].size();i++)
			for(int j=0;j<i;j++)
			{
				int s1=v[k][i].first,t1=v[k][i].second,s2=v[k][j].first,t2=v[k][j].second;
				dis[s2][s1]=dis[s1][s2]=min(dis[s1][s2],t1+t2);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		read(x),read(y);
		int ans=INF;
		for(auto k:v[x])
			for(auto j:v[y])
				ans=min(ans,k.second+j.second+dis[k.first][j.first]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}