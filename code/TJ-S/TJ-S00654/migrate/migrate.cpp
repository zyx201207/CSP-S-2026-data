#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, t;
struct node{
	int step, u;
};
int n, d, x[N], ans = 0;
vector<int> e[N];
node tong[N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(int ii = 1; ii <= t; ii ++){ 
		for(int i = 1; i <= n; i ++) e[i].clear();
		cin >> n >> d; 
		for(int j = 1; j <= n; j ++) cin >> x[j];
		//½¨Í¼  
		for(int i = 1; i <= n; i ++){
			for(int j = i + 1; j <= n; j ++){
				if(x[j] - x[i] <= d){
					e[j].push_back(i);
					e[i].push_back(j);
				}
				else break;
			}
		}
		bool vis[N];
		queue<node> q;
		for(int i = 1; i <= n; i ++){
			tong[i].step = tong[i].u = vis[i] = 0;
		}
		q.push((node){0, 1});
		vis[1] = 1;
		while(!q.empty()){
			node p = q.front(); q.pop();
			if(tong[p.u].u == 0 || tong[p.u].step >= p.step) tong[p.u].u ++, tong[p.u].step = p.step;
			for(int i = 0; i < (int)e[p.u].size(); i ++){
				int v = e[p.u][i];
				if(vis[v]) continue;
				vis[v] = true;
				q.push((node){p.step + 1, v});
			}
		}
		for(int i = 1; i <= n; i ++){
			if(tong[i].u == 2) ans ++;
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}  
