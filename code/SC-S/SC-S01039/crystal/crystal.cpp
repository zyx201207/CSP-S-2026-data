#include <bits/stdc++.h>
using namespace std;
const long long N=1e8;
long long n,m,a[N],sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	long long minn=999999,k=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=sum)
		{
			minn=min(minn,(a[i]-sum));
			if(minn==(a[i]-sum))
			{
				k=a[i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<k)
		{
			while(a[i]!=k)
			{
				if(m==0)
				{
					break;
				}
				else
				{
					m--;
			    	a[i]++;
				}
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}