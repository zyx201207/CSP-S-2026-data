#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
bool st[200005];
vector<int> a;
int dfs(vector<int> v, int l)
{
	if(l == -1)
		return 0;
	int ans = 0;
	vector<int> k;
	for(int j : v)
	{
		if(j & (1 << l))
			k.push_back(j);
	}
	if(k.size() < m)
		return dfs(v, l - 1);
	else
		return dfs(k, l - 1) + (1 << l);
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	int l = floor(log2(a[a.size() - 1]));
	int x = dfs(a, l);
	cout << x << '\n';
	return 0;
}
