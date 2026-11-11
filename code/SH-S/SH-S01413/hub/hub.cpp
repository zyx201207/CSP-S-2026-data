/*

看来真的要afo了
这四道题T1做得生龙活虎，T2做得一坨大粪 ，T3做得一坨大粪 ，T4做得一坨大粪 

本来中间做t2的时候脑子特别清晰。结果越做越烦。做到最后都不知道自己要干什么了。
结果就是t2,t3,t4都没写出来，然后现在18:11，肚子痛得要命。
痛了1个多小时了
我真不理解，最近几个月每天忙到23点多才准备睡觉的结果是什么？
结果是csps越考越拉？

还能说啥呢。体制内的语文差的离谱。还要备考国际高中

afo吧

至少我曾经还来过

--- 2026/10/31 18:13

*/
#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 +10;

vector<int>G[N];
int n, k,siz[N],dep[N],fa[N][40],sum;

void dfs(int x, int parent) {
	siz[x] = 1;
	dep[x] = dep[parent] = 1;
	fa[x][0] = parent; 
	for (int y : G[x]) {
		if (y == parent) continue;
		dfs(y, x);
		siz[x]+=siz[y];
	}
}

int lca(int u, int v) {
	if(dep[u]<dep[v])swap(u,v);
	for(int j=29;j>=0;j--){
		if(dep[fa[u][j]]>=dep[v])
			u=fa[u][j];
	}
	if(u==v)return u;
	for(int j=29;j>=0;j--)
		if(fa[u][j]!=fa[v][j])
			fa[u][j]=fa[v][j];
	return fa[u][0];
}

int calc(int x, int y) {
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}

int maxx(int root){
	int res=0;
	for(int y:G[root])res=max(res,siz[y]);
	return res;
}

void dfs1(int x,int parent) {
	sum=max(sum,max(maxx(x),dep[x]-dep[1]));
	for (int y : G[x])if(y!=parent)dfs1(y,x);
}

void solve() {
	cin >> n >> k;
	bool flag=1;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		if (!(v == u + 1))flag=0;
		G[u].push_back(v);
		G[v].push_back(u); 
	}
	if(flag){
		cout<<(n-k)/3+((n-k)%3>0)<<"\n";
		return;
	}
	dfs(1,0);
	for (int j = 1; j < 30; j++)
		for (int i = 1; i <= n; i++)
			fa[i][j] = fa[fa[i][j-1]][j-1];
	dfs1(1,0); 
	cout<<sum<<"\n";
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
