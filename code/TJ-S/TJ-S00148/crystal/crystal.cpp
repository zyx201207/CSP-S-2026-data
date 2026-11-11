#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,M,a[700005],b[700005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>M;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]+b[i-1];
	}
	int maxx=-99999;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int x=j-i;
			for(int m=1;m<=M;m++)
			{
				if((m+(b[j]-b[i]))%x==0)
				{
					maxx=max(maxx,x);
				}
			}
		}
	}
	cout<<maxx;
	return 0;
}
