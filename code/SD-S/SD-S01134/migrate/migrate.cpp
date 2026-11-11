#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
const ll inf=1e14;
ll c,T,n,d;

struct node{
	ll v,w;
	node(ll _v,ll _w):v(_v),w(_w){}
	friend bool operator<(node x,node y){
		return x.w>y.w;
	}
};
vector<vector<node>>e;
vll dis,vis,cnt;
void addedge(ll u,ll v,ll w){
//	cerr<<"u="<<u<<", v="<<v<<", w="<<w<<endl;
	e[u].emplace_back(v,w);
	e[v].emplace_back(u,w);
}
void D(ll s){
	priority_queue<node>pq;
	pq.emplace(s,0);
	fill(dis.begin(),dis.end(),inf);
	fill(vis.begin(),vis.end(),0);
	fill(cnt.begin(),cnt.end(),0);
	dis[s]=0;
	cnt[s]=1;
	while(pq.size()){
		auto ux=pq.top();
		ll u=ux.v,x=ux.w;
//		cnt[u]=1;
		pq.pop();
		if(!vis[u]){
			vis[u]=1;
			for(auto vw:e[u]){
				ll v=vw.v,w=vw.w;
//				cout<<"u="<<u<<", dis[u]="<<dis[u]<<endl;
//				cout<<"v="<<v<<", dis[v]="<<dis[v]<<", w="<<w<<endl;		
				if(dis[v]>dis[u]+w){
//					cout<<"Case 1\n";
					dis[v]=dis[u]+w;
					cnt[v]=cnt[u];
//					cout<<"pq.emplace("<<v<<","<<dis[v]<<")\n";
					pq.emplace(v,dis[v]);
				}else if(dis[v]==dis[u]+w){
//					cout<<"Case 2\n";
					cnt[v]+=cnt[u];
				}
			}
		}
	}
}
void solve(){
	cin>>n>>d;
	vll a(n+1);
	e.resize(n+1),dis.resize(n+1),vis.resize(n+1),cnt.resize(n+1);
	for(ll i=1;i<=n;i++){
		e[i].clear();
		cin>>a[i];
		ll nw=i-1;
		while(nw>=1&&a[i]-a[nw]<=d){
			e[nw].emplace_back(i,1);
			nw--;
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		D(i);
		for(ll j=i+1;j<=n;j++){
			if(cnt[j]==2){
				ans++;	
			}
		}
	}
	cout<<ans<<"\n";
}
void solveA(){
	cin>>n>>d;
//	cout<<"¾àÀë="<<d<<endl;
	vll a(n+1);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
//	cout<<"¹«²î="<<a[2]-a[1]<<endl;
	if(d<=a[2]-a[1]){
		cout<<0<<"\n";
		return;
	}
	d/=(a[2]-a[1]);
	cout<<max(0ll,n-(2*d-1))<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		if(c==11||c==12)solveA();
		else solve();
	}
}

