#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll INF=1e18;
const string SUBWAY="AC";

struct node{
	ll st,t;//station && time
	bool operator<(const node x)const{
		return t<x.t;
	}
};

/*
void Dijstra(ll S){
	vector<ll> vis(m,INF);
	vis[S]=0;
	priority_queue<node,cmp> pq;
	for(auto f:g[m]){
		for (auto i:road[f]){
			pq.push(i);
		}
	}
}*/

void solve(){
	
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	ll w[m];
	for (ll i=1;i<=m;i++) cin>>w[i];
	vector<node> road[n];
	vector<ll> g[m];
	for (ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		while (k--){
			node x;
			cin>>x.st>>x.t;
			road[i].push_back(x);
			g[x.st].push_back(i);
		}
	}
	vector<vector<ll>> to(m,vector<ll>(m,INF));
	
	//Dijstra
	for (ll S=1;S<m;S++){
		to[S][S]=0;
		priority_queue<node> pq;
		for(auto f:g[S]){
			for (auto i:road[f]){
				pq.push(i);
			}
		}
		while (!pq.empty()){
			node ddd=pq.top();pq.pop();
			ll t=ddd.t,st=ddd.st;
			if (to[S][st]>=t+w[S]+w[st]) continue;
			
			to[S][st]=to[st][S]=t+w[S]+w[st];
			for(auto f:g[st]){
				for (auto i:road[f]){
					i.t+=t;
					pq.push(i);
				}
			}
		}
	}/*
	while (q--){
		ll d1,d2;
		cin>>d1>>d2;
		cout<<to[d1][d2];
	}*/
	return ;
}

int main(){
	//cout<<"HelloWorld!";
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
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
