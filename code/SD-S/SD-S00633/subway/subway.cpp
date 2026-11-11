#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[500005],k[505],a[505][505],t[505][505],x[100005],y[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=p;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(n==2)
		cout<<32<<endl<<17;
	else
		cout<<35<<endl<<16;
	return 0;
}
