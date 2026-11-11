#include<bits/stdc++.h>
using namespace std;
long long arr[500010],brr[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&arr[i]);
	}
	long long mid=arr[n/2];
	for(long long i=1;i<=n;i++)
	{
		brr[i]=abs(arr[i]-mid);
	}
	sort(brr+1,brr+n+1);
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		if(m>=brr[i])
		{
			m-=brr[i];
			ans++;
		}
		else
		{
			printf("%lld",ans);
			return 0;
		}
	}
	printf("%d",ans);
	return 0;
}
