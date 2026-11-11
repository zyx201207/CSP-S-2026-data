#include<bits/stdc++.h>
#define int long long
using namespace std;
const signed N=5e5+5,M=2e6+5;//就赌2e6了！ 
int c,n,m,d,que,w[N],lst,dis[M];
struct edge
{
	int v,w;
	edge(int a=0,int b=0):v(a),w(b){};
};
struct node
{
	int id,dist;
	node(int a=0,int b=0):id(a),dist(b){};
	friend bool operator <(const node &no1,const node &no2)
	{
		return no1.dist>no2.dist;
	};
};
vector<edge>to[M];
int dij(int st,int ed)
{
	priority_queue<node>q;
	memset(dis,0x3f,sizeof(dis));
	q.push({st,0});
	dis[st]=0;
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		int u=now.id,dist=now.dist;
		if(dist>dis[u])continue;
		for(int i=0,v,w;i<to[u].size();i++)
		{
			v=to[u][i].v;w=to[u][i].w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	return w[st]+dis[ed]+w[ed];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>que;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int j=1,op;j<=k*2;j++)
		{
			cin>>op;
			if(j&1)//a
			{
				if(j!=1)
				{
					to[lst+i*m].push_back({op+i*m,0});//线路
					to[op+i*m].push_back({lst+i*m,0});//线路
					lst=op;
				}
				else lst=op;
			}
			else//t
			{
				to[lst+i*m].push_back({lst,op});//i线路站台->j号站厅 
				to[lst].push_back({lst+i*m,op});//j号站厅->i线路站台
				//1~m表示站台,2m,3m表示不同线路 
			}
		}
	}
//	for(int i=0;i<=m*2;i++)
//	{
//		cout<<i<<"->";
//		for(int j=0;j<to[i].size();j++)
//			cout<<to[i][j].v<<" ";
//		cout<<"\n"<<i<<"w>";
//		for(int j=0;j<to[i].size();j++)
//			cout<<to[i][j].w<<" ";
//		cout<<"\n";
//	}
	for(int i=1;i<=que;i++)
	{
		int st,ed;
		cin>>st>>ed;
		cout<<dij(st,ed)<<"\n";
	}
	return 0;
}
/*
n是线路数
m是点数 
元素：地铁口、站厅、站台
w：地铁口<->站厅
t[i][j]从j号站厅<->第i条线路站台
*/
