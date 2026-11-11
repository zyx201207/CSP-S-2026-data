#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
const int N=5e5+10,M=5e2+10,MOD=1e9+7;
const ll inf=1e18;
ll c,n,m,d,q,w[N],k[M];
vector<ll> A[M],T[M];
//1~11  2*n*n*log(n+m)
struct Dij1{
	ll x,d;
	bool operator<(const Dij1 &_)const{return _.d<d;}
};
vector<pa> G1[N+M],Q[N];
ll dis1[N+M],ans[N];
void dij1(ll st){
	for(int i=1;i<=n+m;i++) dis1[i]=inf;
	dis1[st]=0;
	priority_queue<Dij1> pq;
	pq.push({st,0});
	while(!pq.empty()){
		Dij1 tmp=pq.top();
		pq.pop();
		ll x=tmp.x,t=tmp.d;
		if(dis1[x]!=t) continue;
		for(auto to:G1[x]){
			ll v=to.first,w=to.second;
			if(dis1[v]>t+w){
				dis1[v]=t+w;
				pq.push({v,t+w});
			}
		}
	}
	for(auto q:Q[st]){
		ll ed=q.first,idx=q.second;
		ans[idx]=w[st]+w[ed]+dis1[ed];
	}
}
void main1(){
	for(int i=1;i<=m;i++){
		for(int j=0;j<k[i];j++){
			ll a=A[i][j],t=T[i][j];
			G1[a].push_back({n+i,t});
			G1[n+i].push_back({a,t});
		}
	}
	for(int i=1;i<=q;i++){
		ll u,v; cin>>u>>v;
		Q[u].push_back({v,i});
	}
	for(int i=1;i<=n;i++) dij1(i);
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}
//
void main2(){
	
}
void solve(){
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll a,t; cin>>a>>t;
			A[i].push_back(a);
			T[i].push_back(t);
		}
	}
	if(c<=11) main1();
	else if(c<=19) main2();
	else main1();
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	IOS;
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
