#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], y[500005], nxt[500005], dp[500005], deg[500005], da[300005];
vector<long long> b[300005], g[500005];
void topsort(){
	queue<long long> q;
	for(int i = 1;i<=n;i++){
		if(!deg[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		long long u = q.front();
//		printf("%lld %lld %lld\n", u, dp[u], a[u]);
		q.pop();
		for(auto v : g[u]){
			dp[v] += dp[u];
			deg[v]--;
			if(!deg[v]){
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(int i = 1;i<=n;i++){
		scanf("%lld", &a[i]);
		b[a[i]].push_back(i);
		if(i<n){
			g[i].push_back(i + 1);
			deg[i + 1]++;
		}
	}
	for(int i = 1;i<=m;i++){
		if(b[i].size()<2){
			continue;
		}
		for(int j = 0;j<=b[i].size() - 2;j++){
//			y[b[i][j]] = 1;
			g[b[i][j]].push_back(b[i].back() + 1);
			deg[b[i].back() + 1]++;
		}
	}
//	y[n] = 1;
//	for(int i = n;i>=1;i--){
//		if(y[i]){
//			nxt[i] = i;
//		}else{
//			nxt[i] = nxt[i + 1];
//		}
//	}
	for(int i = 1;i<=n;i++){
//		if(!y[i]){
//			g[i].clear();
//			g[i].push_back(nxt[i]);
//		}
		sort(g[i].begin(), g[i].end(), greater<long long>());
		if(g[i].size()==2){
			deg[g[i].back()]--;
			g[i].pop_back();
		}
		dp[i] = 1;
	}
	topsort();
	for(int i = 1;i<=n;i++){
		da[a[i]] += dp[i];
	}
	for(int i = 1;i<=m;i++){
		printf("%lld ", da[i]);
	}
	return 0;
}
/*
为什么没看到yhp555
AK（疑似？）感言：
djr在哪里？He AKed IOI.
/bx gjh
/bx wyt
/bx djr
/bx srt
/bx lyz
/bx wzm
/bx xch
/bx zry
/bx yls
/bx zhy
/bx ysq
/bx cyx 
/bx/bx/bx 
希望能被迷惑行为大赏的人围观 
被罚坐了qwq 
*/
