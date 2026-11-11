#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e5 + 10;

int n, m;
int a[N];
int c[N];
int sc[N];
int ssc[N];


signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++)
	{
		c[i] = a[i] - a[i - 1];
	}
	for(int i = n; i >= 2; i--)
	{
		sc[i] = sc[i + 1] + c[i];
		ssc[i] = ssc[i + 1] + sc[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int l = 1, r = i;
		int res = 0;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			int u = ssc[mid + 1] - ssc[i + 1] - (i - mid) * sc[i + 1];
			if(u <= m)
			{
				r = mid - 1;
				res = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		if(res != 0)
		{
			ans = max(ans, i - res + 1);
		}
	}
	cout << ans << endl;
	return 0;
}
//Oct31==Dec25?
//最后一个大样例少了1,我要炸了  
