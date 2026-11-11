#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,w[N];
vector<pair<int,int>> v[N];
void add(int x,int y,int z)
{
	v[x].push_back({y,z});
	v[y].push_back({x,z});
}
int vis[N],dis[N];
void spfa(int s,int n)
{
	for(int i=1;i<=n;i++) dis[i]=1e18,vis[i]=0;
	queue<int> q;
	dis[s]=0;
	vis[s]=1;
	q.push(s);
	while(q.size())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(auto t:v[x])
		{
			int y=t.first,z=t.second;
			if(dis[y]>dis[x]+z)
			{
				dis[y]=dis[x]+z;
				if(!vis[y])
				{
					vis[y]=1;
					q.push(y);
				}
			}
		}
	}
}
void calc(int cur)
{
	for(int s=1;s<=cur;s++) spfa(s,cur);
}
struct node
{
	int x,y,id;
};
node a[N];
int ans[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#endif
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	int tot=m;
	for(int i=1;i<=n;i++)
	{
		tot++;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			add(tot,a,t);
		}
	}
	for(int i=1;i<=q;i++) cin>>a[i].x>>a[i].y,a[i].id=i;
	sort(a+1,a+q+1,[](node x,node y){return x.x<y.x;});
	for(int i=1;i<=q;i++)
	{
		int x=a[i].x,y=a[i].y;
		if(x!=a[i-1].x) spfa(x,tot);
		ans[a[i].id]=dis[y]+w[x]+w[y];
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}

