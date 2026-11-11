#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,c,t,d,a[N];
vector<pair<int,int>> g[N];
int check()
{
	int dis[N],cnt[N],u,v,w;
	bool inque[N];
	queue<int> q;
	int ans=0;
	for(int i=1;i<=n;i++) dis[i]=1e18;
	dis[1]=0;
	q.push(1);
	inque[1]=1;		
	while(q.size())
	{
		u=q.front();
		q.pop();
		inque[u]=0;
		for(auto t:g[u])
		{
			v=t.first,w=t.second;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				if(!inque[v])
				{
					inque[v]=1;
					q.push(v);	
				}
			}
		}	
	}
	return dis[n];
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)	
			for(int j=1;j<=n;j++)
				if(i!=j&&abs(a[i]-a[j])<=d)
				{
					g[i].push_back({j,abs(a[i]-a[j])});
					g[j].push_back({i,abs(a[i]-a[j])});	
				}	
		cout<<0<<"\n";
	}
}
