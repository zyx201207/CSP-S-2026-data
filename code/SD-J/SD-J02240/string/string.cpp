#include <bits/stdc++.h>
using namespace std;
int n;
long long l;
string s, ss;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r", stdin);
	freopen("string.out","w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a; 
		char c;
		cin >> a >> c;
		l += a;
		for (int j = 1; j <= a; j++)
			s = s + c;
	}
	ss = s;
	reverse(ss.begin(), ss.end());
	l /= 2;
	long long ans = l;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == ss[i])
			ans --;
	}
	cout << ans << endl;
	return 0;
}
