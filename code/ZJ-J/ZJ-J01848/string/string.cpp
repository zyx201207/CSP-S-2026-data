#include <bits/stdc++.h>
using namespace std;
long long n, ans;
int a[234567];
char c[201001];
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	int l = 0, r = n;
	while (l <= r)
	{
		if (c[l] != c[r])
		{
			if (a[l] > a[r]) 
			{
				ans += a[r];
				a[l] -= a[r];
				r--;
			}
			else if (a[l] < a[r])
			{
				ans += a[l];
				a[r] -= a[l];
				l++;
			}
			else 
			{
				ans += a[l];
				a[l] = 0, a[r] = 0;
				l++, r--;
			}
		}
		else if (c[l] == c[r])
		{
			if (a[l] > a[r]) 
			{
				a[l] -= a[r];
				r--;
			}
			else if (a[l] < a[r])
			{
				a[r] -= a[l];
				l++;
			}
			else 
			{
				a[l] = 0, a[r] = 0;
				l++, r--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}