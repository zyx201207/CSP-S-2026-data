#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500010],b[500010];
int main()
{
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (n<=5000)
	{
		for (int k=1;k<=n;k++)
		{	
			long long mid=a[k];
			for (int i=1;i<=k;i++)
			{
				b[i]=mid-a[i];
			}
			sort(b+1,b+k);
			long long sum=0,cnt=0;
			long long j=1;
			while(sum<=m&&j<=k)
			{
				cnt++;
				sum+=b[j];
				j++;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
	else
	{
		long long sum=(a[1]+a[n])*n/2;
		for (int i=n;i>=1;i--)
		{
			if (a[i]*n-sum <=m)
			{
				cout<<i;
				return 0;
			}
		}
	}
	return 0;
}
