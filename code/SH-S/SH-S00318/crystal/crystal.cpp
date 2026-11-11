#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500010];

//void solve1()
//{
//	sort(a+1, a+n+1);
//	long long maxn = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		long long cnt = 0;
//		long long mm = m;
//		for (int j = i-1; j >= 1; j--)
//		{
//			if((a[i] - a[j]) <= mm)
//			{
//				mm -= (a[i] - a[j]);
//				cnt++;
//			}
//		}
//		maxn = max(maxn, cnt+1);
//	}
//	cout << maxn << endl;
//}

bool check(int x)
{
	long long minn = 0x3f3f3f3f, s = 0;
	for (int i = 1; i <= x; i++)
	{
		s += a[x] - a[i];
	}
	minn = min(s, minn);
	for (int i = x+1; i <= n; i++)
	{
		s -= (a[i-1] - a[i-x]);
		s += x*(a[i] - a[i-1]);
		minn = min(s, minn);
	}
	return minn <= m;
}
void solve2()
{
	sort(a+1, a+n+1);
	int l = 1, r = n, mid;
	while (l <= r)
	{
		mid = (l+r)/2;
		if(check(mid)) l = mid+1;
		else r = mid-1;
	}
	cout << r << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
//	if(n <= 5000)
//	{
		solve2();
//	}
	return 0;
}
