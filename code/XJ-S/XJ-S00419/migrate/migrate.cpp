#include<bits/stdc++.h>
using namespace std;
int t,c,n,d;
long long a[10^6+5];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++)
	{
		int x=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	x=a[2]-a[1];
	if(2*x<=d)
	{
		cout<<n-3;
	}
	else
	{
		cout<<0;
	}
	}
	return 0;
}
