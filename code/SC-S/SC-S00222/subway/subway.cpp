#include<bits/stdc++.h>
#define LL long long
#define IC ios::sync_with_stdio(false);cin.tie(0);
#define PLL pair<LL,LL>
using namespace std;
const LL M=5e5+5,N=505,inf=0x3f3f3f3f3f3f3f3f;
LL c,n,m,d,q,a,t,x,y;
LL w[M],k[N],dis[M+N];
vector<PLL>vr[M+N];
priority_queue<PLL,vector<PLL>,greater<PLL> >pq;
void add(LL u,LL v,LL w)
{
	vr[u].push_back({v,w});
	vr[v].push_back({u,w});
	return;
}
void init()
{
	for(LL i=1;i<=m+n;i++)
	{
		dis[i]=inf;
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	IC
	cin>>c>>n>>m>>d>>q;
	for(LL i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(LL i=1;i<=n;i++)
	{
		cin>>k[i];
		for(LL j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			add(m+i,a,t);
			add(a,m+i,t);
		}
	}
	while(q--)
	{
		cin>>x>>y;
		init();
		dis[x]=0;
		pq.push({0,x});
		while(pq.size())
		{
			LL u=pq.top().second;
			pq.pop();
			for(auto it:vr[u])
			{
				LL v=it.first,w=it.second;
				if(dis[v]>dis[u]+w) 
				{
					dis[v]=dis[u]+w;
					pq.push({dis[v],v});
				}
			}
		}
		cout<<w[x]+dis[y]+w[y]<<"\n";
	}
	return 0;	
}