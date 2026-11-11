#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int n, m, a[500005], ans = 1, b[500005], sum[500005];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		b[i] = a[i] - a[1];
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + b[i];
		
//	for (int i = 1; i <= n; i++)
//		cout << sum[i] << " ";
//	cout << endl;
	
	for (int i = 1; i <= n; i++)
	{
		int l = i, r = n, tpos = i;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int nsum = (mid - i + 1) * (a[mid] - a[1]) - (sum[mid] - sum[i - 1]);
			
//			if (i == 1 && mid == 4)
//				cout << nsum << endl;
				
			if (nsum <= m)
			{
				tpos = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		ans = max(ans, tpos - i + 1);
	}
	cout << ans;
	return 0;
}