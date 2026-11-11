#include<bits/stdc++.h>
using namespace std;
int n, len = 0, ans = 0;
string s[100000005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int a;
	char c;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> c;
		for (int j = 1; j <= a; j++)
		{
			s[++len] = c;
		}
	}	
	for (int i = 1; i <= len / 2; i++)
	{
		if (s[i] != s[len - i + 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
