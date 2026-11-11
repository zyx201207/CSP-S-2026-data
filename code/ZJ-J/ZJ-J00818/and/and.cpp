#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[200010];
char s[200010][31];
int cnt[31];
string c, ans;
bool vis[200010];
int cnter;
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1, t; i <= n; i ++)
	{
		cin >> a[i];
		t = a[i];
		c = "";
		while(t)
		{
			c += (t % 2) + '0';
			t /= 2;
		}
		int l = c.size();
		for (int j = 0; j < l; j ++)
		{
			s[i][j + 30 - l] = c[l - j - 1];
			if (s[i][j+30-l])
				cnt[j + 30 - l] ++;
		}
		for (int j = 0; j < 30 - l; j ++)
				s[i][j] = '0';
				
//		cout << i << ' ' << s[i] << '\n';
	}
	int las = n;
	for (int p = 0; p < 30; p ++)
	{
//		cout << p << ' ' << las << '\n';
//		if (p == 26)
//			cout << las <<"************\n";
		if (las >= m)
		{
//			cout << 1 << "***********************************************************\n";
			int t = las;
			for (int i = 1; i <= n; i ++)
				if (!vis[i] and s[i][p] == '0')
				{
					t --;
				}
			
			if (t >= m)
			{
				ans += '1';
				for (int i = 1; i <= n; i ++)
					if (!vis[i] and s[i][p] == '0')
					{
						vis[i] = 1;
					}
				las = t;
			}
			else
				ans += '0';
		}
		else
			ans += '0';
	}
	for (int i = 0; i < 30; i ++)
	{
		cnter = cnter*2 + (ans[i]=='1');
	}
	cout << cnter << '\n';
	return 0;
}
/*
4 2
3 15 12 12
*/
