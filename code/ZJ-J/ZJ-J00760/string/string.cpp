#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	int a;
	char c;
	long long ans = 0;
	while(n--)
	{
		cin >> a >> c;
		while(a--)
		{
			s += c;
		}
	}
	int t = s.size();
	for(int i = 0;i <= (t - 1) / 2;i++) ans += (s[i] != s[t - 1 - i]);
	cout << ans;
	return 0;
}