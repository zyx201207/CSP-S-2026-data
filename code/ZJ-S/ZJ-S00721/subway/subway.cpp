#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,w[500005],ans=0x3f3f3f3f;
ll lu[505][500005];
ll t[505][500005];
ll z[500005][505],zc[500005];
ll zhuan(ll a,ll a1,ll b,ll b1)
{
	return t[a1][a]+t[a1][b]+t[b1][b];
}
int main()
{
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			lu[i][j]=x;
			t[i][x]=y;
			z[x][zc[x]]==i;
			zc[x]++;
		}
	}
	for(ll i=q2;q2<=q;q2++)
	{
		cin>>x>>y;
		for(ll i=1;i<=zc[x];i++)
		{
			for(ll j=1;j<=zc[y];j++)
			if(lu[])
		}
	}
}
