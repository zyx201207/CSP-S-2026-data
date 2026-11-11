#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, cnt;
int a[200010];
char c[200010];
int l;
string s;
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	s += ' ';
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		cin >> c[i];
		l += a[i];
		while (a[i]--)
			s += c[i];
	}	
	for (int i = 1; i <= l / 2; i ++)
	{
		if (s[i] != s[l - i + 1])
			cnt ++;
	}	
	cout << cnt << '\n';
	return 0;
}
