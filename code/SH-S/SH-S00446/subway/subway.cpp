#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct u{
	ll p,val;
	bool operator < (const u ef) const{
		return val>ef.val;
	}
};
ll c,n,m,d,q,w[20010],k,dis[510][21010],dis2[4][501010],vis[21010],vis2[501010];
vector<u> e[501010];

void dij(ll pt){
	priority_queue<u> pq;
	pq.push({pt+m,0});
	dis[pt][pt+m]=0;
	while(!pq.empty()){
		u hd=pq.top();
		pq.pop();
		if(vis[hd.p]) continue;
		vis[hd.p]=1;
		for(auto v:e[hd.p]){
			if(dis[pt][hd.p]+v.val<dis[pt][v.p]){
				dis[pt][v.p]=dis[pt][hd.p]+v.val;
				pq.push({v.p,dis[pt][v.p]});
			}
		}
	}
}
void dij2(ll pt){
	priority_queue<u> pq;
	pq.push({pt+m,0});
	dis2[pt][pt+m]=0;
	while(!pq.empty()){
		u hd=pq.top();
		pq.pop();
		if(vis2[hd.p]) continue;
		vis2[hd.p]=1;
		for(auto v:e[hd.p]){
			if(dis2[pt][hd.p]+v.val<dis2[pt][v.p]){
				dis2[pt][v.p]=dis2[pt][hd.p]+v.val;
				pq.push({v.p,dis2[pt][v.p]});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,tmp;
			cin>>a>>tmp;
			e[a].push_back({m+i,tmp});
			e[m+i].push_back({a,tmp});
		}
	}
	if(n<=2){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n+m;j++) dis2[i][j]=1e18;
		}
		for(ll i=1;i<=n;i++){
			memset(vis2,0,sizeof(vis2));
			dij2(i); 
		}
		while(q--){
			ll l,r,ans=1e18;
			cin>>l>>r;
			for(ll i=1;i<=n;i++) ans=min(ans,dis2[i][l]+dis2[i][r]);
			cout<<ans+w[l]+w[r]<<"\n";
		}
		return 0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n+m;j++) dis[i][j]=1e18;
	}
	for(ll i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dij(i); 
	}
	while(q--){
		ll l,r,ans=1e18;
		cin>>l>>r;
		for(ll i=1;i<=n;i++) ans=min(ans,dis[i][l]+dis[i][r]);
		cout<<ans+w[l]+w[r]<<"\n";
	}
	return 0;
}
