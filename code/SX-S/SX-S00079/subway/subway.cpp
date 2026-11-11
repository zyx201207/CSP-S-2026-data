#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const ll N=2e4+5;
ll c,n,m,d,q,w[N],k[N],a[505][N],b[1005][1005],t[N][505],zd[1005][1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(ll i=1;i<505;i++) for(ll j=1;j<505;j++) zd[i][j]=1e18;
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)  cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		cin>>k[i];
		for(ll j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[a[i][j]][i];
			if(j>1)
			{
				b[a[i][j-1]][a[i][j]]=t[a[i][j-1]][i]+t[a[i][j]][i];
				zd[a[i][j-1]][a[i][j]]=t[a[i][j-1]][i]+t[a[i][j]][i];
			}
		}
	}
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			for(ll l=1;l<=m;l++)
			{
				if(zd[i][l]>zd[i][j]+zd[j][l]) zd[i][l]=zd[i][j]+zd[j][l];
			}
		}
	}
	for(ll i=1;i<=q;i++)
	{
		ll x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+zd[x][y]<<"\n";
	}
	return 0;
}