#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6+5;
int data_point_type,T,n,k,box[N],ans,depth[N];
bool vis[N];
vector<int>tree[N];

void flood_fill(int x)
{
	vis[x] = 1;
	for(auto v:tree[x]) if(vis[v] == 0 && box[v]) flood_fill(v);
	return;
}

int dfs_solvedepth(int x,int fa,int dv)
{
	int the_ans = dv;
	for(auto v:tree[x])
	{
		if(box[v] || v == fa) continue;
		the_ans = max(the_ans,dfs_solvedepth(v,x,dv+1));
	}
	return the_ans;
}

int get_ans(void)
{
	for(int i = 1;i <= n;i++) vis[i] = 0;
	int cnt = 0,the_ans = 0;
	for(int i = 1;i <= n;i++)
	{
		if(box[i] && vis[i] == 0)
		{
			flood_fill(i);
			cnt++;
			if(cnt > 2) return n;
		}
	}
	for(int i = 1;i <= n;i++) if(box[i]) the_ans = max(the_ans,dfs_solvedepth(i,0,0));
	return the_ans;
}

void dfs(int steps,int cnt)
{
	if(cnt > k) return;
	if(steps > n)
	{
		if(cnt == k) ans = min(ans,get_ans());
		return;
	}
	box[steps] = 0;
	dfs(steps+1,cnt);
	box[steps] = 1;
	dfs(steps+1,cnt+1);
	return;
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> data_point_type >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i = 1;i <= n;i++) tree[i].clear();
		for(int i = 1;i < n;i++)
		{
			int u,v;
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		ans = n;
		dfs(1,0);
		cout << ans << '\n';
	}
	return 0;
}
