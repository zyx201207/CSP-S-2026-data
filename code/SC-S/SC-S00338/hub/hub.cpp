#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> ed[20];
ll dis[20];
ll n,k;
ll info[20][2];
void input(){
	cin>>n>>k;
	for(ll i=1;i<n;i++){
		ll u,v;
		cin>>u>>v;
		ed[u].push_back(v);
		ed[v].push_back(u);
		info[i][0]=u;
		info[i][1]=v; 
	}	
}
ll fa[20];
ll getfa(ll x){
	if(fa[x]==x) return fa[x];
	fa[x]=getfa(fa[x]);
	return fa[x];
}
bool vis[20];
ll chk(ll sel){
	if(__builtin_popcount(sel)!=k) return 10000000000;
	queue<ll> q;
	for(ll i=1;i<=n;i++){
		fa[i]=i;
		vis[i]=0;
	}
	for(ll i=1;i<n;i++){
		if((sel&(1ll<<(info[i][0]-1)))&&(sel&(1ll<<(info[i][1]-1)))){
			if(getfa(info[i][0])!=getfa(info[i][1])){
				fa[getfa(info[i][0])]=getfa(info[i][1]);
			}
		}
	}
	ll tot=0;
	for(ll i=1;i<=n;i++){
		if((sel&(1ll<<(i-1)))&&getfa(i)==i){
			tot++;
		}
	}
	if(tot>2) return 10000000000;
	memset(dis,0x3f,sizeof(dis));
	for(ll i=1;i<=n;i++){
		if(sel&(1ll<<(i-1))){
			dis[i]=0;
			q.push(i);
			vis[i]=1;
		}
	}
	while(q.size()){
		ll h=q.front();
		q.pop();
		for(ll i=0;i<ed[h].size();i++){
			if(!vis[ed[h][i]]){
				vis[ed[h][i]]=1;
				dis[ed[h][i]]=dis[h]+1;
				q.push(ed[h][i]);
			}
		}
	}
	ll mx=0;
	for(ll i=1;i<=n;i++){
		mx=max(mx,dis[i]); 
	}
	return mx;
}
void work(){
	input();
	ll mnans=1000000000;
	for(ll i=0;i<(1ll<<n);i++){
		mnans=min(mnans,chk(i));
	}
	for(ll i=1;i<=n;i++){
		ed[i].clear();
	}
	cout<<mnans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		work();
	}
}