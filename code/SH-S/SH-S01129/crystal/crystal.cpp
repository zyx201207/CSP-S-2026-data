#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long maxv=-1000000000000,minv=INT_MAX,m;
	int ans=0,cnt=0,ans1=0,n,i,j,flag=1;
	scanf("%d %lld",&n,&m);
//	printf("%d %lld\n",n,m);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&arr[i]);
		maxv=max(maxv,abs(arr[i]));
		minv=min(minv,arr[i]);
	}
	for(i=3;i<=n;++i)
	{
		if(arr[i]-arr[i-1]!=arr[i-1]-arr[i-2])
			flag=0;
	}
	sort(arr+1,arr+1+n);
	if(n<=5000&&maxv<=100)
	{
		for(i=minv;i<=maxv;++i)
		{
			ans=0;
			cnt=0;
			for(j=1;j<=n;++j)
			{
				if(arr[j]>i)
					break;
			}
			j--;
			for(j;j>=1;--j)
			{
				if(ans+i-arr[j]>m)
					break;
				ans=(i-arr[j])+ans;
				cnt++;
			}
			ans1=max(ans1,cnt);
		}
		printf("%d",ans1);
	}
	else if(n>=5000&&n<=500005&&maxv<=100)
	{
		for(i=minv;i<=maxv;++i)
		{
			ans=0;
			cnt=0;
			for(j=1;j<=n;++j)
			{
				if(arr[j]>i)
					break;
			}
			j--;
			for(j;j>=1;--j)
			{
				if(ans+i-arr[j]>m)
					break;
				ans=(i-arr[j])+ans;
				cnt++;
			}
			ans1=max(ans1,cnt);
		}
		printf("%d",ans1);
	}
	else if(n>=5000&&n<=500005&&flag)
	{
		for(i=n-1;i>=1;--i)
		{
			ans=ans+arr[n]-arr[j];
			if(ans>m)
				break;
			cnt++;
		}
		printf("%d",cnt+1);
	}
	return 0;
}
