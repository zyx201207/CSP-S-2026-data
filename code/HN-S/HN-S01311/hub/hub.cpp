#include<bits/stdc++.h>
using namespace std;
const int inf = INT_MAX/3;
int n, k, tag[1000010], tag1[1000010], tag2[1000010], ans;
vector<int> g[1000010];
bool check(){
	int res = 0;
	for(int i = 1; i <= n; i++) tag1[i] = tag[i];
	for(int i = 1; i <= n; i++){
		if(!tag1[i]) continue;
		if(res >= 2) return 0;
		res++;
		tag1[i] = 0;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int v : g[u]){
				if(!tag1[v]) continue;
				q.push(v);
				tag1[v] = 0;
			}
		}
	}
	if(res != 2) return 0;
	return 1;
}
void dfs(int _, int __){
	if(_ > n){
		if(__ != k) return ;
		int res = 0;
		if(!check()) return ;
		for(int i = 1; i <= n; i++){
			if(tag[i]) continue;
			for(int j = 1; j <= n; j++) tag2[j] = 0;
			queue<pair<int, int> > q;
			q.push({i, 0});
			tag2[i] = 1;
			while(!q.empty()){
				pair<int, int> u = q.front();
				if(tag[u.first]){
					res = max(res, u.second);
					break;
				}
				q.pop();
				for(int v : g[u.first]){
					if(tag2[v]) continue;
					tag2[v] = 1;
					q.push({v, u.second + 1});
				}
			}
		}
		ans = min(ans, res);
		return ;
	}
	if(__ >= k) dfs(_+1, __);
	else{
		dfs(_+1, __);
		tag[_] = 1;
		dfs(_+1, __+1);
		tag[_] = 0;
	}
	return ;
}
void solve(){
	ans = inf;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		g[i].clear();
		tag[i] = tag1[i] = tag2[i] = 0;
	}
	for(int i = 1; i <= n-1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return ;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	scanf("%d%d", &c, &T);
	while(T--) solve();
	return 0;
}
//万圣节是圣诞节吗？ 
