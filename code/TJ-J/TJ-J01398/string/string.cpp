#include<bits/stdc++.h>
using namespace std;
long long n, ans, a[200010];
char c[200010];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> c[i];
	}
	long long nowl = 1, nowr = n;
	while(nowl <= nowr)
	{
		if(a[nowl] == a[nowr])
		{
			if(c[nowl] != c[nowr])
			{
				ans += a[nowl];
			}
			++nowl;
			--nowr;
		}
		else if(a[nowl] < a[nowr])
		{
			a[nowr] -= a[nowl];
			if(c[nowl] != c[nowr])
			{
				ans += a[nowl];
			}
			++nowl;
		}
		else
		{
			a[nowl] -= a[nowr];
			if(c[nowl] != c[nowr])
			{
				ans += a[nowr];
			}
			--nowr;
		}
	}
	cout << ans;
	return 0;
}
//bbbcaaaaaaabbb
//6
//3 b
//1 c
//3 a
//4 a
//1 b
//2 b
