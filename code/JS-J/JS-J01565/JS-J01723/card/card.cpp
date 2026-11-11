#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e5 + 5;
const int MAXM = 3e5 + 5;
ll n, m;
ll a[MAXN];
ll ans[MAXM];
vector<ll> table;
unordered_map<ll, ll> cntTable;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (ll i = 1; i <= n; i++)
	{
		table.clear();
		cntTable.clear();
		for (ll j = i; j <= n; j++)
		{
			if (cntTable[a[j]] > 0)
			{
				while (table.back() != a[j])
				{
					cntTable[table.back()]--;
					table.pop_back();
				}
				cntTable[table.back()]--;
				table.pop_back();
			}
			table.push_back(a[j]);
			cntTable[a[j]]++;
		}
		for (auto &it : cntTable)
		{
			if (it.second > 0)
				ans[it.first]++;
		}
	}
	for (ll i = 1; i <= m; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}