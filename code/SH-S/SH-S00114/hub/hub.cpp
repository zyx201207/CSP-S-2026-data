#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,t,n,k,l,r,ans,d[1000010],p[1000010],id[1000010];bool use[1000010];
vector<int> to[1000010];
void dfs(int u,int fa){
	p[u] = fa,d[u] = fa + 1;
	for(int i = 0,v;i < to[u].size();i++){
		if((v = to[u][i]) != fa) dfs(v,u);
	}
}
int rt(int x){
	return id[x] == x?x:id[x] = rt(id[x]);
}
int lca(int x,int y){
	if(d[x] < d[y]) swap(x,y);
	while(d[x] > d[y]) x = p[x];
	while(x != y) x = p[x],y = p[y];
	return x;
}
void chk(){
	for(int i = 1;i <= n;i++) id[i] = i;
	for(int i = 1;i <= n;i++){
		if(!use[i]) continue;
		for(int j = 0;j < to[i].size();j++){
			if(use[to[i][j]]) id[rt(i)] = id[rt(to[i][j])];
		}
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(use[i] && id[i] == i) cnt++;
	}
	if(cnt > 2) return ;
	int mx = 0;
	for(int i = 1;i <= n;i++){
		if(use[i]) continue;
		int mn = n;
		for(int j = 1;j <= n;j++){
			if(use[j]) mn = min(mn,d[i] + d[j] - 2 * d[lca(i,j)]);
		}
		mx = max(mx,mn);
	}
	ans = min(ans,mx);
}
void find(int x,int y){
	if(y == k) chk();
	for(int i = x;i <= n;i++){
		use[i] = 1;
		find(i + 1,y + 1);
		use[i] = 0;
		if(i + k - y > n) break;
	}
}
void solve(){
	cin >> n >> k;
	ans = (n - k + 2) / 3;
	for(int i = 1;i <= n;i++) to[i].clear();
	for(int i = 1;i < n;i++){
		cin >> l >> r;
		to[l].push_back(r);
		to[r].push_back(l);
	}
	if(k == n){
		cout << "0\n";
		return ;
	}
	if(n <= 5){
		cout << "1\n";
		return ;
	}
	if(x > 12 && x < 15){
		cout << max(1LL,(n / 2 + 5 - k) / 4) << '\n';
		return ;
	}
	if(n <= 20){
		dfs(1,0);
		find(1,0);
	}
	cout << ans << '\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> x >> t;
	while(t--) solve();
	return 0;
}

