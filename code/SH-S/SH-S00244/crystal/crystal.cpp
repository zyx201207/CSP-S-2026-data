#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

int n, m;
int a[500010];
int ans;
int d; // 等差数列的公差 

bool check(int x)
{
//	cout << x << " ";
	int t = (x - 1) >> 1;
//	cout << t << " ";
	int k;
	if(t & 1)	k = (t + 1) / 2 * t;
	else	k = t / 2 * (t + 1);
//	cout << k << " ";
	k *= d * 2;
//	cout << k << " ";
	if((x & 1) == 0)	k += (t + 1) * d;
//	cout << k << " ";
	if(k < 0 || k > m)	return false;
	else	return true;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool f = true;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(i == 1)	continue;
		if(a[i] - a[i - 1] != a[2] - a[1])	f = false; 
	}
	d = a[n] - a[n - 1];
	if(f)
	{
		// 处理等差数列
		int l = 1, r = n, ans = -1;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check(mid))
			{
				l = mid + 1;
				ans = mid;
//				cout << mid << " ";
			}
			else	r = mid - 1;
		}
		cout << ans << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int cnt, t, j;
	int ans = 0;
	for(int i = n; i >= 1; i--)
	{
		cnt = 0, t = m, j = i - 1;
		while(t > 0 && j > 0)
		{
			if(a[i]- a[j] <= t)
			{
				t -= a[i] - a[j];
				cnt++;
				j--;
			}
			else	break;
		}
		ans = max(ans, cnt + 1);
	}
	cout << ans << endl;
	return 0;
}
