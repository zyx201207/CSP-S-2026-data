#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s = "";
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		int t;
		char c;
		cin >> t >> c;
		while (t--)
		{
			s = s + c;
			len++;
		}
	}
	int len2 = len / 2;
	int lenb = len - len2;
	int ans = 0;
	int j = lenb - 1 - (len % 2);
	for (int i = lenb; i < len; i++)
	{
		if (s[i] != s[j])
		{
			ans++;
		}
		j--;
	}
	cout << ans;
	return 0;
}
