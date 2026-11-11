#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
//#define int long long
int c;
int n,m,d,q;//地铁线数，地铁站数，每个地铁站最多被d个线经过，询问
int w[555555];//从 第i个地铁口->第i个站厅 的时间 


vector<pii>vec[6655555];

int dist[6665555],st[6655555];
void dij(int s)
{
	
	priority_queue<pii,vector<pii> ,greater<pii> >q;
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	dist[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		auto t=q.top();
		q.pop();
		int u=t.second;
		if(st[u])continue;
		st[u]=1;
		for(auto p:vec[u])
		{
			int v=p.first,w=p.second;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
	
}
int stand(int x)
{
	return x+5e5;
}
int station(int x)
{
	return x+2*5e5;
}
void solve(int s,int t)
{
//	dij(station(s));
//	cout<<dist[station(t)]<<"\n";
	dij(s);
	cout<<dist[t]+w[s]+w[t]<<"\n";
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int last=-1;
		for(int j=1;j<=k;j++)
		{
			//cin>>a[k[i]][j]>>t[k[i]][j];
			
			int v,w;
			cin>>v>>w;
			vec[station(v)].push_back({stand(i),0});
			if(last!=-1)
			{

				vec[station(last)].push_back({station(v),0});
				//vec[stand(i)].push_back({a[k[i]][j],0});
				
			}
			
			vec[v].push_back({stand(i),w});
			vec[stand(i)].push_back({v,w});
			//站和站台到达 
			last=v;
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		solve(x,y);
	}
	return 0;
}
