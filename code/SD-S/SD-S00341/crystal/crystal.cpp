#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 3;
int a[N];
int b[N];
int read()
{
	int x = 0,fs = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-')
		{
			fs = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * fs;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	int m;
	n = read();
	m = read();
	bool flaga = 1,flagb = 1; 
	for(int i = 1;i <= n;i++)
	{
		a[i] = read();
		if(a[i] != i)
		{
			flaga = 0;
		}
		b[i] = a[i] - a[i - 1];
	}
	sort(a + 1,a + n + 1);
	for(int i = 2;i <= n;i++)
	{
		if((a[i] - a[i - 1]) != (a[i - 1] - a[i - 2]))
		{
			flagb = 0;
			break;
		}
	}
	int ans = 0;
	if(flaga == 1)
	{
		ans = 1;
		for(int i = 1;i <= n;i++)
		{
			if((m - i) >= 0) 
			{
				ans++;
				m -= i;
			}
		}
		cout << ans;
		return 0;
	}
	if(flagb == 1)
	{
		int chu = m / (a[n - 1] - a[n - 2]);
		chu++;
		cout << chu; 
	}
	int k = m;
	int cnt = 1;
	for(int i = 2;i <= n;i++)
	{
		if((a[i] - a[1]) < k)
		{
			cnt++;
			k -= (a[i] - a[1]);
		}
	}
	ans = cnt;
	int f = m;
	cnt = 1;
	for(int i = n - 1;i >= 1;i--)
	{
		if((a[n] - a[i]) <= f)
		{
			cnt++;
			f -= (a[i] - a[1]);
		}
	}
	ans = max(ans,cnt);
	if(ans == n)
	{
		cout << ans;
		return 0;
	}
	int id = 0;
	int mm = 1e18;
	for(int i = 2;i <= n - 1;i++)
	{
		if((b[i] + b[i + 1]) < mm)
		{
			id = i;
			mm = b[i] + b[i + 1];
		}
	}
	a[id] = 0;
	int sh = 0,shh = 0;
	int ids = 1,idx = n;
	for(int i = id - 1;i >= 1;i--)
	{
		if((m - sh) < b[i + 1])
		{
			ids = i + 1;
			break;
		}
		a[i] = b[i + 1] + sh;
		shh = shh + b[i + 1];
		if(sh == 0 && shh != 0)
		{
			sh = shh + sh;
		}
		sh = a[i] + shh;
		//cout << sh << " " << shh << "\n";
	}
	//cout << "\n";
	sh = 0;
	shh = 0;
	
	for(int i = id + 1;i <= n;i++)
	{
		if((m - sh) < b[i])
		{
			idx = i - 1;
			break;
		}
		a[i] = b[i] + sh;
		shh = shh + b[i];
		if(sh == 0 && shh != 0)
		{
			sh = shh + sh;
		}
		sh = shh + a[i];
		//cout << sh << " " << shh << "\n";
	}
	int l = id - 1,r = id + 1;
	cnt = 1;
	while(1)
	{
		if(m <= 0)
		{
			break;
		}	
		if(l >= ids && r <= idx)
		{
			if(a[l] <= m && a[l] <= a[r])
			{
				m -= a[l];
				l--;
				cnt++;
			}
			else if(a[r] <= m)
			{
				m -= a[r];
				r++;
				cnt++;
			}
			else
			{
				break;
			}
		}
		else if(l >= ids)
		{
			if(a[l] <= m)
			{
				m -= a[l];
				cnt++;
				l--;
				
			}
		}
		else if(r <= idx)
		{
			if(a[r] <= m)
			{
				m -= a[r];
				cnt++;
				r ++;
			}
		}
		else
		{
			break;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		cout << a[i] << " ";
	}
	cout <<max(ans,cnt);
	return 0;
}

