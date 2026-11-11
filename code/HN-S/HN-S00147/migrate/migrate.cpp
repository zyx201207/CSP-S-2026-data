#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
ll n,m,ans;
ll a[2000005],dis[2000005],cnt[2000005];
vector<ll> G[2000005];

void bfs(ll s){
	for(int i = 1;i <= n;i++) dis[i] = INF,cnt[i] = 0;
	queue<ll> q;
	q.push(s);
	dis[s] = 0,cnt[s] = 1;
	while(q.size()){
		ll x = q.front();
		q.pop();
		for(auto nx:G[x]){
			if(dis[nx] > dis[x] + 1){
				dis[nx] = dis[x] + 1;
				cnt[nx] = cnt[x];
				q.push(nx);
			}else if(dis[nx] == dis[x] + 1){
				cnt[nx] += cnt[x];
			}
		}
	}
	return ;
}

void work(){
	for(int i = 0;i <= n + 1;i++) G[i].clear();
	ans = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		ll pos = upper_bound(a + 1,a + 1 + n,a[i] + m) - a - 1;
		if(pos > i) G[i].push_back(pos);
		if(pos - 1 > i) G[i].push_back(pos - 1);
		if(pos - 2 > i)	G[i].push_back(pos - 2);
//		for(auto nx:G[i]){
//			cout << i << " " << nx << "\n";
//		}
	}
	for(int i = 1;i <= n;i++){
		bfs(i);
		for(int j = 1;j <= n;j++){
//			cout << j << " " << cnt[j] << "\n";
			ans += (cnt[j] == 2);
		}
	}
	cout << ans << "\n";
	return ;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll id,T; 
	cin >> id >> T;
	while(T--) work(); 
	return 0;
}
