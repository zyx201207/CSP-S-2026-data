#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],cnt=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (long long i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	bool f=1;
	for (long long i=3; i<=n; i++)
	{
		if (a[i]-a[i-1] != a[i-1]-a[i-2])
		{
			f=0;
		}
	}
	if (f)
	{
		long long ct=1;
		for (long long i=2; i<=n; i++)
		{
			b[i]=b[i-1]+a[i]-a[i-1];
		}
		for (long long i=2; i<=n; i++)
		{
			if (m>=b[i])
			{
				m-=b[i];
				ct++;
			}
			else break;
		}
		cout << ct;
	}
	else
	{
		long long mxcnt=0;
		for (long long i=1; i<=n; i++)
		{
			long long l=a[i],r=a[n];
			while (l<r)
			{
				long long mid=(l+r)/2,sum=0,cnt=0;
				for (long long j=i; a[j]<=mid; j++)
				{
					sum+=(mid-a[j]);
					cnt++;
				}
				if (sum>m)
				{
					r=mid;
				}
				else
				{
					l=mid+1;
					mxcnt=max(mxcnt,cnt);
				}
			}
		}
		cout << mxcnt;
	}
	return 0;
} 
