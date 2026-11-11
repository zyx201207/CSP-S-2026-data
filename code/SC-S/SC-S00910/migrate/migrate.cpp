#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=2e6+5;
int n;
ll x[N],ans;
vector <int> g[N];
void bfs(int k)
{
	queue<pair<int,int> > q;
	int dis[n+5];
	int cnt[n+5];
	for(int i=1;i<=n;i++) dis[i]=-1,cnt[i]=0;
	q.push({k,0});
	while(!q.empty())
	{
		int u=q.front().first;
		int w=q.front().second;
		q.pop();
		if(dis[u]==-1)	dis[u]=w,cnt[u]=1;
		else if(dis[u]==w)	cnt[u]++;
		else continue;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];	
			q.push({v,w+1});
		} 
	}
	for(int i=1;i<=n;i++) if(cnt[i]==2) ans++;
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			for(int j=i-1;j>=1;j--)
			{
				if(x[i]-x[j]>d)	break;
				g[j].push_back(i);
			}
		}
		for(int i=1;i<n;i++)
			bfs(i);
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}