#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5010,M = 3e7,inf = 0x3f3f3f3f;
int n,head[N],nex[M],to[M],tot,dis[N],cnt[N];
bool vis[N];
ll d,a[N];
void add(int x,int y)
{
	to[++tot] = y,nex[tot] = head[x],head[x] = tot;
}
void bfs(int st)
{
	queue<int> q;
	for(int i = 1;i <= n;++i) dis[i] = inf,vis[i] = cnt[i] = 0;
	q.push(st);
	dis[st] = 0;
	cnt[st] = 1;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x];i;i = nex[i])
		{
			int y = to[i];
			if(dis[y] > dis[x] + 1)
			{
				dis[y] = dis[x] + 1;
				cnt[y] = cnt[x];
				q.push(y);
			}
			else if(dis[y] == dis[x] + 1) cnt[y] += cnt[x]; 
		}
	}
}
void solve()
{
	tot = 0;
	cin >> n >> d;
	for(int i = 1;i <= n;++i) head[i] = 0;
	for(int i = 1;i <= n;++i) cin >> a[i];
	for(int i = 1;i <= n;++i)
	{
		for(int j = i + 1;j <= n;++j)
		{
			if(abs(a[i] - a[j]) > d) break;
			add(i,j);add(j,i);
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;++i)
	{
		bfs(i);
		for(int j = i + 1;j <= n;j++)
		{
			if(cnt[j] == 2)
			{
				++ans;
			}
		}
	}
	cout << ans << '\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int C,T;
	cin >> C >> T;
	while(T--) solve();
	return 0;
}
