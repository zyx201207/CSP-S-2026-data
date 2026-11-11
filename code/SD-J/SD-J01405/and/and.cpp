#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n,m;
int ans1;
int ans2;
int f;
struct node{
	int a;
	int number_1;
}a[N];

bool cmp(node a, node b)
{
	return (a.number_1 > b.number_1) || (a.number_1 == b.number_1 and a.a > b.a);
}

bool cmp1(node a, node b)
{
	return a.a > b.a;
}

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		int cnt = 0;
		cin >> a[i].a;
		int t = a[i].a;
		while (t)
		{
			if (t & 1)	cnt ++;
			t /= 2;
		}

		a[i].number_1 = cnt;
	}
	
	
	
	sort(a + 1, a + 1 + n, cmp);
	
//	for (int i = 1; i <= n; i ++)
//	{
//		cout << a[i].a << ' ';
//	}
	
	ans1 = a[1].a;
	for (int i = 2; i <= m; i ++)
	{
		if (ans1 & a[i].a != 0)
		{
			ans1 = ans1 & a[i].a;
		}
//		cout << ans1 << '\n';
	}
	
	ans2 = a[m].a;
	for (int i = m - 1; i >= n - m + 1; i --)
	{
		if (ans2 & a[i].a != 0)
		{
			ans2 = ans2 & a[i].a;
		}
	}
	
	cout << max(ans1, ans2);
	
	return 0;
}
 

