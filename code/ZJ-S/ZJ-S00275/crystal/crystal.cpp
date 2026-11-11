#include<bits/stdc++.h>
#define int long long
#define mkp make_pair
#define vc vector
#define INF 2147483647
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

constexpr int N = 500011;

int n, m, ans;
int a[N], sum[N];


signed main()
{
	IOS;
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, [](int x, int y){  return x < y;  });
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1, j = 1; i <= n; i++)
	{
		while (a[i] * (i - j + 1) - (sum[i] - sum[j - 1]) > m && j <= n) j++;
		ans = max(ans, i - j + 1);
	}
	cout << ans << endl;
	return 0;
}
/*

*/