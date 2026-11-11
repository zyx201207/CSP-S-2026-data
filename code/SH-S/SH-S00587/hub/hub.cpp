#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

const ll N = 1000005;

ll c, t, n, k, ans, ch[N];
vector<ll> tre[N];
bool vis1[N], vis2[N];
queue<pi> q;
ll bfs1(ll st){
	memset(vis1, 0, sizeof(vis1));
	ll res = N;
	q.push((pi){st, 0});
	while(!q.empty()){
		pi u = q.front(); q.pop();
		if(ch[u.first]){
			res = min(res, u.second);
			continue;
		}
		
		for(int i = 0; i < tre[u.first].size(); ++ i){
			int v = tre[u.first][i];
			if(vis1[v])
				continue;
			vis1[v] = true;
			q.push({v, u.second + 1});
		}
	}
	return res;
}
void bfs2(ll st){
	q.push((pi){st, 0});
	while(!q.empty()){
		pi u = q.front(); q.pop();
		for(int i = 0; i < tre[u.first].size(); ++ i){
			int v = tre[u.first][i];
			if(ch[v] && !vis2[v]){
				vis2[v] = true;
				q.push((pi){v, 0});
			}
		}
	}
}
void dfs(ll u, ll cnt){
	if(cnt == k){
		ll res = 0, tmp = 0;
		memset(vis2, 0, sizeof(vis2));
		
//		cout << "ch = ";
		for(ll i = 1; i <= n; ++ i){
			if(!ch[i])
				res = max(res, bfs1(i));
			else{
//				cout << i << ' ';
				if(!vis2[i]){
					bfs2(i);
					++ tmp;
					if(tmp > 2)
						break;
				}
			}
		}
//		cout << "\ntmp = " << tmp << endl;
		if(tmp != 2)
			return;
		
		ans = min(ans, res);
//		cout << "\nans = " << ans << endl;
		return;
	}
	if(u == n + 1)
		return;
	
	dfs(u + 1, cnt);
	ch[u] = true;
	dfs(u + 1, cnt + 1);
	ch[u] = false;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	while(t --){
//		printf("-------\n");
		ans = N;
		cin >> n >> k;
//		printf("n = %d\n", n);
		for(ll i = 1; i <= n; ++ i)
			tre[i].clear();
		
		for(ll i = 1; i < n; ++ i){
			ll u, v;
			cin >> u >> v;
			tre[u].push_back(v), tre[v].push_back(u);
		}
//		printf("n = %d\n", n);
//		for(ll i = 1; i <= n; ++ i){
//			for(int j = 0; j < tre[i].size(); ++ j)
//				cout << tre[i][j] << ' ';
//			cout << endl;
//		}
		dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
}
