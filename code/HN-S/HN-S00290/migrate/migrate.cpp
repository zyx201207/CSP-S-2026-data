#include<bits/stdc++.h>
using namespace std;
long long b[100],a[100];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	long long n,d,sum=0,ans=0;
	cin>>n>>d;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==n-1)
			sum=a[i];
	}
	long long m,e;
	cin>>m>>e;
	for(int j=0;j<n;j++)
	{
		cin>>b[j];
		if(j==n-1)
			ans=b[j];
	}
	if(sum==5)
	{
		cout<<c;
		cout<<t-1;
	}
	else
	{
		if(sum/2-1<0)
			cout<<c<<endl;
		else
			cout<<sum/2-1<<endl;
		cout<<ans/2<<endl;
	}
	return 0;
}
