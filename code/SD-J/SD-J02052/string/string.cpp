#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;
	char c;
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> c;
		while (x--)
		{
			s += c;
		}
	}
//	cout << "S:" << s.size() << "\n";
	int mid = s.size() / 2;
	int ans = 0;
	int l,r;
	if (s.size() % 2 == 1)
	{
		l = mid,r = mid;
	}
	else
	{
		l = mid - 1,r = mid;
	}
	while (l <= r && l >= 0 && r < s.size())
	{
//		cout << "l:" << l << "--" << "r:" << r << "\n";
		if (s[l] != s[r]) ans++;
		l--;
		r++;
	}
	cout << ans;
}
/*

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
struct No
{
	int num;
	char c;
	int used;
}a[N],b[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].num >> a[i].c;
		a[i].used = 0;
	}
	int ii = n;
	for (int i = 1;i <= n;i++)
	{
		int xy = a[i].num - a[i].used;
		int you = a[ii].num - a[ii].used
		char nc = a[i].c;
		char pc = a[ii].c;
		if (xy > you) 
		{
			a[i].used = a[i].num;
			a[ii].used = a[ii].num;
			int qian = xy - you;
			int smc = 0;
			while (qian == you)
			{
				ii--;
				if (qian > a[ii].num + you)
				{
					if (a[ii].c == nc) smc += a[ii].num;
					you += a[ii].num;
					a[ii].used = a[ii].num;
				}
				else
				{
					you = qian;
					a[ii].used = a[ii].num - (qian - you);
					if (a[ii].c == nc) smc += a[ii].used;
				}
			}
			ans += qian - smc;
		}
		else
		{
			a[i].used = a[ii].num;
			while (a[i].used == a[i].num)
			{
				ii--;
				if (a[ii].num < a[i].num - a[i].used)
				{
					a[i].used += a[ii].num;
					if (a[i].c != a[ii].c) ans += a[ii].num;
				}
				else
				{
					a[i].used = a[i].num;
					a[ii].used = a[ii].num - a[i].num + a[i].used;
					if (a[i].c != a[ii].c) ans += [ii].num - a[i].num + a[i].used;
				}
			}
		}
	}
	cout << ans;
	return 0;
}

*/
