#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c , t , n , k , mx , id , lst1 , len , lst2 , l1 , l2 ,vst[1000009] ,  p[1000009] , dst[1000009] , h[1000009] , lgh[1000009];
vector<ll> to[1000009];
void dfs1(ll u,ll fa){
	dst[u] = dst[fa]+1;
	p[u] = fa;
	h[u] = 1;
	if(dst[u] > mx){
		mx = dst[u];
		id = u;
	}
	for(ll i = 0; i < to[u].size(); i++){
		ll v = to[u][i];
		if(v == fa) continue;
		dfs1(v,u);
		h[u] = max(h[u],h[v]+1);
	}
} 
struct node{
	ll hght , dp , nm;
	bool operator<(const node&b)const{
		if(b.hght > b.dp){
			if(hght > dp){
				return hght < b.hght;
			}
			else{
				return dp < b.hght;
			}
		}
		else{
			if(hght > dp){
				return hght < b.dp;
			}
			else{
				return dp < b.dp;
			}
		}
	}
};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		memset(dst,0,sizeof(dst));
		memset(vst,0,sizeof(vst));
		memset(lgh,0x3f,sizeof(lgh));
		cin >> n >> k;
		vector<ll> nw[n+1];
		for(ll i = 1; i <= n; i++){
			to[i] = nw[i];
		}
		for(ll i = 1,u,v; i < n; i++){
			cin >> u >> v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		mx = 0 , id = 1;
		dfs1(1,0);
		lst1 = id;
		mx = 0;
		memset(dst,0,sizeof(dst));
		dfs1(lst1,0);
		len = dst[id]-1;
		lst2 = id;
		for(ll i = 1; i * 2 < len; i++){
			id = p[id];
		}
		mx = 0;
		memset(dst,0,sizeof(dst));
		dfs1(id,0);
		l1 = lst1;
		l2 = lst2;
		for(ll i = 1; i * 2 < dst[lst1]; i++) l1 = p[l1];
		for(ll i = 1; i * 2 < dst[lst2]; i++) l2 = p[l2];
		vst[l1] = 1;
		vst[l2] = 1;
		k -= 2;
		priority_queue<node> q;
		queue<ll> pq;
		pq.push(l1);
		pq.push(l2);
		lgh[l1] = 0;
		lgh[l2] = 0;
		for(ll i = 0; i < to[l1].size(); i++){
			q.push((node){h[to[l1][i]],1,to[l1][i]});
		}
		q.push((node){1,dst[p[l1]],p[l1]});
		for(ll i = 0; i < to[l2].size(); i++){
			q.push((node){h[to[l2][i]],1,to[l2][i]});
		}
		q.push((node){1,dst[p[l2]],p[l2]});
		while(!q.empty() && k > 0){
			ll u = q.top().nm;
			q.pop();
			if(vst[u] == 1) continue;
			vst[u] = 1;
			lgh[u] = 0;
			pq.push(u);
			k--;
			for(ll i = 0; i < to[u].size(); i++){
				q.push((node){h[to[u][i]],1,to[u][i]});
			}
			q.push((node){1,dst[p[u]],p[u]});	
		}
		while(!pq.empty()){
			ll u = pq.front();
			pq.pop();
			for(ll i = 0; i < to[u].size(); i++){
				if(lgh[to[u][i]] > lgh[u] + 1){
					lgh[to[u][i]] = lgh[u] + 1;
					pq.push(to[u][i]);
				}
			}
		}
		mx = 0;
		for(ll i = 1; i <= n; i++){
			mx = max(mx,lgh[i]);
		}
		cout << mx << '\n';
	}
	return 0;
} 
