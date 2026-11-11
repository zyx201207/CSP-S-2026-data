#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k, ji, ti, xr, yr;
long long f;
struct p
{
	int cnt, t[25];
};
p a[500010];
bool used[500010];
int w[500010];
long long dfs(int s, long long sum)
{
	for (int i = 1;i <= d; i++)
	{
		if(a[s].t[i]==0) continue;
		used[i]=1;
		used[i]=0;
	}
}
int main()
{
	freopen("aubway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		for (int j = 1; j <= k; j++)
		{
			scanf("%d %d", &ji, &ti);
			a[ji].t[i]=ti;
			a[ji].cnt++;
		}
	}
	while (q--)
	{
		f=0;
		scanf("%d %d", &xr, &yr);
		used[xr]=1;
		f+=w[xr]+w[yr];
	}
	return 0;
}
