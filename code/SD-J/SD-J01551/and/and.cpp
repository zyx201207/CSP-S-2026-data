#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		int sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	int k=a[n]; 
	for(int i=n-1;i>=n-m+1;i--)
	{
		k&=a[i];
	} 
	cout<<k;
	return 0;
} 
