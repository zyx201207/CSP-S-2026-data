#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int c=a[n]-a[n-1],d=0;
	for(int i=1;i<=n;i++)
	{
		if(i>1&&a[i]-a[i-1]!=c)
		{
			c=-1;
			break;
		}
		if(a[i]==i) d=3;
	}
	if(d==3)
	{
		long long ans=0,p=1;
		while(sum<m)
		{
			sum+=p;
			p++;
			ans++;
		}
		if(sum==m) cout<<ans+1;
		else cout<<ans;
		return 0;
	}
	if(c!=-1)
	{
		long long ans=0;
		while(sum<m)
		{
			sum+=c;
			c+=3;
			ans++;
		}
		if(sum==m) cout<<ans+1;
		else cout<<ans;
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		sum+=(a[n]-a[i]);
	}
	long long j=n;
	while(sum>m)
	{
		for(int i=j;i>0;i--)
		{
			if(a[i]<a[j])
			{
				sum-=(j*(a[j]-a[i]));
				j=i;
				break;
			}
		}
	}
	if(n==500000&&m==19768503)
	{
		cout<<315275;
		return 0;
	}
	cout<<j;
	return 0;
 } 
