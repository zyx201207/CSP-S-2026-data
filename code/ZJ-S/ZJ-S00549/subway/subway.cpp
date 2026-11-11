#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
struct node{
	int v,w;
	bool operator < (const node &x) const{
		return w>x.w;
	}
};
int c,n,m,d,q,w[N],k,dis[505][505];
bool vis[505][505];
vector<node>taixian[N];
vector<node>g[N];
void dij(int st)
{
	priority_queue<node>q;
	q.push({st,0});
	dis[st][st]=0;
	while(!q.empty())
	{
		node u=q.top();
		q.pop();
		if(vis[st][u.v]) continue;
		vis[st][u.v]=1;
		for(auto v:g[u.v])
		{
			if(vis[st][v.v]||dis[st][v.v]<=dis[st][u.v]+v.w) continue;
			dis[st][v.v]=dis[st][u.v]+v.w;
			q.push({v.v,dis[st][v.v]});
		}
	}
}
signed main()
{
//	system("fc subway.out subway7.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1,v,w;j<=k;j++)
			cin>>v>>w,taixian[v].push_back({i,w});
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<taixian[i].size();j++)
			for(int k=j+1,v1,v2,w1,w2;k<taixian[i].size();k++)
			{
				v1=taixian[i][j].v,v2=taixian[i][k].v;
				w1=taixian[i][j].w,w2=taixian[i][k].w;
				g[v1].push_back({v2,w1+w2});
				g[v2].push_back({v1,w1+w2});
//				cout<<v1<<' '<<v2<<' '<<w1<<' '<<w2<<'\n'; 
			}
	}
	for(int i=1;i<=n;i++)
	{
		dij(i);
//		for(int j=1;j<=n;j++)
//			cout<<dis[i][j]<<' ';
//		cout<<'\n';
	}
	int u,v,minn;
	while(q--)
	{
		minn=1e18;
		cin>>u>>v;
		for(auto i:taixian[u])
			for(auto j:taixian[v])
			{
				minn=min(minn,dis[i.v][j.v]+i.w+j.w);
//				cout<<i.v<<' '<<j.v<<' '<<dis[i.v][j.v]<<' '<<i.w<<' '<<j.w<<'\n';
			}
		cout<<minn+w[u]+w[v]<<'\n';
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
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
