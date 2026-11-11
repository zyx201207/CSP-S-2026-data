#include<bits/stdc++.h>
using namespace std;
#define ll long long
int C,n,m,d,q,w[500010],a[500010][25][2],len[500010];
ll dis[510][510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		int sz;
		cin>>sz;
		int c,v;
		for(int j=1;j<=sz;j++)
		{
			cin>>c>>v;
			a[c][++len[c]][0]=i;
			a[c][len[c]][1]=v;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=len[i];j++)
		{
			for(int k=j+1;k<=len[i];k++)
			dis[a[i][j][0]][a[i][k][0]]=min((ll)(a[i][j][1]+a[i][k][1]),dis[a[i][j][0]][a[i][k][0]]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[j][i]);
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	int l,r;
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		ll ans=1000000000000000000;
		for(int j=1;j<=len[l];j++)
		{
			for(int k=1;k<=len[r];k++)
			ans=min(ans,dis[a[l][j][0]][a[r][k][0]]+w[l]+a[l][j][1]+w[r]+a[r][k][1]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
