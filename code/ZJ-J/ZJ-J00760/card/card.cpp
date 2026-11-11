#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005]; 
int t[300005], sj[500005];

void dg(int dep)
{
	bool b[300005];
	for(int i = 1;i <=n;i++) b[i] = 0;
	int x = dep;
	while(++x)
	{
		if(sj[x] == sj[dep] || sj[x] == 0) break;
		if(b[sj[x]] == 0)
		{
			b[sj[x]] = 1;
			int y = dep;
			while(y--)
			{
				if(sj[y] == sj[x])
				{
					a[y] = -a[dep];
					dg(y);
					break;
				}
			}
		}
	}
}

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> sj[i];
	}
	for(int i = 1;i <= m;i++) 
	{
		for(int j = n;j >= 0;j--) a[j] = 0;
		for(int j = n;j >= 0;j--)
		{
			if(sj[j] == i)
			{
				a[j] = 1;
				dg(j);
				break;
			}
		}
		int ans = 0;
		a[n + 1] = -1;
		for(int j = n;j >= n;j--)
		{
			if(a[j] == 0) a[j] = a[j + 1];
			ans += (a[j] + 1) / 2;
		}
		cout << ans << " ";
	}
	return 0;
}