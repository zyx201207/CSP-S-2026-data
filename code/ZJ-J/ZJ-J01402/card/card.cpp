#include <bits/stdc++.h>
using namespace std;

struct node
{
	int next,v;
};

node a[300005];
int b[500005],ans[300005],sit[300005],cnt,head[300005];

void add(int u,int v)
{
	cnt++;
	a[cnt].v = v;
	a[cnt].next = head[u];
	head[u] = cnt;
}

void solve(int x)
{
	for(int i = head[x];i;i = a[i].next)
	{
		int v = a[i].v;
		solve(v);
		ans[x] += ans[v];
	}
	return;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> b[i];
		ans[b[i]]++;
		sit[b[i]] = i;
	}
	for(int i = 1;i <= m;i++)
		add(b[sit[i]+1],i);
	solve(b[n]);
	for(int i = 1;i < m;i++)
		cout << ans[i] << " ";
	cout << ans[m];
	return 0;
}
