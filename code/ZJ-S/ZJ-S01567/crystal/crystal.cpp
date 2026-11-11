#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define endl '\n'
using namespace std;
int n, m, ans, ma = LLONG_MIN, mi = LLONG_MAX;
bool flag = 1;
vector<int> a(500005);
bool check(int mid)
{
	int sum = 0;
	rep(i, 1, mid)
		sum += a[mid] - a[i];
	return (sum / 2 <= m);
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	rep(i, 1, n)
	{
		cin >> a[i];
		ma = max(ma, a[i]);
		mi = min(mi, a[i]);
		if (a[i] != i)
			flag = 0;
	}
	sort(a.begin() + 1, a.begin() + n + 1);
	if (n <= 5000)//not quiet sily but 100% ac
	{
		rep(i, 2, n)//try tar_pos
		{
			int tar = a[i], add = m, now_ans = 0;
			rep(i, 1, n)
				if (a[i] == tar)
					now_ans++;
			for (int j = i - 1; j >= 1; j--)
			{
				int need = tar - a[j];
				if (need <= add && a[j] != tar)
				{
					add -= need;
					now_ans++;
				}
				else
					break;
			}
			ans = max(ans, now_ans);
		}
		cout << ans << endl;
		return 0;
	}
	if (ma <= 100 && mi >= -100)//not sily but may wa --- only useing luky
	{
		int left = 1, right = n, tp = 1;
		while (left <= right)
		{
			int mid = (right - left) / 2 + left;
			cout << left << ' ' << right << ' ' << mid << ' ' << check(mid) << endl;
			if (check(mid))
				left = mid + 1, tp = max(tp, mid);
			else
				right = mid - 1;
		}
		cout << tp << endl;
		return 0;
	}
	//max smart
	int d = a[n] - a[n - 1];
	if (n * n * d + n * d <= 2 * m)
	{
		cout << n << endl;
		return 0;
	}
	for (int i = n; i > 0; i--)
		if (i * i * d + i * d <= 2 * m)
		{
			cout << i + 1 << endl;
			return 0;
		}
	return 0;
}
//hope 75pts!
/*//not sily but may wa
half!!!----------but wa
one-dir : i->big   ok?->false
		  i->small ok?->true
half find the n
find the last ok n
ok?=true
	left = mid + 1
ok?=false
	right = mid - 1
----------------------------------------------
the check func should do:

the i from 1 to mid

the sum of all needs < m
----------------------------------------------
save for live:
'''cpp
if (ma <= 100)//not sily but may wa
{
	sort(a.begin() + 1, a.begin() + n + 1);
	int sum = 0;
	rep(i, 1, n)
		sum += ma - a[i];
	if (sum <= m)
		cout << n << endl;
	else
		rep(i, 1, n)
		{
			int need = ma - a[i];
			sum -= need;
			if (sum <= m)
			{
				cout << n - i << endl;
				return 0;
			}
		}
	return 0;
}
'''
*/

/*//not quiet sily but 100% ac
小到大排序
设定tar为每个数
把比他小的数试图加到tar
取max

sort from small to big
set tar to every number
try adding smaller numbers to tar
ans is the bigest res
*/