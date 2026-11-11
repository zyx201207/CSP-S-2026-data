#include <bits/stdc++.h>
using namespace std;

long long a[200005];
char c[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long sum = 0;
	bool f = 1;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		sum += a[i];
		if(i > 1 && c[i] != c[i - 1])f = 0;
	}
	if(f)
	{
		cout << 0;
		return 0;
	}
	bool d = 0;
	if(sum % 2 == 0)d = 1;
	sum = (sum + 1) / 2;
	f = 1;
	long long cnt = 0, ans = 0, t = 0;
	for(int i = 1; i <= n; i++)
	{
		cnt += a[i];
		if(cnt >= sum && f)
		{
			t = i;
			f = 0;
			if(!d)
			{
				a[i] -= 1;
			}
			if(cnt > sum)
			{
				int x = cnt - sum;
				if(x > a[t] - x)
				{
					x -= (a[i] - x);
					a[t] = 0;
					t--;
					while(x >= a[t])
					{
						if(c[t] != c[t + 1])ans += a[t];
						x -= a[t];
						a[t] = 0;
						t--;
					}
					if(x != 0)
					{
						if(c[t] != c[t + 1])ans += x;
						a[t] -= x;
					}
				}
				else 
				{
					a[t] -=  2 * x;
					if(a[t] == 0)t--;
				}
			}
			continue;
		}
		if(!f)
		{
			while(a[i] >= a[t] && a[i] != 0)
			{
				if(c[i] != c[t])ans += a[t];
				a[i] -= a[t];
				a[t] = 0;
				t--;
			}
			if(a[i] != 0)
			{
				if(c[i] != c[t])ans += a[i];
				a[t] -= a[i];
			}
		}
	}
	cout << ans;
	return 0;
}
