#include<bits/stdc++.h>
using namespace std;
const int N = 35;
int qc, t, n, k, cnt, mx, dep[N];
vector <int> g[N];
int w[N];
void dfs0(int p, int fa){
	for(auto x : g[p]){
		if(x == fa)continue;
		dfs0(x, p);
		if(!w[p] && w[x])cnt++;
	}
}
bool ck(){
	cnt = 0;
	dfs0(1, 0);
	cnt += (int)w[1];
	return cnt <= 2;
}
int dfs1(int p, int fa, int tp){
	dep[p] = dep[fa] + 1;
	int mn = w[p] ? 0 : N;
	for(auto x : g[p]){
		if(x == fa)continue;
		mn = min(mn, dfs1(x, p, w[p] ? p : tp) + 1);
	}
	mx = max(mx, min(mn, tp ? dep[p] - dep[tp] : N));
	return mn;
}
int query(){
	mx = 0;
	dfs1(1, 0, 0);
	return mx;
}
void solve(){
	int ans = N;
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++){
		g[i].clear();
	}
	for(int i = 1;i < n;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 1;i <= n;i++){
		w[i] = 0;
	}
	for(int i = 1;i <= k;i++){
		w[n - i + 1] = 1;
	}
	do{
		if(ck())ans = min(ans, query());
	}while(next_permutation(w + 1, w + n + 1));
	printf("%d\n", ans);
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &qc, &t);
	if(qc > 3){
		printf("QwQ");
		return 0;
	}
	while(t--){
		solve();
	}
	return 0;
}