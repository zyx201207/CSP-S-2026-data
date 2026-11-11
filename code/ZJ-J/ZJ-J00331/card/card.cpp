#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,m,a[N],cnt[N],sz[N];
vector<int> e[N];
bool vis[N];
void dfs(int u){
	sz[u] = cnt[u];
	for (int v:e[u]){
		dfs(v);
		sz[u] += sz[v];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i = 1;i <= n;++ i){
		cin>>a[i];
	}
	for (int i = n;i >= 1;-- i){
		if (!vis[a[i]]) e[a[i + 1]].push_back(a[i]);
		cnt[a[i]] ++;
		vis[a[i]] = 1;
	}
	dfs(0);
	for (int i = 1;i <= m;++ i){
		cout<<sz[i]<<' ';
	}
	return 0;
}