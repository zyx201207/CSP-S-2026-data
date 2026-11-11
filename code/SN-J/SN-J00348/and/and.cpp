#include <bits/stdc++.h>
using namespace std;
int n, num[200005], m, ans = -1;
string pr(int x)
{
	string k = "";
	while (x > 0)
	{
		int f = x % 2;
		k += (f+'0');
		x /= 2;
	}
	return k;
}
string pri(int a, int b)
{
	if (a == 0 || b == 0) return "0";
	string x = pr(a), y = pr(b);
	string s = "";
	int maxlen = max(x.length(), y.length());
	for (int i = 0; i < maxlen; i++)
	{
		if ((x[i] == '1') && (y[i] == '1')) s += '1';
		else s += '0';
	}
	return s;
}
int andp(int a, int b)
{
	string s = pri(a, b);
	int nn=0, m = 1;
	for (int i = 0; i < s.length(); i++)
	{
		nn += (m*(s[i]-'0'));
		m *= 2;
	}
	return nn;
}
bool cmp(int a, int b)
{
	return a >= b;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> num[i];
	sort(num+1, num+n+1, cmp);
	ans = num[1];
	for (int i = 2; i <= m; i++)
	{
		ans = andp(num[i], ans);
	}
	cout << ans;
	return 0;
}
