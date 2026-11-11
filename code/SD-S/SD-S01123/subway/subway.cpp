#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=505;
#define ll long long
struct P
{
	int v,w;
};
vector<P> g[N*4];
struct node 
{
	ll dis,pos;
	bool operator <(const node&x)const
	{
		return dis<x.dis;
	};
};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int  c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
//	cin>>c>>n>>m>>d>>q;
	ll sk=m*2;
	for(int i=1;i<=m;i++)
	{
		int w;
		scanf("%d",&w);
	//	cin>>w;
		g[i].push_back({i+m,w});
		g[i+m].push_back({i,w});
	}	
	int cnt=2*m;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
	//	cin>>k;
		sk+=k;
		for(int j=1;j<=k;j++)
		{
			int pos,t;
			scanf("%d%d",&pos,&t);
		//	cin>>pos>>t;	
			g[++cnt].push_back({pos+m,t});
			g[pos+m].push_back({cnt,t});
			if(j>=2)
			{
				g[cnt].push_back({cnt-1,0});
				g[cnt-1].push_back({cnt,0});
			}
		}
	}
//	for(int i=1;i<=cnt;i++)
//	{
//		cout<<i<<"pos:\n";
//		for(auto j:g[i])
//		{
//			cout<<j.v<<' ';
//		}
//		cout<<'\n';
//		for(auto j:g[i])
//		{
//			cout<<j.w<<' ';
//		}
//		cout<<'\n';
//	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		priority_queue<node> q;
		q.push({0,x});
		vector<long long> dis(cnt+1,1e18),vis(cnt+1,0);
		dis[x]=0;
		while(q.size())
		{
			int u=q.top().pos;
			q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto i:g[u])
			{
				ll v=i.v,w=i.w;
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
					q.push({dis[v],v});
				}
			}
		}
//		cout<<'\n';
//		for(int i=1;i<=cnt;i++)
//			cout<<dis[i]<<' ';
//		cout<<'\n';;
		cout<<dis[y]<<'\n';
	}
	return 0;
}

// rrrrrrrrrrrrrr       pppppppppppppp				+						+
// rr           rr		pp			 pp				+  						+
// rr            rr		pp			  pp			+						+
// rr           rr		pp  		 pp				+						+
// rrrrrrrrrrrrr		pppppppppppppp				+                       +
// rrrrrr				pp				   ++++++++++++++++++++   ++++++++++++++++++++
// rr    rr				pp	              			+						+
// rr      rr			pp							+						+
// rr        rr			pp							+						+
// rr          rr		pp							+						+
// rr            rr		pp							+						+
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2
fuck
想不出来优化了
fuck
我想上迷惑行为大赏 
rp++ 
我旁边这个人在写诗,一直在放屁 
我大概要afo了
i love c++
i love oi
i love you
i love 江淼
麻烦不要透露我的账号 
*/

