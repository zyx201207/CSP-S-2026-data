#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N];
vector<pair<int,int> > a[N],t[505];
long long dis[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int l;
		cin>>l;
		while(l--)
		{
			int x,y;
			cin>>x>>y;
			t[i].push_back({x,y});
			a[x].push_back({i,y});
		}
	}
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<t[i].size();j++)
		{
			int x=t[i][j].first,y=t[i][j].second;
			for(int k=0;k<a[x].size();k++)	dis[i][a[x][k].first]=min(dis[i][a[x][k].first],1ll*a[x][k].second+y);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++) dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=dis[0][0];
		for(int i=0;i<a[x].size();i++)
			for(int j=0;j<a[y].size();j++) ans=min(ans,dis[a[x][i].first][a[y][j].first]+a[x][i].second+a[y][j].second+w[x]+w[y]);
		cout<<ans<<"\n";
	}
	return 0;
}
//fc F:\SD-S01036ÖÜÅôÔ¶\T2\1.out F:\SD-S01036ÖÜÅôÔ¶\T2\subway7.ans 
