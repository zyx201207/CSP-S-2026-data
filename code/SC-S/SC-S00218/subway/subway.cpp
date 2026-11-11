#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<int,int>
#define v first
#define w second
const ll N=5e5+5+500;
const ll INF=1e18;
vector<pll>a[N];
int c,n,m,d,q;
int w[N];
ll f[1505][1505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	int tn=n+m;
	for(int i=1;i<=tn;i++)
	{
		for(int j=1;j<=tn;j++)
		{
			if(i==j)f[i][j]=0;
			else f[i][j]=INF;
		}
	}
	int k,x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			a[x].push_back({m+i,y});
			a[m+i].push_back({x,y});
			f[x][m+i]=y;
			f[m+i][x]=y;
		}
	}
	for(int k=1;k<=tn;k++)
	{
		for(int i=1;i<=tn;i++)
		{
			for(int j=1;j<=tn;j++)
			{
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}