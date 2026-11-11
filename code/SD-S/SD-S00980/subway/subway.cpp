#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N=1e6+5;
const ll INF=1e18;
ll read(){
	ll k=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))k=k*10+c-'0',c=getchar();
	return f*k;
}
void write(ll x){
	if(x==0){putchar('0');return;}
	if(x<0){putchar('-');x=-x;}
	ll len=0;
	char c[100];
	while(x){c[len++]=x%10+'0';x/=10;}
	while(len--)putchar(c[len]);
}
ll a[N],w[N],t[N];
ll dis[1005];
ll ans;
bool vis[N];
ll c,m,n,d,q;
vector<pair<ll,ll> >p[N];
void dijkstra(int s,int e){
	for(int i=1;i<=m+n;i++)dis[i]=INF,vis[i]=false;
	dis[s]=0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;
	q.emplace(0,s);
	while(!q.empty()){
		ll u=q.top().second,w=q.top().first;
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(auto i:p[u]){
			ll v=i.first;
			ll ww=i.second;
			if(dis[v]>dis[u]+ww){
				dis[v]=dis[u]+ww;
				if(dis[v]==e)return;
				q.emplace(dis[v],v);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(ll i=1;i<=m;i++){
		w[i]=read();
	}
	for(ll j=1;j<=n;j++){
		ll k=read();
		for(ll i=1;i<=k;i++){
			a[i]=read(),t[i]=read();
			p[a[i]].emplace_back(m+j,t[i]);
			p[m+j].emplace_back(a[i],t[i]);
		}
	}
	for(ll i=1;i<=q;i++){
		ll u=read(),v=read();
		dijkstra(u,v);
		write(dis[v]+w[u]+w[v]);
		putchar(endl);
	}
	return 0;
}
