#include<bits/stdc++.h>					//0 pts
#define N 505
#define INF 1e18
typedef long long ll;
using namespace std;
struct Edge{
	ll ln,v,w;
};
ll C,n,m,d,Q,dis[N*N],k[N],ww[N],a[N][N],t[N][N];
vector<Edge> e[N];
void SPFA(ll s){
	queue<pair<ll,ll>> q;
	q.push(make_pair(s,n+2));
	fill(dis,dis+N*5,INF);
	dis[s]=0;
	while(!q.empty()){
		ll u=q.front().first,lln=q.front().second; q.pop();
		for(Edge ee:e[u]){
			ll ln=ee.ln,v=ee.v,w=ee.w;
			if(lln-n>0&&lln-n<=n) w=t[ln][v];
			if(ln-n>0&&ln-n<=n) w=t[lln][v];
			if((ln>n||lln>n||ln==lln)&&dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(make_pair(v,ln));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>Q;
	for(ll i=1;i<=m;i++) cin>>ww[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(ll i=1;i<=n;i++) for(ll j=2;j<=k[i];j++)
		e[a[i][j-1]].push_back({i,a[i][j],0}),
		e[a[i][j]].push_back({i,a[i][j-1],0});
	for(ll i=1;i<=n;i++) for(ll j=1;j<=k[i];j++)
		e[a[i][j]].push_back({n+1,n+a[i][j],t[i][j]}),
		e[n+a[i][j]].push_back({n+1,a[i][j],t[i][j]});
	for(ll i=1;i<=n;i++)
		e[n*2+i].push_back({+2,m+n,ww[i]}),
		e[n+i].push_back({n+2,n*2+i,ww[i]});
	while(Q--){
		ll xr,yr;
		cin>>xr>>yr;
		SPFA(n*2+xr);
		cout<<dis[n*2+yr]<<"\n";
	}
	return 0;
}
