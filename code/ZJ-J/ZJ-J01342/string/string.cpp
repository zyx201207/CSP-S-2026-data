#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n;
long long a[N];
char c[N];
long long sumlen;
long long ans;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i] >> c[i];
		sumlen += a[i];
	}
	int l = 1, r = n;
	while (l < r)
	{
		if (c[l] == c[r])
		{
			if (a[l] < a[r])
			{
				a[r] -= a[l];
				a[l] = 0;
				l ++;
//				cout << 1;
			}
			else if (a[l] > a[r])
			{
				a[l] -= a[r];
				a[r] = 0;
				r --;
//				cout << 2;
			}
			else if (a[l] == a[r])
			{
				a[l] = 0;
				a[r] = 0;
				l ++;
				r --;
//				cout << 3;
			}
		}
		else
		{
			if (a[l] < a[r])
			{
				ans += a[l];
				a[r] -= a[l];
				a[l] = 0;
				l ++;
//				cout << 4;
			}
			else if (a[l] > a[r])
			{
				ans += a[r];
				a[l] -= a[r];
				a[r] = 0;
				r --;
//				cout << 5;
			}
			else if (a[l] == a[r])
			{
				ans += a[l];
				a[l] = 0;
				a[r] = 0;
				l ++;
				r --;
//				cout << 6;
			}
		}
	}
	cout << ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/