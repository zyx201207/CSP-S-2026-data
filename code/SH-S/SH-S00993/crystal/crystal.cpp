#include <iostream>
#include <algorithm>
#define endl '\n'
#define int long long
using namespace std;

const int N = 5e5 + 2; 
int n, m, a[N], pre[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
	} 
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + a[i];
	} 
	int j = 1, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		while (a[i] * (i - j + 1) - (pre[i] - pre[j - 1]) > m && j + 1 <= i)
		{
			j++; 
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans << endl;
	cout.flush(); 
	return 0;
}
