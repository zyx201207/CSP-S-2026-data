#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,m = 0,num = 0;
	char c;
	string s = "";
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> c;
		m += a;
		for (int j = 1;j <= a;j++)
		{
			s += c;
		}
	}
	for (int i = 0;i < m / 2;i++)
	{
		if (s[i] != s[m - i - 1])
		{
			num++;
		}
	}
	cout << num;
	return 0;
}
