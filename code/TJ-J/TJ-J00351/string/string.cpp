#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	for(int i = 1;i <= n;i++)
	{
		int m;
		cin >> m;
		string c;
		cin >> c;
		for(int j = 1;j <= m;j++)
			s += c;
	}
	int l = s.size(),ans = 0;
	for(int i = 1;i < l;i++)
	{
		s[i] != s[l + 1 - i];
		ans++;
	}
	cout << ans / 2;
	return 0;
}
