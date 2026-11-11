//高文轩 铜川市第二中学 SN-J00654
#include <bits/stdc++.h>
using namespace std;

int n, r, l = 1;
long long num, cnt;
struct s
{
	int shu;
	char a;
}sh[200010];

int main ()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	r = n;
	for (int i = 1; i <= n; i++)
	{
		cin >> sh[i].shu >> sh[i].a;
		num += sh[i].shu;
	}
	while (l <= r)
	{
		if (sh[l].shu > sh[r].shu)
		{
			num -= 2 * sh[r].shu;
			if (sh[l].a != sh[r].a)
			{
				cnt += sh[r].shu;
			}
			sh[l].shu -= sh[r].shu;
		}
		if (sh[l].shu == sh[r].shu)
		{
			num -= sh[l].shu * 2;
			if (sh[l].a != sh[r].a)
			{
				cnt += sh[l].shu;
			}
			sh[l].shu = 0;
			sh[r].shu = 0;
		}
		if (sh[l].shu < sh[r].shu)
		{
			num -= sh[l].shu * 2;
			if (sh[l].a != sh[r].a)
			{
				cnt += sh[l].shu;
			}
			sh[r].shu -= sh[l].shu;
		}
		if (sh[l].shu == 0)
		{
			l++;
		}
		if (sh[r].shu == 0)
		{
			r--;
		}
	}
	cout << cnt;
	return 0;
}
