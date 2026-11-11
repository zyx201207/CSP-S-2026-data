#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,n,m,s[N],dis[N],cnt[N];
vector <int> graph[N];
queue <int> q;
void bfs(int x)
{
	memset(dis,127,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	dis[x]=0;q.push(x);cnt[x]=1;
	while(!q.empty())
	{
		int k=q.front();q.pop();
		for(int i=0;i<graph[k].size();i++)
		{
			int v=graph[k][i];
			if(dis[v]>dis[k]+1) dis[v]=dis[k]+1,cnt[v]=cnt[k],q.push(v);
			else if(dis[v]==dis[k]+1) cnt[v]+=cnt[k];
		}
	}
}
void work()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) graph[i].clear();
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(s[j]-s[i]<=m) graph[i].push_back(j);
	int res=0;
	for(int i=1;i<=n;i++)
	{
		bfs(i);
		for(int j=i+1;j<=n;j++)
			if(cnt[j]==2) res++;
	}
	cout<<res<<"\n";
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;cin>>c>>t;
	while(t--) work();
	return 0;
}
