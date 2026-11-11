#include<iostream>
#include<cstdio>
using namespace std;
long long c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		long long n=0,m=0,a[20005]={},sum=0;
		cin>>n>>m;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=n;j++)
		{
			if(j+2*m-1<=n)
			{
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
