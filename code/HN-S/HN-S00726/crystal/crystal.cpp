#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N],d[N],sum[N],ans = 1;
bool flag = 1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		d[i] = a[i] - a[i - 1];
		if (i != 1 && d[i] != d[i - 1])
		{
			flag = 0;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		int cnt = 1;
		if (flag)
		{
			if ((d[2] + (i - 1) * d[2]) * (i - 1) / d[2] <= m)
			{
				ans = min(i,max(ans,(d[2] + (i - 1) * d[2]) * (i - 1) / d[2]));
			}
			continue;
		}
		memset(sum,0,sizeof(sum));
		int cnt1 = 0;
		for (int j = i - 1; j >= 1; j--)
		{
			sum[j] = sum[j + 1] + d[j + 1];
			if (cnt1 + sum[j] <= m) 
			{
				cnt1 += sum[j];
				cnt++;
			}
			else
			{
				break;
			}
		}
		ans = max(ans,cnt);
	}
	cout << ans;
	return 0;
}

