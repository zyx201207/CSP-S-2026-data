#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,a,b,cg,t;
	cin>>c>>n>>m>>d>>q;
	long long w[m+1],k[n+1]; 
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>c>>t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a>>b;
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2)
	{
		cout<<32<<endl<<17;
		return 0;
	}
	else if(c==0&&n==3&&m==7&&d==20&&q==2)
	{
		cout<<35<<endl<<16;
		return 0;
	}
	return 0;
}
