#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,ans;
long long m,a[N],st[205];
bool flag=1;
int main()
{
	freopen("crystal4.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if (i>=3 && a[i]-a[i-1]!=a[i-1]-a[i-2])flag=0;
	}
	if (n<=0)
	{
		sort(a+1,a+1+n);
		for (int i=n;i>=1;i--)
		{
			int num=0;
			long long sum=0;
			for (int j=i;j>=1;j--)
			{
				if (sum+a[i]-a[j]>m)break;
				else
				{
					sum+=a[i]-a[j];
					num++;
				}
			}
			ans=max(ans,num);
		}
	}
	else if (flag)
	{
		long long num=m/(a[2]-a[1]);
		long long l=1,r=num,mid;
		while(l<=r)
		{
			mid=(l+r)/2;
			if (mid*(mid+1)/2>num)r=mid-1;
			else l=mid+1;
		}
		ans=r+1;
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			st[a[i]+100]++;
		}
		for (long long i=201;i>=0;i--)
		{
			int num=0;
			long long sum=m;
			for (long long j=i;j>=0;j--)
			{
				if (sum-st[j]*(i-j)<0 && sum>0)
				{
					num+=sum/(i-j);
					sum-=sum/(i-j)*(i-j);
				}
				else
				{
					sum-=st[j]*(i-j);
					num+=st[j];
				}
			}
			ans=max(ans,num);
		}
	}
	cout<<ans;
	return 0;
}
