#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const ll LEN = 5e5+10;
struct eage{
	ll end, dis;
	bool operator<(const eage &n)const{
		return n.dis < dis; 
	}
};
ll C, N, M, D, Q, W[LEN];
unordered_map<ll, ll> T[600];
vector<ll> flag[LEN];
vector<eage> E[600];
ll D_(ll s, ll e){
	bool flag[600] = {0};
	ll maxx[600];
	memset(maxx, 0x3f, sizeof(maxx));
	priority_queue<eage> Q;
	Q.push({s, 0});
	maxx[s] = 0;
	while(!Q.empty()){
		ll v = Q.top().end;
		Q.pop();
		if(e == v) break;
		if(flag[v]) continue;
		flag[v] = true;
		for(ll i = 0; i < E[v].size(); i++){
			ll v_ = E[v][i].end, d_ = maxx[v]+E[v][i].dis;
			if(d_ < maxx[v_] && !flag[v_]){
				Q.push({v_, d_});
				maxx[v_] = d_;
			}
		}
	} return maxx[e];
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld %lld %lld %lld %lld", &C, &N, &M, &D, &Q);
	for(ll i = 1; i <= M; i++){
		scanf("%lld", &W[i]);
	} for(ll i = 0; i < N; i++){
		ll q = 0;
		scanf("%lld", &q);
		for(ll j = 0; j < q; j++){
			ll a = 0, t = 0;
			scanf("%lld %lld", &a, &t);
			T[i][a] = t;
			for(ll k = 0; k < flag[a].size(); k++){
				ll p = flag[a][k], x = t+T[p][a];
				E[i].push_back({p, x});
				E[p].push_back({i, x}); 
			} flag[a].push_back(i);
		}
	} for(ll i = 0; i < Q; i++){
		ll s = 0, e = 0, minn = INT_MAX;
		scanf("%lld %lld", &s, &e);
		for(ll j = 0; j < flag[s].size(); j++){
			for(ll k = 0; k < flag[e].size(); k++){
				ll v = T[flag[s][j]][s];
				ll u = T[flag[e][k]][e];
				minn = min(minn, D_(flag[s][j], flag[e][k])+v+u);
			}
		} printf("%lld\n", minn+W[s]+W[e]);
	}
	return 0;
}