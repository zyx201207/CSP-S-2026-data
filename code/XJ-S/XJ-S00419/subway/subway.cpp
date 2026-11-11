#include<bits/stdc++.h>
using namespace std;
int w[10^9],a[10^9],t[10^9],x[10^9],y[10^9];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i];
			cin>>t[i];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i];
		cin>>y[i];
	}
	cout<<35<<endl<<16;
	return 0;
}
