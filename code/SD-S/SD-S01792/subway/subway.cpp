#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1005;
int c,n,m,d,k,q,w[N],a[1005][1005],x,y;
pair<int,int>ki[N],qr[10005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++) cin>>ki[j].first>>ki[j].second;
		for(int j=1;j<=k;j++)
		{
			for(int z=1;z<=k&&z!=j;z++)
			{
				a[ki[j].first][ki[z].first]=ki[j].second+ki[z].second;
				a[ki[z].first][ki[j].first]=ki[z].second+ki[j].second;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int z=1;z<=m;z++)
			{
				a[i][j]=min(a[i][j],a[i][z]+a[z][j]);
				a[j][i]=a[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<a[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
