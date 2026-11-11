#include <bits/stdc++.h>
#define ull unsigned long long
#define endl '\n'
using namespace std;

const ull N = 2e5 + 10;

ull n, nt = 0, ans = 0;
ull a[N];
char c[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (ull i = 1; i <= n; i++)
	{
	  	cin >> a[i] >> c[i];
	  	nt += a[i];
	}
	
	int l = 1, r= n;
	while (l < r)
	{
		int t = min(a[l], a[r]);
		if (c[l] != c[r])
		{
			ans += t;
		}
		a[l] -= t, a[r] -= t;
		if (a[l] == 0 && a[r] != 0)
		{
			l += 1;
		}
		else if (a[l] != 0 && a[r] == 0)
		{
			r-=1;
		}
		else if (a[l] == 0 && a[r] == 0)
		{
			l+=1, r-=1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
