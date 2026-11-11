#include<bits/stdc++.h>
using namespace std;
long long dis[510][510],w[130000],t[125260][510],a[510][125260],x[100010],y[100010],k[510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dis,0x3f,sizeof(dis));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[a[i][j]][i];
		}
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=k[i];j++) for(int l=j;l<=k[i];l++) dis[a[i][j]][a[i][l]]=min(dis[a[i][j]][a[i][l]],t[a[i][j]][i]+t[a[i][l]][i]);
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) for(int l=1;l<=m;l++) dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
	for(int i=1;i<=q;i++) cout<<dis[x[i]][y[i]]+w[x[i]]+w[y[i]]<<endl;
	return 0;
}
