#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long maxn=-1e9;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int flag=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long x=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=x)
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		int cnt=1;
		for(int i=2;i<=n;i++)
		{
			if(1ll*x*cnt>m)
			{
				cout<<i-1;
				break;
			}
			cnt+=i;
		}
	}
	else
	{
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)
		{
			int ans=m;
			long long cnt=1;
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]>a[j]+ans)
				{
					break;
				}
					cnt++;
					ans=ans-(a[i]-a[j]);
			}
			maxn=max(maxn,cnt);
		}
		cout<<maxn;
	}
	return 0;
}
