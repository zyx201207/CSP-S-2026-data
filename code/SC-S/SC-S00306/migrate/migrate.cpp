#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5000+5,inf=1e18+7;
int n,t,a[N],d,dd,dist[N],ans;
vector<int> g[N];
bool vis[N];
void diji(int st,int ed)
{
	for(int i=1;i<=n;i++){vis[i]=0;dist[i]=inf;}
	queue<int> q;
	q.push(st);
	dist[st]=0;
	int cnt=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vis[u]||u==ed)continue;
		vis[u]=1;
		for(int nxt:g[u])
		{
			int v=nxt;
			if(v==ed&&dist[v]==dist[u]+1)cnt++;
			if(dist[v]>dist[u]+1)
			{
				if(v==ed)cnt=1;
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	} 
	if(cnt==2)ans++;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>dd>>t;
	while(t--)
	{
		for(int i=1;i<=n;i++)a[i]=0;
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			g[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)g[i].push_back(j);
				else break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d)
				diji(i,j);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
