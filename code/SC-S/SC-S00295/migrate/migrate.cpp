#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2000005;
int c, t, vis[maxn];
ll x[maxn], n, d;

int minm;
void dfs(int i, int m, int v){
	if(i == v)
	{
		if(m < minm)
		{
			minm = m;
			vis[v] = 0;
		}
		if(m == minm)vis[v]++;
		return;
	}
	for(int j = i+1; j <= n; ++j)
	{
		if(x[j] - x[i] <= d)dfs(j, m+1, v);
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--)
	{
		scanf("%d%d", &n, &d);
		memset(x, 0, sizeof(x));
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; ++i)
		{
			scanf("%lld", &x[i]);
		}
		ll ans = 0;
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				minm = 2000005;
				dfs(i, 0, j);
				if(vis[j] == 2)++ans;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}