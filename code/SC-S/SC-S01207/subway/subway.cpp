#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pii;
typedef array<ll,3> arr3;
const ll N=5e5*4+10,INF=1e11+10;
ll c,n,m,d,q,k[N];
vector<vector<arr3>> g(N);//nd,w,type
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {//m个站点 
		ll w;
		cin>>w;//口->站厅 
		g[i].push_back({m+i,w,0});
		g[m+i].push_back({i,w,0});
	}
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		vector<ll> s;//subway 
		for(int j=1;j<=k[i];j++) {
			ll a,t;
			cin>>a>>t;
			s.push_back(a);
			g[m+a].push_back({2*m+a,t,i});//站厅->站台
			g[2*m+a].push_back({m+a,t,i}); 
		}
		for(int j=0;j<s.size()-1;j++) {//连接站台 
			ll u=2*m+s[j],v=2*m+s[j+1];
			g[u].push_back({v,0,i});
			g[v].push_back({u,0,i});
		}
	}
	
	while(q--) {
		ll x,y;
		cin>>x>>y;
		priority_queue<arr3,vector<arr3>,greater<arr3>> pq;//w,nd,type
		vector<bool> vis(N);
		vector<ll> dis(N,INF);
		dis[x]=0;
		pq.push({0,x,0});
		while(!pq.empty()) {
			arr3 tp=pq.top();
			ll nd=tp[1],st=tp[2];
//			cout<<nd<<" "<<st<<"\n";
			pq.pop();
			if(vis[nd])	continue;
			vis[nd]=true;
			if(nd==y){
				break;
			} 
			
			for(const auto& x:g[nd]) {
				ll node=x[0],wh=x[1],ste=x[2];
				if(ste!=st&&(ste!=0&&st!=0)) {//出口到站厅不需要上楼 
					ll ct=0;
					for(const auto& y:g[node]) {
						if(y[0]==nd&&y[2]==st) {
							ct+=y[1];
							break;
						}
					}
					for(const auto& y:g[nd]) {
						if(y[0]==node&&y[2]==ste) {
							ct+=y[1];
							
							break;
						}
					}
					if(!vis[node]&&dis[nd]+wh+ct<dis[node]) {
						dis[node]=dis[nd]+wh+ct;
						pq.push({dis[nd]+wh+ct,node,ste});
					}
				} else {
					if(!vis[node]&&dis[nd]+wh<dis[node]) {
						dis[node]=dis[nd]+wh;
						pq.push({dis[nd]+wh,node,ste});
					}
				}
				
			}
		}
		cout<<dis[y]<<"\n";
		
	}
	return 0;
}