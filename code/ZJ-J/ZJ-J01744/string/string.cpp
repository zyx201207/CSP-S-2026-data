#include <bits/stdc++.h>
using namespace std;
int a[200005];
string s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string u;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> s[i];
		for (int j = 1;j <= a[i];j++)
		{
			u += s[i];
		}
	}
	int ans = 0;
	for (int i = 0;i < u.size() / 2;i++)
	{
		if (u[i] != u[u.size() - i - 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
