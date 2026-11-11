#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=5e5+15;
int c,n,m,d,q;
int p[M],k[N];
int f[N][N];
vector< pair<int,int> > t[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,tm;
			cin>>x>>tm;
			t[x].push_back({i,tm});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<t[i].size();j++)
			for(int k=0;k<t[i].size();k++)
			{
				int u=t[i][j].first,y=t[i][j].second;
				int v=t[i][k].first,z=t[i][k].second;
				f[u][v]=f[v][u]=(f[u][v]>y+z)?(y+z):f[u][v];
			}
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		{
			if(i==k) continue;
			for(int j=i+1;j<=n;j++)
				if(f[i][j]>f[i][k]+f[k][j])
					f[i][j]=f[j][i]=f[i][k]+f[k][j];
		}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=p[x]+p[y],res=1e18;
		for(int j=0;j<t[x].size();j++)
			for(int k=0;k<t[y].size();k++)
			{
				int u=t[x][j].first,w=t[x][j].second;
				int v=t[y][k].first,z=t[y][k].second;
				res=(res>w+z+f[u][v])?(w+z+f[u][v]):res;
			}
		cout<<ans+res<<"\n";
	}
	return 0;
}