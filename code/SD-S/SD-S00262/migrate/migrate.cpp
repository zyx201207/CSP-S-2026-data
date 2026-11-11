#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 2e6 + 10;
ll c, t;
ll cnt, sum;
ll a[MX];
ll step[MX];
vector<ll> e[MX];
bool vis[MX];
ll bfs(ll x, ll p){
	queue<ll> q;
	q.push(x);
	step[x] = 1;
	while(!q.empty()){
		ll t = q.front();
		q.pop();
		for(auto it : e[t]){
			if(!step[it]){
				step[it] = step[t] + 1;
				q.push(it);
			}
		}
	}
	return --step[p];
}
void dfs(ll x, ll p, ll st){
	if(x == p){
		if(st == sum){
			cnt++;
		}
		return;
	}
	for(auto it : e[x]){
		if(!vis[it]){
			vis[it] = 1;
			dfs(it, p, st + 1);	
			vis[it] = 0;
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	int maxn = -1;
	while(t--){
		for(int i = 1; i <= maxn; i ++)	e[i].clear(); 
		memset(a, 0, sizeof(a));
		int n, d;
		cin >> n >> d;
		maxn = max(maxn, n);
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
		}
		if(n <= 100){
			for(int i = 1; i <= n; i ++){
				for(int j = i + 1; j <= n; j ++){
					if(a[j] - a[i] <= d){
						e[i].push_back(j);
						e[j].push_back(i);
					}	
				}
			}
			ll ans = 0;
			for(int i = 1; i <= n; i ++){
				for(int j = i + 1; j <= n; j ++){
					memset(step, 0, sizeof(step));
					memset(vis, 0, sizeof(vis));
					vis[i] = 1;
					cnt = 0;
					sum = bfs(i, j);
					dfs(i, j, 0); 
					if(cnt == 1 + 1){
						ans++;
					}
				}
			}
			cout << ans << endl;
		}
		cout << 0 << endl;
	}

	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
