#include<bits/stdc++.h>					//30 pts
#define N 1000005
#define SN 105
#define INF 1e18
#define pb push_back
typedef long long ll;
using namespace std;
struct Edge{
	ll u,v;
}e[N];
ll C,T,n,k,ans16,dis[SN][SN],vst[SN],slt[SN];
vector<ll> g[N];
void DFS2(ll u){
	vst[u]=1;
	for(ll v:g[u]) if(!vst[v]&&slt[v]) DFS2(v);
}
bool Check(){
//	for(ll i=1;i<=n;i++) if(slt[i]) cout<<i<<" ";
//	cout<<"?\n";
	ll cnt=0;
	fill(vst,vst+SN,0);
	for(ll i=1;i<=n;i++) if(slt[i]&&!vst[i]){
		cnt++; DFS2(i);
	}
	return cnt==2;
}
void BFSSS(ll s){
	queue<ll> q;
	q.push(s);
	for(ll j=1;j<=n;j++) dis[s][j]=INF;
	dis[s][s]=0;
	while(!q.empty()){
		ll u=q.front(); q.pop();
		for(ll v:g[u]) if(dis[s][v]>dis[s][u]+1)
			dis[s][v]=dis[s][u]+1,q.push(v);
	}
}
void Calc16(){
//	for(ll i=1;i<=n;i++) if(slt[i]) cout<<i<<" ";
//	cout<<"¡Ì\n";
	for(ll i=1;i<=n;i++) if(slt[i]){
		BFSSS(i);
	}
	ll mx=-INF;
	for(ll i=1;i<=n;i++) if(!slt[i]){
		ll t=INF;
		for(ll j=1;j<=n;j++) if(slt[j]) t=min(t,dis[j][i]);
		mx=max(mx,t);
	}
	ans16=min(ans16,mx);
}
void DFS(ll x,ll cx){
	if((x<n&&n-x+1<k-cx)||cx>k||(x>n&&cx!=k)) return;
	if(cx==k){
		if(Check()) Calc16();
		return;
	}
	slt[x]=1;
	DFS(x+1,cx+1);
	slt[x]=0;
	DFS(x+1,cx);
}
void Solve16(){						//30 pts
	fill(slt,slt+SN,0);
	ans16=INF;
	for(ll i=1;i<=SN;i++) vector<ll>().swap(g[i]);
	for(ll i=1;i<n;i++){
		ll u=e[i].u,v=e[i].v;
		g[u].pb(v),g[v].pb(u);
	}
	DFS(1,0);
	cout<<ans16<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(ll i=1;i<n;i++) cin>>e[i].u>>e[i].v;
		if(C<=6) Solve16();
	}
	return 0;
} 
