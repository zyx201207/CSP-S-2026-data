#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll N=210,M=410;
ll _,n,m,dd,qq;
ll w[M],d[N*2+M];bool vis[N*2+M];
struct node{ll k,a[M],t[M],vis[M];}x[N];
vector<pii> e[N*2+M];
priority_queue<pii,vector<pii>,greater<pii> > q;
void dij(ll x){
	for(ll i=1;i<=2*m+n;i++) d[i]=1e18,vis[i]=0;
	q.push({0,x}),d[x]=0;
	while(!q.empty()){
		pii t=q.top();q.pop();
		ll u=t.second,dis=t.first;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:e[u]){
			ll v=i.first,w=i.second;
			if(d[v]>dis+w) d[v]=dis+w,q.push({d[v],v});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>_>>n>>m>>dd>>qq;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>x[i].k;
		for(ll j=1;j<=x[i].k;j++){
			cin>>x[i].a[j]>>x[i].t[j],x[i].vis[x[i].a[j]]=j;
			e[x[i].a[j]].push_back({i+2*m,w[x[i].a[j]]+x[i].t[j]}),e[i+2*m].push_back({x[i].a[j]+m,w[x[i].a[j]]+x[i].t[j]});
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			for(ll k=1;k<=m;k++){
				if(x[i].vis[k]!=0&&x[j].vis[k]!=0){
//					cout<<k<<" "<<i+2*m<<" "<<j+2*m<<" "<<x[i].t[x[i].vis[k]]+x[j].t[x[j].vis[k]]<<"\n";
					e[i+2*m].push_back({j+2*m,x[i].t[x[i].vis[k]]+x[j].t[x[j].vis[k]]});
					e[j+2*m].push_back({i+2*m,x[i].t[x[i].vis[k]]+x[j].t[x[j].vis[k]]});
				}
			}
		}
	}
//	for(int i=1;i<=2*m+n;i++){
//		for(auto v:e[i]){
//			cout<<i<<" "<<v.first<<" "<<v.second<<"\n";
//		}
//	}
	while(qq--){
		ll x,y;cin>>x>>y;
		dij(x);
		cout<<d[y+m]<<"\n";
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
