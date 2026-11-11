#include<bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const ll N=1010;
ll n,k,c[N],h[N],tot,f[N],ans,dis[N],nd[N];
pair<ll,ll> e[N];
struct Node{
	ll to,nxt;
}edges[N<<1];
void ADD(ll u,ll v){
	edges[++tot].to=v;
	edges[tot].nxt=h[u];
	h[u]=tot;
}
ll find(ll u){
	if(f[u]==u)return u;
	return f[u]=find(f[u]);
}
void dfs1(ll u,ll fa){
	for(ll i=h[u];i;i=edges[i].nxt){
		ll v=edges[i].to;
		if(v==fa)continue;
		nd[v]=nd[u]+1;
		dfs1(v,u);
	}
}
void calc(){
	for(ll i=1;i<=n;i++)f[i]=i;
	for(ll i=1;i<n;i++){
		ll u=e[i].x,v=e[i].y;
		if(c[u] && c[v]){
			ll fu=find(u),fv=find(v);
			f[fu]=fv;
		}
	}
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		if(c[i] && f[i]==i)cnt++;
	}
	if(cnt>2)return ;
	for(ll i=1;i<=n;i++){
		if(c[i]){
			for(ll j=1;j<=n;j++)nd[j]=-1;
			nd[i]=0;
			dfs1(i,0);
			for(ll j=1;j<=n;j++)dis[j]=min(dis[j],nd[j]);
		}
	}
	ll sum=0;
	for(ll i=1;i<=n;i++)sum=max(sum,dis[i]);
	ans=min(ans,sum);
}
void dfs(ll u,ll nd){
	if(nd>n-u+1)return ;
	if(u==n+1){
		calc();
		return ;
	}
	dfs(u+1,nd);
	if(nd){
		c[u]=1;
		dfs(u+1,nd-1);
	}
}
void Main(){
	cin>>n>>k;
	for(ll i=1;i<=n;i++)h[i]=0;
	tot=0;
	for(ll i=1;i<n;i++){
		cin>>e[i].x>>e[i].y;
		ADD(e[i].x,e[i].y);
		ADD(e[i].y,e[i].x);
	}
	ans=inf;
	dfs(1,k);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--)Main();
	return 0;
}