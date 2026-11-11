#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[550001];
vector<int> a[501];
vector<int> t[501];
int zta[550001][21],ztt[550001][21];
int k[501];
int mp[501][501],f[501][501];
signed main()
{
	memset(mp,0x3f,sizeof mp);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int i,j,l;
	for(i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)
		{
			int ai,ti;
			cin>>ai>>ti;
			a[i].push_back(ai);
			t[i].push_back(ti);
			zta[ai][++zta[ai][0]]=i;
			ztt[ai][zta[ai][0]]=ti;
		}
	}
	for(i=1;i<=m;i++)
	{
		int len=zta[i][0];
		for(j=1;j<=len;j++)
		{
			for(l=j+1;l<=len;l++)
			{
				int dt=ztt[i][j]+ztt[i][l];
				mp[zta[i][j]][zta[i][l]]=min(mp[zta[i][j]][zta[i][l]],dt);
				mp[zta[i][l]][zta[i][j]]=min(mp[zta[i][l]][zta[i][j]],dt);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			f[i][j]=mp[i][j];
		}
		f[i][i]=0;
	}
	for(l=1;l<=n;l++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(f[i][j]>=f[i][l]+f[l][j])
				{
					f[i][j]=f[i][l]+f[l][j];
				}
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f,lenx=zta[x][0],leny=zta[y][0];
		for(i=1;i<=lenx;i++)
		{
			for(j=1;j<=leny;j++)
			{
				ans=min(ans,ztt[x][i]+ztt[y][j]+f[zta[x][i]][zta[y][j]]);
			}
		}
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}