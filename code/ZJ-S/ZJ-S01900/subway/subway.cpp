#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+10;
ll c,n,m,d,q,w[N],a[N][N],t[N][N],k[N],dj[N][N],X,Y;
vector<ll>g[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dj,0x3f,sizeof(dj));
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)
	cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			g[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			int x=g[i][j];
			for(int e=1;e<=k[x];e++)
			{
				dj[i][a[x][e]]=0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			int x=g[i][j];
			for(int e=1;e<=k[x];e++)
			{
				int y=a[x][e];
				if(y==i)
				continue;
				for(int f=0;f<g[y].size();f++)
				{
					int h=g[y][f];
					if(h==x)
					continue;
					for(int o=1;o<=k[h];o++)
					{
						int vv=a[h][o];
						if(vv==y)
						continue;
						dj[i][vv]=t[x][i]+t[h][vv];
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=n;k++)
		{
			for(int j=1;j<=n;j++)
			{
				dj[i][j]=min(dj[i][j],dj[i][k]+dj[k][j]);
			}
		}
	}
	while(q--)
	{
		cin>>X>>Y;
		cout<<w[X]+dj[X][Y]+w[Y]<<'\n';
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
