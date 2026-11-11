#include <bits/stdc++.h>
using namespace std;

const long long rp = 1e9;
long long n,m;
long long a[200005];
long long ans = INT_MIN;

int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1;i <= n - m + 1;i++)
	{
		long long now = a[i];
		long long cnt = m - 1;
		for (int j = i + 1;j <= n && cnt > 0;j++)
		{
			if ((now & a[j]) >= now)
			{
				cnt--;
				now = (now & a[j]);
			}
		}
		if (cnt == 0)ans = max(now,ans);
	}
	cout << ans << endl;
	return 0;
}
