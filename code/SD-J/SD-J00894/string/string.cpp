#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 10;

int n;
int a[N];
char c[N];

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	int ans = 0;
	while(l < r)
	{
		if(a[l] <= a[r])
		{
			if(c[l] != c[r])
			{
				ans += a[l];
				a[r] -= a[l];
				l++;
			}
			else
			{
				a[r] -= a[l];
				l++;
			}
		}
		else
		{
			if(c[l] != c[r])
			{
				ans += a[r];
				a[l] -= a[r];
				r--;
			}
			else
			{
				a[l] -= a[r];
				r--;
			}
		}
	}
	cout << ans << endl;
	return 0;
} 
//Trick||Treat! 
