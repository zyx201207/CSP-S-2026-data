#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int a[1004][50004], t[1004][50004], w[126000];
struct node{
	int v, w;
};
vector<node> e[2000];
int vis[1004];
int dis[1004];
void dfs(int x){
	vis[x] = 1;
	for(int i = 0;i < e[x].size();i++){
		int v = e[x][i].v, w = e[x][i].w;
		if(vis[v] == 1){
			continue;
		}
		if(dis[v] >= dis[x] + e[x][i].w){
			dis[v] = dis[x] + e[x][i].w;
		}
		dfs(v);
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin>>w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		int v, w;
		for(int j = 2;j <= 2*k;j++){
			cin>>v>>w;
			int u = v+500;
			node t;
			t.v = v, t.w = w;
			e[u].push_back(t);
			t.v = u;
			e[v].push_back(t);
		}
	}
	for(int i = 1;i <= q;i++){
		int x, y;
		cin>>x>>y;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			dis[i] = 2147483647;
		}
		for(int i = 1;i <= n;i++){
			vis[i] = 0;
		}
		dis[x] = 0;
		dfs(x);
		cout<<dis[y]<<endl;
	}
	return 0;
}