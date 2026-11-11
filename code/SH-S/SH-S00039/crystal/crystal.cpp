#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, tmp = 1, ans = 1;
int a[N], b[N];
bool f()
{
	int x = a[2] - a[1];
	for(int i = 2; i <n;++i)
	{
		if(x != a[i+1] - a[i]) return 0;
	}
	return 1;
}
bool g()
{
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] != i) return 0;
	}
	return 1;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >>m;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	if(g())
	{
		for(int i = 1; i<= n; ++i)
		{
			if(m >= (1 + i) * i /2 ) ans++;
			else
			{
				cout << ans;
				break;
			}
		}
		return 0;
	}
	if(f())
	{
		for(int i = 1; i<= n; ++i)
		{
			if(m >= (a[2] - a[1]) * (1 + i) * i /2 ) ans++;
			else
			{
				cout << ans;
				break;
			}
		}
		return 0;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; ++i)
	{
		int mm = m;
		while(mm && i - tmp >= 1)
		{
			if(b[i- tmp] == b[i])
			{
				tmp++;
				continue;
			}
			else 
			{
				b[i-tmp]++;
				mm--;
			}
		}
		if(b[i- tmp] == b[i] && mm == 0)
		{
			tmp++;
		}
		ans = max(ans, tmp);
		tmp = 1;
		for(int j = 1; j <= n; ++j)
		{
			b[j] = a[j];
		}
	}
	/*sum /= n;
	for(int i = 1; i <= n; ++i)
	{
		b[i] = abs(sum - a[i]);
		t = min(t, b[i]);
	}
	for(int i =1; i <= n; ++i)
	{
		if(b[i] == t) tmp = i;
	}
	while(m)
	{
		if(a[tmp - 1] == a[tmp]) 
		{
			tmp--;
			ans++;
			continue;
		}
		else
		{
			a[tmp -1]++;
			m--;
		}
	}
	if(a[tmp - 1] == a[tmp]) ans++;
	*/cout << ans;
	return 0;
}
