#include <bits/stdc++.h>
using namespace std;
int n,a,cnt; 
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> c;
		for (int j = 1;j <= a;j++)
		{
			s += c;
		}
	}
	for (int i = 0;i < s.length() / 2;i++)
	{
		if (s[i] != s[s.length() - i - 1])
		{
			cnt++;
		}
	}
	cout << cnt;
}
