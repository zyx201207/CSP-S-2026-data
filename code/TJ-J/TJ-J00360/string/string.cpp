#include <bits/stdc++.h>
using namespace std;
int n, a, cnt = 0;
string c, s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a >> c;
		while(a--) s += c;
	}
	int l = 0, r = s.length() - 1;
	while(l < r)
	{
		if(s[l] != s[r]) cnt++;
		l++;
		r--;
	}
	cout << cnt;
	return 0;
}
