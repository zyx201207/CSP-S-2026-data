#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n;
int maxn = 1;
ll m;
ll a[N], d[N], b[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i ++)
	{
		d[i - 1] = a[i] - a[i - 1];
		b[i] = b[i - 1] + (i - 1) * d[i - 1];
		if (b[i] <= m) maxn ++;
	}
	for (int r = 2; r <= n; r ++)
	{
		int l = lower_bound(b + 1, b + n + 1, b[r] - m) -b;
		if (b[l] > b[r] - m) l --;
		if (l) maxn = max(maxn, r - l + 1); 
	}
	cout << maxn;
	return 0;
}
