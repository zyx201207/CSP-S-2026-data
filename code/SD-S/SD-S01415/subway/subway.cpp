#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;
ll w[N],d[N][2];
vector<pii>dot[N],edge[N];
void dijkstra(int st,int ed)
{
	memset(d,0x3f,sizeof d);
	d[st][0]=w[st];
	priority_queue<piii,vector<piii>,greater<piii> >q;
	q.push({w[st],{st,0}});
	while(!q.empty())
	{
		piii t=q.top();
		q.pop();
		ll dis=t.first;
		int u=t.second.first,op=t.second.second;
		if(d[u][op]!=dis)continue;
		if(!op)//µãµ½Ïß
		{
			for(auto i:dot[u])
			{
				int j=i.first;
				ll w=i.second;
				if(d[j][1]>d[u][0]+w)
				{
					d[j][1]=d[u][0]+w;
					q.push({d[j][1],{j,1}});
				}
			}
		}
		else
		{
			for(auto i:edge[u])
			{
				int j=i.first;
				ll w=i.second;
				if(d[j][0]>d[u][1]+w)
				{
					d[j][0]=d[u][1]+w;
					q.push({d[j][0],{j,0}});
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int id,n,m,dd,q;
	cin>>id>>m>>n>>dd>>q;
	for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=m;i++)
	{
		int len;
		scanf("%d",&len);
		for(int j=1;j<=len;j++)
		{
			ll x,t;
			scanf("%lld%lld",&x,&t);
			dot[x].push_back({i,t});
			edge[i].push_back({x,t});
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		dijkstra(x,y);
		printf("%lld\n",d[y][0]+w[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
