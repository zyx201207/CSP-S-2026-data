#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long v,w;
};
int mcnt,lt[205];
long long dis[10000005];
bool vis[10000005];
vector<node> mp[10000005];
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		int w;
		cin>>w;
		mp[i].push_back({m+i,w});
		mp[m+i].push_back({i,w});
	}
	mcnt=2*m;
	for(int i=1;i<=n;i++)
	{
		cin>>lt[i];
		int x,y=-1,k; 
		for(int j=1;j<=lt[i];j++)
		{
			cin>>x>>k;
			mp[++mcnt].push_back({m+x,k});
			mp[m+x].push_back({mcnt,k});
			if(y!=-1)
			{
				mp[mcnt].push_back({mcnt-1,0});
				mp[mcnt-1].push_back({mcnt,0});
			}
			y=x;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		for(int j=1;j<=mcnt;j++)
		{
			dis[j]=1e18;
			vis[j]=0;
		}
		dis[x]=0;
		pq.push({0,x});
		while(!pq.empty())
		{
			int u=pq.top().second;
			pq.pop();
			if(vis[u]==1)
			continue;
			vis[u]=1;
			for(auto v:mp[u])
			{
				if(dis[v.v]>dis[u]+v.w)
				{
					dis[v.v]=dis[u]+v.w;
					pq.push({dis[v.v],v.v});
				}
			}
		}
		cout<<dis[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}