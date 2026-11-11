#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500005;
int a[N],sum[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	int c = a[2] - a[1];
	bool f = 1;
	for (int i = 3;i <= n;i++)
	{
		if (a[i] - a[i - 1] != c)
		{
			f = 0;
			break;
		}
	}
	if (f)
	{
		for (int i = 1;i <= n;i++)
			if (c * i * (i - 1) / 2 <= m) ans = max(ans,i);
		//cout << m << ' ' << a[2] << ' ' << a[1] << ' ' << c << endl;
		cout << ans;
		return 0;
	}
	for (int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= i;j++)
		{
			if (a[i] * (i - j + 1) - (sum[i] - sum[j - 1]) <= m)
				ans = max(ans,i - j + 1);
		}
	}
	cout << ans;
	return 0; 
}
//14:30-15:07 75pts
