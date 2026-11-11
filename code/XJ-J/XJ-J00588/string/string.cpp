#include <bits/stdc++.h>
using namespace std;

string s;
int n, duan, cnt;
char c;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> duan >> c;
		while (duan --)
		{
			s += c;
		}
	}
	int l = 0, r = s.size() - 1;
	while (l <= r)
	{
		if (s[l] != s[r])
		{
			cnt ++;
		}
		l ++, r --;
	}
	cout << cnt;
	return 0;
}
