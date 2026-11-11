#include <bits/stdc++.h>
using namespace std;
char str[1000000010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		for (int j = cnt; j < a + cnt; j++)
			str[j] = c;
		cnt += a;
	}
	int len = strlen(str);
	int ans = 0;
	int i = 0, j = len - 1;
	while(i <= j)
	{
		if (str[i] != str[j])
			ans++;
		i++, j--;
	}
	cout << ans << "\n";
	return 0;
}
