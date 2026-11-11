#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll a[200010];
ll max_and = -1;
int main()
{
	//freopen("and.in", "r", stdin);
	//freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i + 1;j < m;j++)
		{
			if (a[j] and a[j + 1] > max_and)
				max_and = a[j] & a[j + 1];
		}
	}
	cout << max_and;
	return 0;
}
