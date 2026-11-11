#include <bits/stdc++.h>
using namespace std;

#define int long long

string a[200005];
string zes[105];
queue <int> q;
unordered_set <int> st;

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	zes[0] = "";
	for (int i = 1; i <= 99; i++)
		zes[i] = zes[i - 1] + '0';
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		st.insert(i);
		int tmp;
		cin >> tmp;
		while (tmp)
		{
			a[i] = char(tmp % 2 + '0') + a[i];
			tmp /= 2;
		}
		a[i] = zes[40 - a[i].size()] + a[i];
	}
	int ans = 0;
	for (int k = 0; k < 40; k++)
	{
		int num = 0;
		for (auto i : st)
		{
			num += a[i][k] - '0';
		}
		if (num < m) continue;
		ans += (1LL << (39 - k));
		for (auto i : st)
		{
			if (a[i][k] == '0') q.push(i);
		}
		while (!q.empty())
		{
			st.erase(q.front());
			q.pop();
		}
	}
	cout << ans << '\n';
	return 0;
}
