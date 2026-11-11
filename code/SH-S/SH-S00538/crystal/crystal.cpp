#include <iostream>
#include <algorithm>
using namespace std;
long long a[500005];
long long s[500005];
int n;
long long m;
bool check100(int x)
{
	long long minn=1e18;
	for (int l=1;l+x-1<=n;l++)
	{
		int r=l+x-1;
		long long sum=0;
		sum=a[r]*(r-l+1)-(s[r]-s[l-1]);
		minn=min(minn,sum);
	}
	if (minn<=m) return true;
	else return false;
}
bool check(int x)
{
	long long minn=1e18;
	for (int l=1;l+x-1<=n;l++)
	{
		int r=l+x-1;
		long long sum=0;
		for (int i=l;i<=r;i++)
		{
			sum+=a[r]-a[i];
		}
		minn=min(minn,sum);
	}
	if (minn<=m) return true;
	else return false;
}
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
	for (int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while (l<r)
	{
		int mid=l+r+1>>1;
		if (n<=5000)
		{
			if (check(mid))
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		else
		{
			if (check100(mid))
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
	}
	cout<<l<<endl;
	return 0;
}
