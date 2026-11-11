#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, l, j, ans; //j记录L/2处的i , ans为需要修改的个数 
bool fl;
struct S
{
	int a, m;
	char c;
};
S s[200005];
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i].a >> s[i].c;
		l += s[i].a;
		s[i].m = l;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!fl && s[i].m >= (int)(l / 2))
		{
			j = i;
			fl = 1;
			break;
		}
	}
	if (l % 2 == 0) //偶
	{
		for (int i = 1, k = n - i + 1; (i <= j && k > j) || k - i >= 1; )
		{
			if (s[i].c == s[k].c) //不用改 
			{
				if (s[i].a == s[k].a)
				{
					s[i].a = 0;
					s[k].a = 0;
					i++;
					k--;
				}
				else if (s[i].a > s[k].a)
				{
					s[i].a -= s[k].a;
					s[k].a = 0;
					k--;
				}
				else
				{
					s[k].a -= s[i].a;
					s[i].a = 0;
					i++;
				}
			}
			else
			{
				if (s[i].a == s[k].a)
				{
					ans += s[i].a;
					s[i].a = 0;
					s[k].a = 0;
					i++;
					k--;
				}
				else if (s[i].a > s[k].a)
				{
					ans += s[k].a;
					s[i].a -= s[k].a;
					s[k].a = 0;
					k--;
				}
				else
				{
					ans += s[i].a;
					s[k].a -= s[i].a;
					s[i].a = 0;
					i++;
				}
			}
		}
	}
	else //奇 
	{
		for (int i = 1, k = n - i + 1; (i <= j && k > j) || k - i >= 1; )
		{
			if (s[i].c == s[k].c) //不用改 
			{
				if (s[i].a == s[k].a)
				{
					s[i].a = 0;
					s[k].a = 0;
					i++;
					k--;
				}
				else if (s[i].a > s[k].a)
				{
					s[i].a -= s[k].a;
					s[k].a = 0;
					k--;
				}
				else
				{
					s[k].a -= s[i].a;
					s[i].a = 0;
					i++;
				}
			}
			else
			{
				if (s[i].a == s[k].a)
				{
					ans += s[i].a;
					s[i].a = 0;
					s[k].a = 0;
					i++;
					k--;
				}
				else if (s[i].a > s[k].a)
				{
					ans += s[k].a;
					s[i].a -= s[k].a;
					s[k].a = 0;
					k--;
				}
				else
				{
					ans += s[i].a;
					s[k].a -= s[i].a;
					s[i].a = 0;
					i++;
				}
			}
		}
	} 
	cout << ans;
	return 0;
 } 
