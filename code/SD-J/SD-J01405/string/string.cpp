#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n;
string s;
int ans;

struct node
{
	int a;
	char c;
}a[N];

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i].a >> a[i].c;
	}
	
	int l = 1, r = n;
	while (l < r)
	{
		if (a[l].a < a[r].a)
		{
			if (a[l].c != a[r].c)
			{
				ans += a[l].a;
				a[r].a -= a[l].a;
				a[l].a = 0;
				l ++;
			}
			else
			{
				a[r].a -= a[l].a;
				a[l].a = 0;
				l ++;
			}
		}
		else if (a[l].a == a[r].a)
		{
			if (a[l].c != a[r].c)
			{
				ans += a[l].a;
				a[l].a = 0;
				a[r].a = 0;
				l ++,r --;
			}
			else
			{
				a[l].a = 0;
				a[r].a = 0;
				l ++;
				r --;
			}
		}
		else
		{
			if (a[l].c != a[r].c)
			{
				ans += a[r].a;
				a[l].a -= a[r].a;
				a[r].a = 0;
				r --;
			}
			else
			{
				a[l].a -= a[r].a;
				a[r].a = 0;
				r --;
			}
		}
//		cout << "666" << '\n';
	}
	
	cout << ans;
	
	return 0;
}
/*

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/ 

