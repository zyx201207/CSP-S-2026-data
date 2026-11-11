#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,sum=0;		
int x,y;
int w[500010],k[500010],t[501][500010],a[501][500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		sum+=w[x];
		sum+=w[y];
	}
	return 0;
}
