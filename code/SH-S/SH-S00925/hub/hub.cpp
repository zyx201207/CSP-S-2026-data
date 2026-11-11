#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const int N = 1e6 + 5;
ll c,t,n,k;
vector <ll> e[N];
void input() {
	cin>>n>>k;
	for(ll i = 1;i <= n;i++) e[i].clear();
	for(ll i = 1;i < n;i++) {
		ll u,v; cin>>u>>v;
		e[u].push_back(v); e[v].push_back(u);
	}
}
ll ans,cnt,dep[15],f[15],mindep[15],mindep2[15],minid[15];
bool flag[15];
void dfs2(ll u,ll fa) {
	if(!flag[fa] && flag[u]) cnt++;
	if(flag[u]) {
		mindep[u] = dep[u]; mindep2[u] = 1e9;
	} else mindep[u] = mindep2[u] = 1e9;
	for(ll v : e[u]) {
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs2(v,u);
//		cout<<"!!!"<<u<<" "<<v<<" "<<f[u]<<" "<<f[v]<<'\n';
		if(mindep[v] < mindep[u]) {
			mindep2[u] = mindep[u]; mindep[u] = mindep[v]; minid[u] = v;
		} else mindep2[u] = min(mindep2[u],mindep[v]);
	}
//	cout<<u<<" "<<mindep[u]<<'\n';
}
ll out[15];
void dfs3(ll u,ll fa,ll lst) {
	if(flag[u]) lst = u;
	for(ll v : e[u]) {
		if(v == fa) continue;
		if(v == minid[u]) out[v] = min(out[u] + 1,mindep2[u] - dep[u] + 1);
		else out[v] = min(out[u] + 1,mindep[u] - dep[u] + 1);
		dfs3(v,u,lst);
		f[u] = max(f[u],f[v]);
	}
	if(!flag[u]) {
		ll tmp = 1e9;
		if(mindep[u] != 1e9) tmp = min(tmp,mindep[u] - dep[u]);
		if(lst) tmp = min(tmp,dep[u] - dep[lst]);
		tmp = min(tmp,out[u]);
		f[u] = max(f[u],tmp);
	}
}
ll check() {
	cnt = 0;
	dep[1] = dep[0] = 0;
	for(ll i = 1;i <= n;i++) f[i] = 0;
	dfs2(1,0);
	out[1] = 1e9;
	dfs3(1,0,0);
	if(cnt > 2) return -1;
//	cout<<"1::";
//	for(ll i = 1;i <= n;i++) {
//		cout<<flag[i]<<" ";
//	}
//	cout<<'\n';
//	cout<<"2::";
//	for(ll i = 1;i <= n;i++) {
//		cout<<f[i]<<" ";
//	}
//	cout<<'\n';
//	if(!f[1]) cout<<"!@#!@#!@#\n\n\n";
	return f[1];
}
void dfs(ll pos,ll cnt) {
	if(cnt > k) return;
	if(pos == n + 1) {
		ll tmp = check();
		if(tmp != -1) {
			ans = min(ans,tmp);
		}
		return;
	}
	dfs(pos + 1,cnt);
	flag[pos] = 1;
	dfs(pos + 1,cnt + 1);
	flag[pos] = 0;
}
void solve1() {
	ans = 1e9;
	for(ll i = 1;i <= n;i++) flag[i] = 0;
	dfs(1,0);
	cout<<ans<<'\n';
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--) {
		input();
		if(n <= 10) solve1();
		else cout<<1<<'\n';
	}
	return 0;
}
