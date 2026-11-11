#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int N=505;
int c,n,m,fw,q,pre;
vector<pair<long long,int>> g[N*N];
long long d[N*N];
void dij(int s)
{
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
	q.push({0,s});
	bool vis[10005]={};
	for(int i=0;i<=m*3+n;i++) d[i]=1e18;
	d[s]=0;
	while(!q.empty())
	{
		auto i=q.top();
		q.pop();
		if(vis[i.s]) continue;
		vis[i.s]=1;
		for(auto j:g[i.s])
		{
			if(d[j.s]>i.f+j.f)
			{
				d[j.s]=i.f+j.f;
				q.push({d[j.s],j.s});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>fw>>q;
	for(int i=1;i<=m;i++)
	{
		long long x;
		cin>>x;
		g[(i-1)*2].push_back({x,(i-1)*2+1});
		g[(i-1)*2+1].push_back({x,(i-1)*2});
	}
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		while(t--)
		{
			int a;
			long long w;
			cin>>a>>w;
			g[(a-1)*2+1].push_back({w,i-1+m*2});
			g[i-1+m*2].push_back({w,(a-1)*2+1});
		}
	}
	while(q--)
	{
		int s,e;
		cin>>s>>e;
		if(s!=pre) dij((s-1)*2);
		cout<<d[(e-1)*2]<<'\n';
		pre=s;
	}
	return 0;
}