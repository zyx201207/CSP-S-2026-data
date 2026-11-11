#include<bits/stdc++.h>
using namespace std;
const int N=500005;
struct station{
	long long line;
	long long dis;
};
long long c,n,m,d,q,kk;
long long ans,x,y;
long long w[N],g[500005];
station st[500005][25];
long long mp[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(mp,0x3f,sizeof(mp));
	for(long long i=1;i<=505;i++)
		mp[i][i]=0;
	for(long long i=1;i<=m;i++)
		cin>>w[i];
		
	for(long long i=1;i<=n;i++)
	{
		cin>>kk;
		for(long long j=1;j<=kk;j++)
		{
			cin>>x>>y;
			g[x]++;
			st[x][g[x]].line=i,st[x][g[x]].dis=y;
		}
	}
	for(long long i=1;i<=m;i++)
		for(long long j=1;j<=g[i];j++)
			for(long long k=1;k<=g[i];k++)
				mp[st[i][j].line][st[i][k].line]=min(mp[st[i][j].line][st[i][k].line],st[i][j].dis+st[i][k].dis);
	
	for(long long k=1;k<=n;k++)
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=n;j++)
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	
	for(long long i=1;i<=q;i++)
	{
		cin>>x>>y;
		ans=999999999;
		for(long long j=1;j<=g[x];j++)
			for(long long k=1;k<=g[y];k++)
				ans=min(ans,mp[st[x][j].line][st[y][k].line]+st[x][j].dis+st[y][k].dis);
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}