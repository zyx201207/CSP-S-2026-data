#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll=long long;
using pli=pair<ll,int>;
const int N=1e6+10;
int c,n,m,deg,Q,w[N],x[N],y[N];
ll ans[N];
struct E{
	int v,w;
};
vector<E> g[N+500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>deg>>Q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a>>t;
			g[a].push_back({i+m,t});
			g[i+m].push_back({a,t}); 
		}
	}
	for(int i=1;i<=Q;++i) cin>>x[i]>>y[i],ans[i]=INF;
//    auto start = chrono::steady_clock::now();	
	for(int s=1;s<=n;++s){
		priority_queue<pli,vector<pli>,greater<pli>> q;
		vector<ll> dis(n+m+1,INF);
		q.push({0,s+m});
		dis[s+m]=0;
		while(!q.empty()){
			int u=q.top().second;
			ll d=q.top().first;
			q.pop(); 
			if(dis[u]!=d) continue;
			for(E e : g[u]){
				int v=e.v,w=e.w;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					q.push({dis[v],v});
				}
			}
		}
		for(int i=1;i<=Q;++i){
			if(x[i]==y[i]){
				ans[i]=0;
				continue; 
			}
			ans[i]=min(ans[i],dis[x[i]]+dis[y[i]]+w[x[i]]+w[y[i]]);
		}
//		double t = chrono::duration<double>(chrono::steady_clock::now() - start).count();
//        if (t > 1.8) break;
	}
	for(int i=1;i<=Q;++i) cout<<ans[i]<<"\n";
	return 0;
}
