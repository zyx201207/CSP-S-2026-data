#include <bits/stdc++.h>
using namespace std;

long long a[500010],b[500010];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxn = -1e13,minn = 1e13,ans = -1;
	cin >> n >> m;
	int mm = m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		maxn = max(maxn,a[i]);
		minn = min(minn,a[i]);
	}
	for(int i = minn;i <= maxn;i++)
	{
		m = mm;
		for(int j = 1;j <= n;j++)
		{
			if(i - a[j] < 0)
			{
				b[j] = 1e18;
			}
			else
			{
				b[j] = i - a[j];
			}
		}
		sort(b + 1,b + n + 1);
		long long cur = 1,cnt = 0;
		while(1)
		{
			if(cur == n + 1)
			{
				break;
			}
			if(m >= b[cur])
			{
				cnt++;
				m -= b[cur];
				cur++;
			}
			else
			{
				break;
			}
		}
		ans = max(ans,cnt);
	}
	cout << ans << endl;
	return 0;
} 
