#include<bits/stdc++.h>

using namespace std;
long long n,m,sum=0;
long long a[550000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		long long ans=0,cnt=0;
		for(long long j=1;j<=i;j++)
		{
			cnt++;
			ans+=(a[i]-a[i-j]);
			if(ans>m)
			{
				cnt--;
				break;
			}
		}
		sum=max(sum,cnt);
	}
	cout<<sum+1;
	return 0;
} 
