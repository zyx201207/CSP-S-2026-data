#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> e[N];
int dp[N][N];
bool ch[N][N];
int f[N];
int sz[N];
int n,K;
int mxle[N][2];
void dfs(int u,int last)
{
	f[u] = last;
	sz[u] = 1;
	for(int i = 0;i < e[u].size();i ++)
	{
		int v = e[u][i];
		if(v == last) continue;
		dfs(v,u);
		ch[u][v] = 1;
		for(int j = 1;j <= n;j ++)
		{
			ch[u][j] |= ch[v][j];
		}
		for(int j = min(K,sz[u]);j >= 1;j --)
		{
			for(int k = 0;k <= min(sz[v],j);k ++)
			{
				dp[u][j + k] = max(dp[u][j],dp[v][k]);
			}
		}
		dp[u][0] = max(dp[u][0],dp[v][0] + 1);
	}
	return;
}
void dfs2(int now,int last,int st,int ed,bool F)
{
	mxle[now][F] = mxle[last][F] + 1;
	for(int i = 0;i < e[now].size();i ++)
	{
		int v = e[now][i];
		if(f[v] == st || v == ed || v == last) continue;
		dfs2(v,now,st,ed,F);
	}
}
void solve()
{
	cin >> n >> K;
	for(int i = 1;i <= n;i ++)
	{
		e[i].clear();
		for(int j = 1;j <= n;j ++) 
		{
			dp[i][j] = 1e9;
			ch[i][j] = 0;
		}
		dp[i][0] = 1;
		dp[i][1] = 0;
	}
	for(int i = 1;i < n;i ++)
	{
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	mxle[0][0] = -1;
	mxle[0][1] = -1;
	int ans = 1e9;
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= n;j ++)
		{
			if(ch[i][j] || ch[j][i]) continue;
			for(int k = 1;k < K;k ++)
			{
				int now = max(dp[i][min(sz[i],k)],dp[j][min(sz[j],k)]);
				for(int I = 1;I <= n;I ++)
				{
					mxle[I][0] = 0;
					mxle[I][1] = 0;
				}
				dfs2(i,0,i,j,0);
				dfs2(j,0,j,i,1);
				for(int I = 1;I <= n;I ++)
				{
					now = max(now,min(mxle[I][0],mxle[I][1]));
				}
				cout << i << ' ' << j << ' ' << now << '\n';
				ans = min(ans,now);
			}
		}
	}
	cout << ans << '\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin >> c >> T;
	while(T --)
	{
		solve();
	}
	return 0;
}
