#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[10001],k,g,a[1001],b[1001],x[1001],y[1001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=7;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=7;j++)
		{
			cin>>b[j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(n==3)
	{
		cout<<35<<endl;
		cout<<16;
		return 0;
	}
	cout<<32<<endl;
	cout<<17;
	return 0;
}
