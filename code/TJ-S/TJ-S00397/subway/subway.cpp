#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,sum=0;
	cin>>c>>n>>m>>d>>q;
	int w[m+1],k[n+1],a[n+1],t[n+1],x[q+1],y[q+1],ans[q+1];
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=i;j++)
		{
			cin>>a[j]>>t[j];
		}
	}
	for (int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		sum=0;
		for (int j=x[i];j<=y[i];j++)
		{
			sum+=t[i];
		}
		ans[i]=sum*9/2;
	}
	for (int i=1;i<=q;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
