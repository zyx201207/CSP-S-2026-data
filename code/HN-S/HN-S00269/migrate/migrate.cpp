#include<bits/stdc++.h> 
using namespace std;
long long c,t,n,d;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(a[4]-a[1]>2*d)
		{
			cout<<0<<endl;
			continue;
		}
		if(a[n]-a[1]<d)
		{
			cout<<0<<endl;
			continue;
		}
		long long x=a[2]-a[1];
		long long z=(d/x)*2;
		cout<<n-z+1<<endl;
	}
} 
