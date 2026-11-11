#include<bits/stdc++.h>
using namespace std;
long long n,m,max_ai;
long long a[500005];
long long sum[500005];
bool check(int x)
{
	long long num = m,size = a[x];
	for(int i = 1;i <= x;i++)
	{
		num -= (a[x] - a[i]);
		if(num < 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		max_ai = max(max_ai,abs(a[i]));
	}
	sort(a + 1,a + n + 1);
	if(n <= 5000)
	{
		long long ans = -1;
		for(int i = 1;i <= n;i++)
		{
			sum[i] = sum[i - 1] + a[i];
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j < i;j++)
			{
				if(sum[i] - sum[j - 1] + m >= (i - j + 1) * a[i])
				{
					long long x = (i - j + 1) * 1ll;
					ans = max(ans,x);
				}
			}
		}
		cout<<ans;
	}
	else
	{
		long long l = 1,r = n,ans;
		while(l <= r)
		{
			long long mid = (l + r + 1) / 2;
			if(check(mid))
			{
				ans = mid;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		cout<<ans;
	}
	return 0;
} 
