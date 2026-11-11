#include<iostream>
#include<cstring>
#include<cstring>
using namespace std;
int n,m;
int a[500001];
int p[201],f[201];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	bool k = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] < a[i - 1]) k = 1;
	}
	if(k == 0)
	{
		int u = 1;
		while(u <= n)
		{
			int t = u;
			while(a[u] == a[t])
			{
				u++;
			}
			int r = u - t;
			if(r % 2 == 0) cout << r / 2 << ' ';
			else cout << t - 1 + r / 2 << ' ';
		}
		return 0;
	}
	if(m == 2)
	{
		int cnt = 0;
		if(a[n] == 1)
		{
			for(int i = 1;i <= n;i++)
			{
				if(a[i] == 2) cnt++;
			}
			cout << n << ' ' << cnt;
		}
		if(a[n] == 2)
		{
			for(int i = 1;i <= n;i++)
			{
				if(a[i] == 1) cnt++;
			}
			cout << cnt << ' ' << n;
		}
		return 0;
	}
	for(int u = 1;u <= n;u++)
	{
		for(int i = u;i <= n;i++)
		{
			if(p[a[i]] == 0) p[a[i]] = i;
			else
			{
				for(int j = 1;j <= m;j++)
				{
					if(p[j] > p[a[i]]) p[j] = 0;
				}
				p[a[i]] = i;
			}
		}
		for(int j = 1;j <= m;j++)
		{
			if(p[j] != 0) f[j]++;
			p[j] = 0;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << f[i] << ' ';
	}
}
