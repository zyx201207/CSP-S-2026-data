#include <bits/stdc++.h>
using namespace std;

int n;
long long len, m;

struct node
{
	int a;
	char c;
}p[200005];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].a >> p[i].c;
		len += 1ll * p[i].a;
	}
	m = len / 2;
	int j = n;
	long long cur = m, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == j || m == 0 || cur == 0) break;
		while (i <= j && j >= 1 && p[i].a > 0)
		{
			if (i == j || m == 0 || cur == 0) break;
			if (p[i].a > p[j].a)	
			{
				if (p[i].c != p[j].c) ans += p[j].a;
				p[i].a -= p[j].a;
				m -= p[j].a;
				cur -= p[j].a;
				p[j].a = 0;
				j--;
			}
			else if (p[i].a < p[j].a)	
			{
				if (p[i].c != p[j].c) ans += p[i].a;
				p[j].a -= p[i].a;
				m -= p[i].a;
				cur -= p[i].a;
				p[i].a = 0;
			}
			else
			{
				if (p[i].c != p[j].c) ans += p[j].a;
				m -= p[j].a;
				cur -= p[j].a;
				p[i].a = p[j].a = 0;
				j--;
			}
		}
		//cout << i << " " << j << " " << m << " " << cur << " " << ans << endl;
		if (i == j || m == 0 || cur == 0) break;
	}
	cout << ans << endl;
	return 0;
}
