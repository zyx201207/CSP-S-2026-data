#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5,M = 3e5 + 5;
int a[N];
int to[N];
int last[M];
int w[N];
int cnt[M];
int sz[N];
vector<int> v[N];
void dfs(int now)
{
	sz[now] = 1;
	for(int i = 0;i < v[now].size();i ++)
	{
		int u = v[now][i];
		dfs(u);
		sz[now] += sz[u];
	}
	if(w[now] != 0)
	{
		cnt[w[now]] += sz[now];
	}
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i = n;i >= 1;i --)
	{
		if(last[a[i]] == 0)
		{
			v[i + 1].push_back(i);
			to[i] = i + 1;
			w[i] = a[i];
		}
		else
		{
			v[last[a[i]]].push_back(i);
			to[i] = last[a[i]];
		}
		last[a[i]] = i;
	}
	dfs(n + 1);
	for(int i = 1;i <= m;i ++)
	{
		cout << cnt[i] << ' ';
	}
	return 0;
}
