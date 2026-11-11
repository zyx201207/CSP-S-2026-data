#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
int T;
int n,m;
int a[N];
int res = 0;
vector <int> g[N];
int vis[N];
int cnt[N];
void bfs(int s)
{
	queue <int> q;
	q.push(s);
	vis[s] = 1;
	while(!q.empty())
	{
		int front = q.front();q.pop();
		for(auto it : g[front])
		{
			q.push(it);
			if(vis[it] == 0){vis[it] = vis[front] + 1;}
			else if(vis[it] == vis[front] + 1){cnt[it] ++;}
		}
	}
}
void solve()
{
	cin >> n >> m;
	bool flag = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i]; 
	}
	for(int i = 1;i < n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			if(a[j] - a[i] <= m)
			{
				g[i].push_back(j);
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		bfs(i);
		for(int i = 1;i <= n;i++)
		{
			if(cnt[i] == 2)
			{
				res ++;
			}
		}
	}
	cout << res << endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin >> c;
	cin >> T;
	while(T--)
	{
		solve();
	}
	return 0;
}


