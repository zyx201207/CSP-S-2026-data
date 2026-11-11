#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int n, m;
int a[MAXN];
unordered_map<int, int> lst;
map<int, int> cnt;
int nxt[MAXN];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = n; i >= 1; i--)
	{
		if(!lst.count(a[i])) lst[a[i]] = i;
		nxt[i] = lst[a[i]];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			if(nxt[j] != j) j = nxt[j];
			cnt[a[j]]++;
		}
	}
	for(auto it : cnt) cout << it.second << " ";
	return 0;
}