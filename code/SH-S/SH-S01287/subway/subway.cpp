#include <bits/stdc++.h>
using namespace std;

const int N=505, M=5e4+5, D=25;
int c, n, m, d, q;

int k[N];
int cnt[M];
int a[N][M];
int t[N][M];

int w[M];

int vis[N];
int vis2[M];

int tim=M*2;

int dfs(int s, int to,int last, int l)
{
	int cost=M*2;
	
	if (a[l][to])
		return last+t[l][to];
		
	for (int x=1;x<=m;x++)
	{
		if (vis[x]||cnt[x]<2||!a[l][x]||x==s) continue;
		for (int e=1;e<=n;e++)
		{
			if (vis[e] || !a[e][x] || e==l) continue;
			vis[e]=1;
			cost=min(cost, dfs(x,to,t[l][x]+t[e][x],e));
			vis[e]=0;
		}
	}
	
	if (cost==M*2) return last; 
	return last+cost;
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i]; 
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			int s;
			cin >> s;
			cnt[s]++;
			a[i][s]=1;
			cin>>t[i][s];
		}
	}
	
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		tim=M*2;
		for (int e=1;e<=n;e++)
		{
			if (a[e][x])
		    	tim=min(tim, dfs(x, y, w[x]+w[y], e)+t[e][x]);
		}
		cout << tim << '\n';
	}
	return 0;
}
