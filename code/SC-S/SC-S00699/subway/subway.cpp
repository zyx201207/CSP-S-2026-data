#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct node{
	int to,k;
};
int n,m,d,q;
int w[N],k[N],t[505][20005];
int dis[N];
vector<node> g[N];
bool vis[N];
void dfs(int s,int k){
	vis[s] = 1;
	for(auto c : g[s]){
		dis[c.to] = min(t[k][c.to] + t[c.k][s] + dis[s],dis[c.to]);
		if(!vis[c.to])
			dfs(c.to,c.k);
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> m >> m >> n >> d >> q;
	for(int i = 1;i <= n;i++)
		cin >> w[i];
	for(int i = 1;i <= m;i++){
		cin >> k[i];
		int last = 0,x,y;
		if(k[i] == 1) continue;
		cin >> x;
		cin >> t[i][x];
		cin >> y;
		cin >> t[i][y];
		g[x].push_back({y,i});
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		memset(dis,0x3f,sizeof dis);
		dis[x] = w[x];
		dfs(x,0);
		cout << dis[y] << '\n';
	}
	return 0;
} 