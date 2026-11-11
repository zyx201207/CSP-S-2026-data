#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
bool flag = 1;
long long ans = 0;
char only_c = '@';
string s = "", book = "";
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		char temp_c;
		cin >> temp_c;
		book += temp_c;
		if (only_c == '@') only_c = temp_c;
		else if (temp_c != only_c) flag = 0;
	}
	if (!flag)
	{
		flag = 1;
		for (int i = 1; i <= n / 2; i++)
		{
			int j = n - i + 1;
			if (a[i] != a[j] || book[i - 1] != book[j - 1])
			{
				flag = 0;
				break;
			}
		}
	}
	if (flag)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= a[i]; j++) s += book[i - 1];
	}
	int l = s.size();
	for (int i = 0; i <= l / 2; i++)
	{
		int j = l - i - 1;
		if (s[i] != s[j]) ans++;
	}
	cout << ans;
	return 0;
}
