#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
ll n,m;
ll dis[1000005],cnt[1 << 21];
bool vis[1000005],use[1000005];
vector<ll> G[1000005];

void dfs(ll x,ll fa){
	if(use[x] == 0) return ;
	if(vis[x]) return ;
	vis[x] = 1;
	for(auto nx:G[x]){
		if(nx != fa){
			dfs(nx,x);
		}
	}
	return ;
}

void bfs(){
	for(int i = 0;i <= n + 1;i++) dis[i] = INF;
	queue<ll> q;
	for(int i = 1;i <= n;i++){
		if(use[i]){
			q.push(i);
			dis[i] = 0;
		}
	}
	while(q.size()){
		ll x = q.front();
		q.pop();
		for(auto nx:G[x]){
			if(dis[nx] > dis[x] + 1){
				dis[nx] = dis[x] + 1;
				q.push(nx);
			}
		}
	}
	return ;
}

void work(){
	for(int i = 0;i <= n + 1;i++) G[i].clear();
	cin >> n >> m;
	ll ans = INF;
	for(int i = 1;i < n;i++){
		ll s,e;
		cin >> s >> e;
		G[s].push_back(e);
		G[e].push_back(s); 
	} 
	cnt[0] = 0;
	for(int i = 0;i < (1 << n);i++){
		cnt[i] = cnt[i >> 1] + (i & 1);
		if(cnt[i] != m) continue;
		for(int j = 0;j < n;j++){
			use[j + 1] = (i >> j) & 1;
			vis[j + 1] = 0;
			dis[j + 1] = INF;
		}
		ll cnt = 0;
		for(int j = 1;j <= n;j++){
			if(use[j] && vis[j] == 0){
				dfs(j,0);
				cnt++;
			}
		} 
		if(cnt > 2) continue;
		bfs();
		ll tmp = -INF;
		for(int j = 1;j <= n;j++){
			tmp = max(tmp,dis[j]);
		}
		ans = min(ans,tmp);
	}
	cout << ans << "\n";
	return ;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll T;
	cin >> T;
	cin >> T;
	while(T--) work();
	return 0;
}
