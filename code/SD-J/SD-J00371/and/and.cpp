#include<bits/stdc++.h>
using namespace std;
int a[200005],cf[200004],sum[200004],s[200004];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	long long ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=n-m+1;i--)
	{
		if(i==n)ans=a[n];
		else ans=(ans&a[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		cf[i]=a[i+1]-a[i];
		s[i]=s[i-1]+cf[i];
	}
	long long minx=1e9;
	int pop;
	/*for(int j=1;i<=m-1;i++)
		{
			sum[i]+=cf[i-j];
		}*/
	for(int i=m;i<=n-1;i++)
	{
		sum[i]=s[i]-s[i-m];
		if(sum[i]<minx)
		{
			minx=sum[i];
			pop=i;
		}
	}
	long long ans2=0;
	for(int i=0;i<=m-1;i++)
	{
		if(i==0)ans2=a[pop];
		else ans2=(ans2&a[pop-i]);
	}
	cout<<max(ans,ans2);
	return 0;
}
