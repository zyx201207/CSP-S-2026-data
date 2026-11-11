#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a[500009], m, ans;
int main ()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//saved
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort (a, a+n);
	ll p = n-1, d = 0;
	// now p will be the exact ending
	// add p-1 will be illegal
	for (int i = n-1; i >= 0; i--)
	{
		if (i != n-1)
		{
			d -= (a[i+1]-a[i])*(i-p+1);
		}
		while (p > 0)
		{
			//att p-1
			if (d+(a[i]-a[p-1]) > m) break;
			d += a[i]-a[p-1];
			p--;
		}
		ans = max(ans,i-p+1);
	}
	cout << ans << endl;
	return 0;
}
