#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int c, t, n, k, fa[20], dis[20], vis[20]; 
vector<int> l[20];

int check(int a[]){
	for(int i = 1;i <= n;i++){
		fa[i] = 0;
	//	cout << a[i] << " ";
	}
//	cout << " == "; 
	int kuai = 0;
	for(int i = 1;i <= n;i++){
		if(a[i]){
			for(int j = 0;j < l[i].size();j++){
				int v = l[i][j];
				if(fa[v]){
					fa[i] = fa[v];
				}
			//	cout << i << " " << v << "  ";
			}
			if(fa[i] == 0){
				fa[i] = 1;
				kuai++;
			//	cout << i <<"  ";
			} 
		}
	}
	if(kuai > 2){
		return 1e9;
	}
//	cout << "abab" <<"   ";
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int i = 1;i <= n;i++){
			dis[i] = 1e9;
			vis[i] = 0;
		}
		
		if(a[i] == 0){
			int anss = 1e9;
			queue<pair<int, int> > q;
			q.push({0, i});
			while(!q.empty()){
				int w = q.front().first, u = q.front().second;
				q.pop();
				if(vis[u]){
					continue;
				} 
				vis[u] = 1;
				for(int j = 0;j < l[u].size();j++){
					int v = l[u][j];
					if(vis[v] == 0 && dis[v] > w + 1){
						dis[v] = w +1;
						q.push({dis[v], v});
					}
				}
			}
			
			for(int i = 1;i <= n;i++){
				if(a[i]){
					anss = min(anss, dis[i]);
			//		cout << dis[i] << " ";
				}
			}
			ans = max(anss, ans);
		}
	}
//	cout <<ans << endl;
	return ans;
}

int dfs(int i, int ch, int a[]){
	int ans = 1e9;
	if(i == n + 1){
		if(ch == k){
			ans = min(ans, check(a));
		}
		return ans;
	}
	ans = dfs(i + 1, ch, a);
	a[i] = 1;
	ans = min(ans, dfs(i + 1, ch + 1, a));
	a[i] = 0;
	return ans;
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1;i <= n;i++){
			l[i].clear();
		}
		for(int i = 1;i < n;i++){
			int u, v;
			cin >> u >> v;
			l[u].push_back(v);
			l[v].push_back(u);
		}
		int a[20] = {};
		cout << dfs(1, 0, a) <<endl;
	}
}
//0 2
//5 2
//1 2
//2 3
//3 4
//4 5
//10 3
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//3 8
//7 9
//9 10

