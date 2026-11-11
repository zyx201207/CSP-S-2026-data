/*
[24, 50] pts. 
*/
#include<bits/stdc++.h>
#define Hahaha using
#define I namespace
#define AK std
#define IOI ;
#define ll long long
#define N (int)(5e5 + 10)
Hahaha I AK IOI
vector<int> g[N];
ll c, n, d, a[N], dis[N], cnt[N], ans;

void bfs(int x){
	for(int i = 1; i <= n; i++){
		cnt[i] = 0;
		dis[i] = 1e18;
	}
	queue<pair<int, int>> q;
	q.push({x, 0});
	cnt[x] = 1;
	dis[x] = 0;
	while(q.size()){
		int u = q.front().first;
		int s = q.front().second;
		q.pop();
		for(auto v : g[u]){
			if(s + 1 < dis[v]){
				dis[v] = s + 1;
				cnt[v] = cnt[u];
				q.push({v, dis[v]});
			}else if(s + 1 == dis[v]){
				cnt[v] += cnt[u];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(cnt[i] == 2){
			ans++;
		}
	}
}

void work(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(a[j] - a[i] <= d){
				g[i].push_back(j);
			}else{
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		bfs(i); 
	}
	cout << ans << "\n";
	for(int i = 1; i <= n; i++){
		g[i].clear();
	}
	ans = 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int oT_To = 1;
	cin >> c >> oT_To;
	while(oT_To--){
		work();
	}
	return 0;
}
