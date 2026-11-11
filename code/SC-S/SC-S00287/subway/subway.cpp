#include<iostream>
#include<vector>
#include<queue>
#define int long long
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

const int N=5e4+5;
const int M=5e2+5;

int c,n,m,d,q;
int tot;
int w[N];
int a[M][N],t[M][N];

namespace graph{
	
	vector<pii>e[N];
	int dis[N];
	bool vis[N];
	
	inline void add(int u,int v,int w){
//		cout<<"u:"<<u<<",v:"<<v<<",w:"<<w<<"\n";
		return e[u].push_back({v,w}),e[v].push_back({u,w}),void();
	}
	
	inline int dijk(int st,int ed){
		for(int i=1;i<=tot;++i)dis[i]=1e18,vis[i]=0;
		priority_queue<pii,vector<pii>,greater<pii>>q;
		dis[st]=0,q.push({0,st});
		while(!q.empty()){
			auto pi=q.top();q.pop();
			int d=pi.x,u=pi.y;
			if(d!=dis[u])continue ;
			if(vis[u])continue ;
			vis[u]=1;
			for(auto pi:e[u]){
				int w=pi.y,v=pi.x;
//				cout<<"----u:"<<u<<",v:"<<v<<",w:"<<w<<"\n";
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					q.push({dis[v],v});
				}
			}
		}
		return dis[ed];
	}
	
}using namespace graph;

signed main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
//	freopen("subway1.in","r",stdin),freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	tot=m*2;
	for(int i=1;i<=m;++i){
		cin>>w[i];
		add(i,i+m,w[i]);
	}
//	cout<<"\n\n";
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		int cnt=0;
		for(int j=1;j<=k;++j){
			int a,t;cin>>a>>t;
			add(m+a,++tot,t);
			++cnt;
			if(cnt>1){
				add(tot-1,tot,0);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<dijk(x,y)<<"\n";
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

32
17

*/

/*

大力建图哇
先把地铁站拆成地铁口和站厅，然后在站厅和站台间连边
地铁口编号 1~m，站厅编号 m+1~2m，然后每个站台继续新建点

*/
