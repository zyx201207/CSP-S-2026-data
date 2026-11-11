#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e9 + 10; 

int n;
int a[N];
char c[N];
string x;
string y;
int ans; 
int cnt = -1;
int len;

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i] >> c[i]; 
		for(int j=1; j<=a[i]; j++)
		{
			x += c[i];
		}
		len += a[i];
	}
	for(int i=n; i>=1; i--)
	{
		for(int j=1; j<=a[i]; j++)
		{
			y += c[i];
		}
	}
	for(int i=0; i<len/2; i++)
	{
		if(x[i] != y[i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
