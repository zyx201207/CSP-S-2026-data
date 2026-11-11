#include<bits/stdc++.h>
using namespace std;

long long n, ans, pot = 1, tot;
long long a[200005];
char b[200005];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	long long n;
	cin >> n;
	tot = n;
	for(int i = 1; i <= n; i++)
	{
		long long x;
		char m;
		cin >> x >> m;
		a[i] = x;
		b[i] = m;
	}
	for(int i = 1; i <= n; i++)
	{
		if(b[tot] == b[pot])
		{
			if(a[pot] < a[tot])
			{
				a[tot] -= a[pot];
				pot++;
			}
			else if(a[pot] > a[tot])
			{
				a[pot] -= a[tot];
				tot--;
			}
			else
			{
				pot++;
				tot--;
			}
		}
		else
		{
			if(a[pot] < a[tot])
			{
				a[tot] -= a[pot];
				ans += a[pot];
				a[pot] = 0;
				pot++;
			}
			else if(a[pot] > a[tot])
			{
				a[pot] -= a[tot];
				ans += a[tot];
				a[tot] = 0;
				tot--;
			}
			else
			{
				ans += a[pot];
				a[pot] = 0;
				a[tot] = 0;
				pot++;
				tot--;
			}
		}
		if(tot == pot)break;
	}
	cout << ans;
	
	return 0;
} 
