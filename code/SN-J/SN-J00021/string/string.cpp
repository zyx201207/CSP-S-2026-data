#include<bits/stdc++.h>
using namespace std;
int n;
char c[200010];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int cnt = 1;
	for(int i = 1; i <= n; i++)
	{
		int a;
		char b;
		cin >> a >> b;
		for(int j = cnt; j < cnt + a; j++)
		{
			c[j] = b;
		}
		cnt += a;
	}
	long long ans = 0;
	for(int i = 1; i < cnt / 2; i++)
	{
		if(c[i] == c[cnt - i])
		{
			continue;
		}
		else
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
