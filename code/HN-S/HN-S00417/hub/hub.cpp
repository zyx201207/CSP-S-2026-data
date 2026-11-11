#include <bits/stdc++.h>

#define multicase() int t;cin>>t;while(t--)

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

void fast_io(){
	ios::sync_with_stdio(0);
	cin.tie(0) ,cout.tie(0);
}

const ll kMaxN = 1e5 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

vector<ll> g[kMaxN];

ll fa[107];
ll c;
ll n , k;

bool check1(ll p){
	ll res = 0;
	while(p){
		if(p & 1) res ++;
		p >>= 1;
	}
	return res == k;
} 

ll find(ll x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

bitset<107> bt;
bitset<107> vis;
vector<ll> sel;

void debug(ll x){
	for(int i = 0 ; i < n; i++){
		if(x & (1 << i)) cout<<i+1<<" "; 
	}
}

bool check2(ll x){
	for(int i = 1 ; i <= n ; i++) fa[i] = i;
	bt.reset();
	sel.clear();
	ll sum = 0;
	for(int i = 0 ; i < n ; i++){
		if(x & (1 << i)) {
			sum++;
			bt[i+1] = 1;
			sel.push_back(i+1);
		}
	}
	if(sum <= 2) return 1;
//	debug(x),cout<<" - \n";
//	for(auto v : sel) cout<<v<<" ";
//	cout<<'\n';
	vis.reset();
	vector<ll> pd;
	pd.push_back(2);
	pd.push_back(3);
	pd.push_back(10);
	for(auto p : sel){
		if(vis[p]) continue;
		vis[p] = 1;
		for(auto v : g[p]){
//			if(sel == pd) cout<<v<<" - "<<p<<"\n";
			if(bt[v]) {
				sum--;
				vis[v] = 1;
			}
		}
	}
//	for(auto p : sel){
//		for(auto v : g[p]){
//			if(!bt[v]) continue;
//			ll vv = find(v);
//			ll i = find(p);
//			fa[vv] = i;
//		}
//	}
//	sum = 0;
//	bt.reset();
//	for(auto p : sel){
//		if(!bt[find(p)]) sum++ , bt[find(p)] = 1; 
//	}
	return sum <= 2;
}



ll dep[107];

ll calc(ll x){
	memset(dep , 0x3f , sizeof dep);
	queue<ll> que;
	for(int i = 0 ; i < n ; i++){
		if(x & (1 << i)) {
			que.push(i+1);
			dep[i+1]=0;
		} 
	}
	while(!que.empty()){
		ll u = que.front();
		que.pop();
		for(auto v : g[u]){
			if(dep[v] == inf) {
				dep[v] = dep[u] + 1;
				que.push(v);
			}
		}
	}
	ll res = 0;
	for(int i = 1 ; i <= n ; i++){
		res = max(res , dep[i]);
	}
	return res;
}

void solve(){
	for(int i = 1 ; i <= n ; i++) g[i].clear();
	cin>>n>>k;
	for(int i = 1 ; i < n ; i++){
		ll u , v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll upS = 1 << n;
	ll ans = inf; 
	for(int S = 0 ; S < upS ; S++){
		if(!check1(S)) continue;
//		debug(S),cout<<"---\n";
		if(!check2(S)) continue;
//		debug(S);
//		cout<<calc(S)<<"\n"; 
		ans = min(ans , calc(S));
//		debug(S);
//		cout<<"---";		
	}
	cout<<ans;
}

int main(){
	fast_io();
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	cin>>c;
	multicase(){
		solve();
		cout<<"\n";
	}
	return 0;
}

