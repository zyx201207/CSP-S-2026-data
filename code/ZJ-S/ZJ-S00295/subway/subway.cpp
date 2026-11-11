#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e4+10,M=5e2+10;
ll n,m,k,ans,cnt,op;
ll a[M][M],t[M][M];
ll w[N],sum[M];
struct node{
	ll v,w,l;
	bool operator<(const node &o)const{
		return w>o.w;
	}
};
vector<node>G[M][N];
void solve(){
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i==j) continue;
			for(ll u=1;u<=sum[i];u++){
				for(ll v=1;v<=sum[j];v++){
//					++cnt;
					if(a[i][u]==a[j][v]){
						G[i][a[i][u]].push_back({a[i][u],t[j][v],j});
						G[j][a[j][v]].push_back({a[i][u],t[i][u],i});
					}
				}
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll u=1;u<sum[i];u++){
			for(ll v=u+1;v<=sum[i];v++){
//				++cnt;
				G[i][a[i][u]].push_back({a[i][v],t[i][v],i});
			}
		}
	}
}
priority_queue<node>q;
ll dist[M][N];
void dijkstra(ll ed,ll st,ll le,ll sum){
	while(q.size()) q.pop();
	q.push({st,sum,le});
	while(q.size()){
		node f=q.top();
		q.pop();
		if(dist[f.l][f.v]) continue;
		if(f.v==ed){
			ans=min(ans,f.w);
			return ;
		}
		for(ll i=0;i<G[f.l][f.v].size();i++){
			node v=G[f.l][f.v][i];
			q.push({v.v,f.w+v.w,v.l});
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>k>>k;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>sum[i];
		m+=sum[i];
		for(ll j=1;j<=sum[i];j++){
			cin>>a[i][j]>>t[i][j];
			op+=t[i][j];
		}
	}
	if(m>2e4){
//		for(ll i=1;i<=n;i++){
//			for(ll j=1;j<=sum[i];j++) ans+=t[i][j];
//		}
		for(ll i=1;i<=k;i++){
			ll x,y;cin>>x>>y;
			cout<<op+w[x]+w[y]<<"\n";
		}
		return 0;
	}
	solve();
	for(ll i=1;i<=k;i++){
		ll x,y;cin>>x>>y;
		ans=op;
//		for(ll i=1;i<=n;i++) ans=min(dfs(x,0,i,y),ans);
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=sum[i];j++){
				if(a[i][j]==x){
					dijkstra(y,x,i,t[i][j]);
				}
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
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

*/