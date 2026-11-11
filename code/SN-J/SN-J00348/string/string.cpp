#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], ans;
string s, c[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	while (l < r)
	{
		if (c[l] != c[r]) ans++;
		a[l]--, a[r]--;
		if (a[l] == 0) l++;
		if (a[r] == 0) r--;
	}
	cout << ans;
	return 0;
}
