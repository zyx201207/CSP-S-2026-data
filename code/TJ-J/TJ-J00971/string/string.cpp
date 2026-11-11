#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a[10005];
	string c;
	string s;
	cin >> n;
	int ii = 1;
	long long aa = 0;
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		for (int j = 1;j <= a[i];j++)
		{
			s[ii] = c[i];
			ii++;
		}
		aa += a[i];
	}
	for(int i = 1;i <= aa / 2;i++)
	{
		if(s[i] != s[aa + 1 - i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
