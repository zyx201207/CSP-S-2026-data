#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,t;
ll cw[500005];
vector<pair<ll,ll>>to[500005][3];
ll k,v,w;
ll x,y;
priority_queue<pair<ll,pair<ll,bool>>>q;//size,place,0->z,1->x
ll dis[500005][3];
ll dij()
{
	q.push({0,{x,0}});
	for(int i=1;i<=m;i++)
	{
		dis[i][0]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][1]=-1;
	}
	while(!q.empty())
	{
		pair<ll,pair<ll,bool>>now;
		now=q.top();
//		cout<<now.first<<" "<<now.second.first<<" "<<now.second.second<<endl;
		q.pop();
		if(dis[now.second.first][now.second.second]!=-1)
		{
			continue;
		}
		dis[now.second.first][now.second.second]=-now.first;
		if(now.second.first==y&&now.second.second==0)
		{
			break;
		}
		for(pair<ll,ll>pl:to[now.second.first][now.second.second])
		{
//			cout<<pl.first<<" "<<pl.second<<endl;
			q.push({now.first-pl.second,{pl.first,!now.second.second}});
		}
	}
	while(!q.empty())
	{
		q.pop();
	}
	return dis[y][0];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>t;
	for(int i=1;i<=m;i++)
	{
		cin>>cw[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>v>>w;
			to[i][1].push_back({v,w});
			to[v][0].push_back({i,w});
		}
	}
	while(t--)
	{
		cin>>x>>y;
		cout<<cw[x]+cw[y]+dij()<<endl;
//		for(int i=1;i<=n;i++)
//		{
//			cout<<dis[i][1]<<" ";
//		}
//		cout<<endl;
//		for(int i=1;i<=m;i++)
//		{
//			cout<<dis[i][0]<<" ";
//		}
//		cout<<endl;
	}
	return 0;
}
