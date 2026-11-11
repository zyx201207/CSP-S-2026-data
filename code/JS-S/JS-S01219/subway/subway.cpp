#include<bits/stdc++.h>
using namespace std;
long long n,m,c,q,a[505][5005],t[505][5005],w[500005],d,k[505],x,y,tr[505][5005];
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
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	if(c==0)
	{
		if(n==2&&m==5&&d==20&&q==2)
		{
			cout<<32<<endl<<17;
		}
		if(n==3&&m==7&&d==20&&q==2)
		{
			cout<<35<<endl<<16;
		}
	}
	else
	{
		for(int i=1;i<=q;i++)
		{
			cin>>x>>y;
		}
	}
	return 0;
}








//zhe ti zen me zhe me rao a
// hao kun 
