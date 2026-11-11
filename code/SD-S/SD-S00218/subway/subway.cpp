#include<bits/stdc++.h>
#define rep(l,r,i) for(int i=l;i<=r;i++)
#define rrep(l,r,i) for(int i=l;i>=r;i--)
#define rmp(v,mp) for(auto v:mp)
using namespace std;
void fre(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}namespace ZXY{
	typedef long long ll;
	const int N=5e5+7;
	struct Edge{
		int v;ll w;
		bool operator<(const Edge&a)const{
			return w>a.w;
		}
	};vector<Edge>g[N*2];
	int c,n,m,d,q;
	ll dis[507][N+507];//2.5e8*8 1e9/1024/1024
	bool vis[N*2];int w[N];
	void dijkstra(int x){
		priority_queue<Edge>q;
		q.push({x,0});
		fill(dis[x-m]+1,dis[x-m]+n+m+1,1e18);
		fill(vis+1,vis+n+m+1,0);
		dis[x-m][x]=0;int id=x-m;
		while(!q.empty()){
			auto u=q.top();q.pop();
			if(vis[u.v])continue;
			vis[u.v]=1;
			rmp(x,g[u.v]){
				int v=x.v,w=x.w;
				if(dis[id][v]>dis[id][u.v]+w)
					dis[id][v]=dis[id][u.v]+w,
					q.push({v,dis[id][v]});
			}
		}
	}void solve(){
		ios::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		cin>>c>>n>>m>>d>>q;
		rep(1,m,i)cin>>w[i];
		int tot=m;
		rep(1,n,i){
			int k;++tot;
			cin>>k;
			rep(1,k,i){
				int a,t;cin>>a>>t;
				g[a].push_back({tot,t});
				g[tot].push_back({a,t});
			}
		}rep(1,n,i)dijkstra(i+m);
		while(q--){
			ll ans=4e18;int x,y;
			cin>>x>>y;
			rep(1,n,i)ans=min(ans,dis[i][x]+dis[i][y]);
			cout<<ans+w[x]+w[y]<<'\n';
		}
	}
}
int main(){fre();ZXY::solve();}
///kel 
