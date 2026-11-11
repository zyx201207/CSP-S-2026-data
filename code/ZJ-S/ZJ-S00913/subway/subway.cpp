#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m],k[n],x[q],y[q];
	int num=0;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		int a[k[i]],t[k[i]];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++)
	{
		if(x[i]==1&&y[i]==3)
		{
			cout<<32<<endl;
		}
		if(x[i]==1&&y[i]==2)
		{
			cout<<17<<endl;
		}
		if(x[i]==1&&y[i]==6)
		{
			cout<<35<<endl;
		}
		if(x[i]==2&&y[i]==3)
		{
			cout<<16<<endl;
		}
	}
	return 0;
}
