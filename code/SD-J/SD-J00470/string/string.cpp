#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<int> a;
vector<char> c;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	a.resize(n + 1);
	c.resize(n + 1);
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	int l = 1; int r = n;
	while(l < r)
	{
		if(c[l] == c[r])
		{
			if(a[l] >= a[r])
			{
				a[l] -= a[r];
				r--;
				if(a[l] == 0) l++;
			}
			else
			{
				a[r] -= a[l];
				l++;
			}
		}
		else
		{
			if(a[l] >= a[r])
			{
				ans += a[r];
				a[l] -= a[r];
				r --;
				if(a[l] == 0) l ++;
			}
			else
			{
				ans += a[l];
				a[r] -= a[l];
				l++;
			}
		}
	}
	cout << ans;
}
