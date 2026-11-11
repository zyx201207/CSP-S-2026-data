#include <bits/stdc++.h>

using namespace std;

long long a[500010];
long long sum[500010];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	long long m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	sort(a + 1,a + n + 1);
	
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
		
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		int num = -1;
		int l = 0,r = i;
		while (l <= r)
		{
			int mid = (l + r)/ 2;
			if (sum[i] - sum[mid] + m >= a[i] * (i - mid))
			{
				num = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		ans = max(ans,i - num);
	}
	cout << ans;
	
	return 0;
}
