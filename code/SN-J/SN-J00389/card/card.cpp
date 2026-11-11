#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 10;

int n, m, a[maxn], cnt[maxn];
vector<int> now[maxn];
int vis[maxn];

int main ()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int i = 1; i <= m; i++) vis[i] = 0;
		now[i].push_back(-50);
		int tail = 1;
		now[i].push_back(a[i]);
		vis[a[i]] = 1;
		for (int j = i + 1; j <= n; j++)
		{
			if (vis[a[j]] == 0)
			{
				now[i].push_back(a[j]);
				tail++;
				vis[a[j]]++;
			}
			else
			{
				while (now[i][tail] != a[j])
				{
					vis[now[i][tail]]--;
					now[i].pop_back();
					tail--;
				}
				vis[now[i][tail]]--;
				now[i].pop_back();
				tail--;
				now[i].push_back(a[j]);
				tail++;
				vis[a[j]]++;
			}
		}
		for (int j : now[i])
		{
			cnt[j]++;
		}
	}
	for (int i = 1; i <= m; i++) cout << cnt[i] << ' ';
	return 0;
}

