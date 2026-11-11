#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[501010];
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
	int flag=1;
	long long q=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(a[i]!=a[i-1]+q) flag=0;
	}
	if(flag==1)
	{
		long long l=1,r=n;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			if((q+mid*q)*mid/2<m)
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<ans+1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		long long sum=0,res=1;
		for(int j=i-1;j>=1;j--)
		{
			sum+=a[i]-a[j];
			if(sum>m) break;
			res++;
		}
		ans=max(res,ans);
	}
	cout<<ans;
	return 0;
}