#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n==m)
	{
		long long sum=a[0];
		for(int i=1;i<n;i++)sum&=a[i];
		cout<<sum;
	} 
	if(m==1)
	{
		long long sum=0;
		for(int i=1;i<n;i++)sum=max(sum,a[i]);
		cout<<sum;
	}
	if(m==2)
	{
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)sum=max(sum,a[i]&a[j]);
		}
		cout<<sum;
	}
	return 0;
}									   
