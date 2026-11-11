#include <bits/stdc++.h>
using namespace std;
int ccc,T;
int n,k;
const int N = 1e6 + 10;
vector <int> g[N];
bool vis[N];
int fa[N];
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
int dep[N];
void dfs(int u,int fa){
	
	for (int now1 = 0;now1 < g[u].size();now1 ++){
		int v = g[u][now1];
		if(v == fa) continue;
		if(!vis[v]){
			dfs(v,u);
			dep[u] = min(dep[u],dep[v] + 1);
		}else{
			dep[v] = 0;
			
		}
	}
	return;
}
void solve(){
	scanf("%d%d",&n,&k);
	if(k >= n){
		printf("0\n");
		return;
	}
	for (int i = 1;i <= n;i ++){
		g[i].clear();
	}
	for(int i = 1;i < n;i ++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 1e9;
	for (int S = 0;S < (1 << n);S ++){
		int sum = 0;
		for (int j = 0;j < n;j ++){
			dep[j + 1] = 0;
			fa[j + 1] = j + 1;
			if(S & (1 << j)) sum ++,vis[j + 1] = 1;
		}
		if(sum > k) continue;
		for (int i = 1;i <= n;i ++){
			if(vis[i]){
				for (int now1 = 0;now1 < g[i].size();now1 ++){
					int j = g[i][now1];
					if(vis[j] == 0) continue;
					int fi = find(i),fj = find(j);
					if(fi == fj) continue;
					fa[fi] = fj;
				}
			}
		}
		int qwq1 = 0,qwq2 = 0,scc = 0;
		bool no = 0;
		for (int i = 1;i <= n;i ++){
			if(vis[i]){
				int pwp = find(i);
				if(qwq1 == 0 ){
					qwq1 = pwp;
					scc = 1;
				}else if(qwq1 != pwp && qwq2 == 0){
					qwq2 = pwp;
					scc = 2;
				}else if(scc == 2 && pwp != qwq1 && pwp != qwq2){
					no = 1;
				}
				
			}
		}
		if(no) continue;
		int ovo = 1e9;
		for (int i = 1;i <= n;i ++){
			
			if(!vis[i]){
				cout << i << " ";
				dfs(i,0);
				ovo = max(dep[i],ovo);
			}
		}
		cout << endl;
		ans = min(ans,ovo);
	}
	printf("%d\n",ans);
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&ccc,&T);
	while(T --){
		solve();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
