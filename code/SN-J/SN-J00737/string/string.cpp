// 阮文轩 西北大学附属中学 SN-J00737
#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char b[200005];
vector<char> s;
int ans, n;
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= a[i]; j++)
			s.push_back(b[i]);
	}
	int ans = 0;
	for (int i = 0; i < s.size() / 2; i++)
		if (s[i] != s[s.size() - i - 1])
			ans++;
	cout << ans;
	return 0;
}
