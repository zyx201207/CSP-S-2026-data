#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII piar<int, int>
#define fi first
#define se second
using namespace std;
const int MAXN = 5e5 + 7;

inline int read()
{
	int w = 0, c = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		c = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		w = w * 10 + ch - '0';
		ch = getchar();
	}
	return w * c;
}

int n, m;
int a[MAXN];
int ans = 1;

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read(), m = read();
	int d = 0;
	int f = 1;
	for(int i = 1;  i <= n;  i++)
	{
		a[i] = read();
		if(i == 2)
		{
			d = a[i] - a[i-1];
		}
		if(i >= 3)
		{
			if(d != a[i] - a[i-1])
			{
				f = 0;
			}
		}
	}
	
	sort(a + 1, a + n + 1);
	if(f)
	{
		int now = m, ex = d;
		int ans = 1;
		while(now)
		{
			now -= ex;
			if(now < 0)
			{
				break;
			}
			ex += d;
			ans++;
		}
		cout<<min(ans, n)<<endl;
		return 0;
	}
	a[0] = -1e18;
	
	for(int i = 1;  i <= n;  i++)
	{
		int now = m;
		int cnt = 1;
		int l = i - 1;
		while(now)
		{
			now = now - (a[i] - a[l]);
			if(now < 0)
			{
				break;
			}
			l--, cnt++;
		}
		ans = max(cnt, ans);
	}
	cout<<ans<<endl;
	
	return 0;
}
