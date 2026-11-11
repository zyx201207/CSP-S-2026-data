#include<bits/stdc++.h>
#define MX 4000000
#define int long long
using namespace std;
int head[MX + 10],to[MX + 10],nxt[MX + 10],cnt;
int c,T,n,k,ans;
void add(int u,int v)
{
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
int dfs(int p,int fa)
{
	int mx,cmx;
	mx = cmx = 0;
	for (int i = head[p];i;i = nxt[i])
	{
		if (to[i] != fa)
		{
			int now = dfs(to[i],p);
			if (now > mx) mx = now;
			else if (now > cmx) cmx = now;
		}
	}
	ans = max(ans,mx + cmx);
	return mx + 1;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1;i <= n;i++) head[i] = 0;
		ans = cnt = 0;
		for (int i = 1,u,v;i < n;i++)
		{
			cin >> u >> v;
			add(u,v);
			add(v,u);
		}
		dfs(1,0);
		if (n <= k) cout << 0 << '\n';
		else if (ans <= k) cout << 1 << '\n';
		else cout << max(1ll,(ans - k + 1) / 2) << '\n';
	}
	return 0;
}
