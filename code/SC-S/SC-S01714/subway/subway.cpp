#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500001];
int t8[202][404];
int dis[202][404];
int vis[202][404];
vector<int> line8[404];
vector<int> gra8[202][404];
struct node{
	int v,layer,dist;
	bool operator <(const node p)const{
		if(dist!=p.dist) return dist>p.dist;
		else return v<p.v;
	}
};
priority_queue<node> dij;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	if(1<=c && c<=8)
	{
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			int lst=-1;
			for(int j=1;j<=k;j++)
			{
				int a1,t1;
				cin>>a1>>t1;
				t8[i][a1]=t1;
				line8[a1].push_back(i);
				if(lst!=-1)
				{
					gra8[i][a1].push_back(lst);
					gra8[i][lst].push_back(a1);
				}
				lst=a1;
			}
		}	
		for(int i=1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
			int tot=w[x]+w[y];
			for(int j=0;j<=403;j++) for(int k=0;k<=201;k++) dis[k][j]=99999999999;
			for(int j=0;j<=403;j++) for(int k=0;k<=201;k++) vis[k][j]=0;
			dis[0][x]=0;
			dij.push({x,0,0});
			while(!dij.empty())
			{
				int v=dij.top().v;
				int layer=dij.top().layer;
				int dist=dij.top().dist;
				dij.pop();
				if(vis[layer][v]==1) continue;
				if(dis[0][v]>dis[layer][v]+t8[layer][v])
				{
					dis[0][v]=dis[layer][v]+t8[layer][v];
					if(!vis[layer][v]) dij.push({v,0,dis[0][v]});
				}
				for(int j=0;j<(int)line8[v].size();j++)
				{
					int ppp=line8[v][j];
					if(ppp==layer)
					{
						for(int k=0;k<(int)gra8[ppp][v].size();k++)
						{
							int to=gra8[ppp][v][k];
							if(dis[ppp][to]>dis[ppp][v])
							{
								dis[ppp][to]=dis[ppp][v];
								if(!vis[ppp][to]) dij.push({to,ppp,dis[ppp][to]});
							}
						}
					}
					if(dis[ppp][v]>dis[layer][v]+t8[layer][v]+t8[ppp][v])
					{
						dis[ppp][v]=dis[layer][v]+t8[layer][v]+t8[ppp][v];
						if(!vis[ppp][v]) dij.push({v,ppp,dis[ppp][v]});
					}
				}
				vis[layer][v]=1;
			}
			cout<<tot+dis[0][y]<<endl;
		}
		
	}
	else if(20<=c && c<=21)
	{
		vector<int> a(500005);
		vector<int> t(500005);
		vector<int> a999(500005);
		vector<int> t999(500005);
		int minn=9999999999999;
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				int a1,t1;
				cin>>a1>>t1;
				if(i==1) a[a1]=1,t[a1]=t1;
				else
				{
					a999[a1]=1,t999[a1]=t1;
					if(a[a1]==1) minn=min(minn,t1+t[a1]);
				} 
			}
		}	
		for(int i=1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
			int tot=w[x]+w[y];
			if((a[x]==1 && a[y]==1 && a999[x]==0 && a999[y]==0)) cout<<tot+t[x]+t[y]<<endl;
			else if((a[x]==0 && a[y]==0 && a999[x]==1 && a999[y]==1)) cout<<tot+t999[x]+t999[y]<<endl;
			else if((a[x]==1 && a[y]==1 && a999[x]==1 && a999[y]==1)) cout<<tot+min(t[x]+t[y],t999[x]+t999[y])<<endl;
			else if((a[x]==1 && a[y]==1 && a999[x]==1 && a999[y]==0)) cout<<tot+min(t[x]+t[y],t999[x]+minn+t[y])<<endl;
			else if((a[x]==1 && a[y]==0 && a999[x]==1 && a999[y]==1)) cout<<tot+min(t999[x]+t999[y],t[x]+minn+t999[y])<<endl;
			else if((a[x]==1 && a[y]==1 && a999[x]==0 && a999[y]==1)) cout<<tot+min(t[x]+t[y],t[x]+minn+t999[y])<<endl;
			else if((a[x]==0 && a[y]==1 && a999[x]==1 && a999[y]==1)) cout<<tot+min(t999[x]+t999[y],t999[x]+minn+t[y])<<endl;
			else if((a[x]==1 && a[y]==0 && a999[x]==0 && a999[y]==1)) cout<<tot+t[x]+minn+t999[y]<<endl;
			else if((a[x]==0 && a[y]==1 && a999[x]==1 && a999[y]==0)) cout<<tot+t999[x]+minn+t[y]<<endl;
		}
		
	}
	
	return 0;
}