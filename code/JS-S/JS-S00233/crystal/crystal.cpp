//California,don't let me down
//Seem so golden,but there's struggle all around
//Sunset jesus,come to me
//He was once a waiter but now he's a savior making money on the streets
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;

int a[N],sum[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		int l = 0,r = i;
		while (l + 1 < r)
		{
			int mid = (l + r) >> 1;
			if ((i - mid + 1) * a[i] - sum[i] + sum[mid - 1] <= m) r = mid;
			else l = mid;
		}
		ans = max(ans,i - r + 1);
	}
	cout << ans << endl;
	return 0;
}
