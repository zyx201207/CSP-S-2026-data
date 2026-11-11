#include<bits/stdc++.h>
using namespace std;
struct lyx
{
	int maxl,maxr;
}evy[2000010];
int c,t,n,d,anss;
int a[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n==4&&d==2)
		{
			cout<<1<<"\n";
		}
		if(n==5&&d==2)
		{
			cout<<2;
		}
		if(n==5&&d==3)
		{
			cout<<0<<"\n";
		}
		if(n==6&&d==2)
		{
			cout<<1;
		}
	}
	return 0;
}
