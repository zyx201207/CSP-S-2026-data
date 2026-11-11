#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int w[1005],k[1005],a[1005][1005],t[1005][1005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	  cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		  cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
	}
	return 0;
}
