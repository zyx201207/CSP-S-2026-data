#include<bits/stdc++.h>
using namespace std;
int n, a[200005];
long long len, ans;
char x, f[50000000];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> x;
		len += a[i];
		for(int j = len - a[i]; j < len; j++)
			f[j] = x;
	}
	int t = (len - 1) / 2;
	for(int i = 0, j = len - 1; i <= t, j >= t; i++, j--)
	{
		if(f[i] != f[j])
			ans++;
	}
	/*for(int i = 0; i < len; i++)
		cout << f[i];*/
	cout << ans;
	return 0;
}

