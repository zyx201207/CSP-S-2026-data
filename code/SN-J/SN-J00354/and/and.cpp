#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+7;
ll n, a[N], dp[N], maxn, m;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << a[2] and a[3];
	return 0;
}
