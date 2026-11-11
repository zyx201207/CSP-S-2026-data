#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
long long a[N];
int n;
long long m;
long long sum[N];
int ans = -1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin >> n >> m;
	for(int t = 1;t <= n;t++)
	{
		cin >> a[t];		
	}		
	sort(a + 1,a + n + 1);
	for(int t = 1;t <= n;t++)
	{
		sum[t] = sum[t - 1] + a[t];
	} 
	for(int t = n;t >= 1;t--)
	{
		int l = 1,r = t - 1;
		long long mid;
		while(l <= r)
		{
			mid = (l + r) / 2;
			long long cnt = sum[t - 1] - sum[mid - 1];
			if(a[t] * (t - mid) - cnt <= m)
			{
				if(t - mid + 1 > ans)
				{
					ans = t - mid + 1;
				}
				r = mid - 1;
			} 
			else l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}

