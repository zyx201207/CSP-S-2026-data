#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 

const int N = 2e5 + 5;
int n, a[N];
char c[N];
ll ans;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	int hed = 1, tal = n;
	while (hed < tal)
	{
		if (c[hed] == c[tal])
		{
			if (a[hed] > a[tal])
			{
				a[hed] -= a[tal];
				tal--;
			}
			else if (a[hed] < a[tal])
			{
				a[tal] -= a[hed];
				hed++;
			}
			else
			{
				hed++;
				tal--;
			}
		}
		else
		{
			if (a[hed] > a[tal])
			{
				ans += a[tal];
				a[hed] -= a[tal];
				tal--;
			}	
			else if (a[hed] < a[tal])
			{
				ans += a[hed];
				a[tal] -= a[hed];
				hed++;
			}
			else
			{
				ans += a[hed];
				hed++;
				tal--;
			}
		}
	}
	cout << ans << endl;
	return 0;	
} 
