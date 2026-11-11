#include <bits/stdc++.h>
#define int long long
using namespace std;

int n , m , ans , l = 1 , cz , minn = 1e9;
int a[500005] , e[500005] , qz[500005];
bool f , f2;

signed main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		minn = min(a[i] , minn);
		qz[i] = qz[i - 1] + a[i];
		if(a[i] - a[i - 1] != 1 && i > 1)
		{
			f = 1;
		}
		if(a[i] - a[i - 1] != a[i - 1] - a[i - 2] && i > 2)
		{
			f2 = 1;
		}
		cz = a[i] - a[i - 1];
	}
	sort(a + 1 , a + n + 1);
	if(f == 0)
	{
		for(int i = 1;i < n;i ++)
		{
			if(ans + i > m)
			{
				cout << i - 1;
				return 0;
			}
			ans += i;
		}
		cout << n;
		return 0;
	}
	else if(f2 == 0)
	{
		for(int i = 1;i < n;i ++)
		{
			if(ans + cz * i > m)
			{
				cout << i - 1;
				return 0;
			}
			ans += cz * i;
		}
		cout << n;
	}
	else if(n <= 5000)
	{
		for(int i = 2;i <= n;i ++)
		{
			for(int j = l;j < i;j ++)
			{
				if(e[j] + (i - j) * (a[i] - a[i - 1]) > m)
				{
					ans = max(ans , i - j);
					if(n - i + 1 <= ans)
					{
						cout << ans;
						return 0;
					}
					l ++;
				}
				e[j] += (i - j) * (a[i] - a[i - 1]);
			}
		}
		cout << ans;
	}
	else
	{
		if(minn < 0)
		{
			for(int i = 1;i <= n;i ++)
			{
				a[i] += abs(minn) + 1;
				qz[i] = qz[i - 1] + a[i];
			}
		}
		for(int i = 1;i <= n;i ++)
		{
			while((i - l + 1) * a[i] - qz[i] + qz[l - 1] > m)
			{
				l ++;
			}
			ans = max(ans , (i - l + 1));
		}
		cout << ans;
	}
	return 0;
}
