#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5, maxm = 3e5 + 5;
int a[maxn], cnt[maxm];
vector<int> lst[maxm];
bool vis[maxn];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
	for(int st = 1; st <= n; st++)
	{
		for(int i = 1; i <= m; i++)lst[i].clear();
		memset(vis, 0, sizeof(vis));
		for(int i = st; i <= n; i++)
		{
			if(lst[a[i]].size())
			{
				for(int j = i - 1; j >= lst[a[i]][lst[a[i]].size() - 1]; j--)
				{
					 if(!vis[j])lst[a[j]].pop_back();
					vis[j] = 1;
				}
			}
			lst[a[i]].push_back(i);
		}
		for(int i = st; i <= n; i++)if(!vis[i])cnt[a[i]]++;
	}
	for(int i = 1; i <= m; i++)printf("%d ", cnt[i]);
	return 0;
}
