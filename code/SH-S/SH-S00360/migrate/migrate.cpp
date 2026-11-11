#include<bits/stdc++.h>						//48 pts
#define N 2000005
#define SN 5005
#define INF 1e18
#define pb push_back
typedef long long ll;
using namespace std;
ll n,d,C,T,x[N],dis[SN],cnt[SN],vst[SN];
vector<ll> e[SN];
bool A(){
	ll td=x[2]-x[1];
	for(ll i=3;i<=n;i++) if(x[i]-x[i-1]!=td) return false;
	return true;
}
void SolveA(){		//8 pts
	ll td=x[2]-x[1];
	if(2*td<=d){
		ll j=d/td; j*=2;
		cout<<max(n-j+1,0ll)<<"\n";
	}
	else cout<<"0\n";
}
void Dfs(ll fa,ll u,ll c){			//40 pts
//	cout<<"Dfs("<<fa<<","<<u<<","<<c<<")\n";
	if(c>dis[u]) return;
	if(c==dis[u]) cnt[u]++;
	for(ll v:e[u]) if(v!=fa) Dfs(u,v,c+1);
}
ll Bfs(ll s){
	queue<ll> q;
	q.push(s);
	fill(vst,vst+SN,0);
	fill(cnt,cnt+SN,0);
	fill(dis,dis+SN,INF);
	dis[s]=0;
	while(!q.empty()){
		ll u=q.front(); q.pop();
		for(ll v:e[u]) if(dis[v]>dis[u]+1) dis[v]=dis[u]+1,q.push(v);
	}
	ll tans=0;
	Dfs(-1,s,0);
	for(ll i=1;i<=n;i++) if(cnt[i]==2) tans++;
	return tans;
}
void SolveSmall(){
	for(ll i=1;i<=n;i++) e[i].clear();
	ll ans=0;
	for(ll i=1;i<=n;i++) for(ll j=i+1;j<=n;j++) if(x[j]-x[i]<=d) e[i].pb(j),e[j].pb(i);
	for(ll i=1;i<=n;i++) ans+=Bfs(i);
	cout<<ans/2<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>x[i];
		if(C==11||C==12) SolveA();
		else if(C<=10) SolveSmall();
	}
	return 0;
}
