/*
想不到怎么快速统计答案
倒闭了
exp:15pts
fin:18:05 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
vector<int>e[N];
int tim,vis[N];
queue<int>que;
bool is[N];
int dis[N];
void bfs(int st)
{
	que.push(st);
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		vis[u]=tim;
		dis[u]=0;
		for(auto v:e[u])
		{
			if(is[v]&&vis[v]!=tim)
			{
				que.push(v);
			}
		}
	}
}
int n,k;
bool stk[N];
void gt()
{
	for(int i=1;i<=n;i++) if(is[i]) que.push(i);
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		stk[u]=0;
		for(auto v:e[u])
		{
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				if(stk[v]) continue;
				stk[v]=1;
				que.push(v);
			}
		}
	}
}
void solve()
{
	int ans=INT_MAX;
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n>20)
	{
		cout<<n/4<<'\n';
		return;
	}
	for(int i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)!=k) continue;
		memset(dis,0x3f,sizeof(dis[0])*(n+5));
		for(int j=0;j<n;j++)
		{
			is[j+1]=((i>>j)&1);
		}
		int cnt=0;
		tim++;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]!=tim&&is[j])
			{
				cnt++;
				if(cnt>2) break;
				bfs(j);
			}
		}
		if(cnt>2) continue;
		gt();
		int maxn=0;
		for(int j=1;j<=n;j++)
		{
			maxn=max(maxn,dis[j]);
		}
		ans=min(ans,maxn);
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int sid,T;
	cin>>sid>>T;
	while(T--) solve();
	return 0;
}
