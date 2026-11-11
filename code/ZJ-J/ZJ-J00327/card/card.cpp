#include <bits/stdc++.h>
using namespace std;

vector<int> t;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n + 1], ans[m + 1], last[m + 1];
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		last[a[i]] = i;
	}
	for (int i = 1; i <= m; i++) ans[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		t.resize(0);
		for (int j = i; j <= n; j++)
		{
			if (last[a[j]] != j) j = last[a[j]];
			t.push_back(a[j]);		
		}
		for (int k = 0; k < t.size(); k++) ans[t[k]]++;
	}
	
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	
	return 0;
}
