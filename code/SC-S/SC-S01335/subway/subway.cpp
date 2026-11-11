#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,cnt,vis[1001005],ptime,dis[1001005],ddd[3005][3005];
vector<pair<int,int> > v[1001005];
priority_queue<pair<int,int> >p;
vector<int> vit;
int dist(int x,int y)
{
	for(auto i:vit) dis[i]=1e18;
	vit.clear();
	while(p.size()) p.pop();
	ptime++;
	dis[x]=0;
	p.push({0,x});
	vit.push_back(x);
	while(p.size())
	{
		int o=p.top().second;
		p.pop();
		if(o==y) break;
		vis[o]=ptime;
		for(auto i:v[o])
		{
			if(vis[i.first]==ptime) continue;
			if(dis[i.first]>dis[o]+i.second)
			{
				dis[i.first]=dis[o]+i.second;
				vit.push_back(i.first);
				p.push({-dis[i.first],i.first});
			}
		}
	}
	int ans=dis[y];
	return ans;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		v[i].push_back({i+m,x});
		v[i+m].push_back({i,x});
	}
	cnt=2*m;
	for(int i=1;i<=n;i++)
	{
		int len;
		cin>>len;
		cnt++;
		for(int j=1;j<=len;j++)
		{
			int x,p;
			cin>>x>>p;
			v[cnt].push_back({x+m,p});
			v[x+m].push_back({cnt,p});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	if(cnt<=3000)
	{
		for(int i=1;i<=cnt;i++)
		{
			dist(i,-1);
			for(int j=1;j<=cnt;j++)
			{
				ddd[i][j]=dis[j];
			}
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			cout<<ddd[x][y]<<endl;
		}
	}
	else
	{
		while(q--)
		{
			int T,S;
			cin>>T>>S;
			cout<<dist(T,S)<<endl;
		}
	}
	return 0;
}