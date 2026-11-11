#include<bits/stdc++.h>

using namespace std;

vector<int> G[2000010];

int mx = 0;
int id = 0;

int pre[2000010];

void dfs(int u, int fa, int dep){
	if(mx < dep){
		mx = dep;
		id = u;
	}
	pre[u] = fa;
	for(int v : G[u]){
		if(v == fa){
			continue;
		}
		dfs(v, u, dep + 1);
	}
}

void dfs2(int u, int fa, int now2, int dep){
	if(mx < dep){
		mx = dep;
		id = u;
	}
//	pre[u] = fa;
	for(int v : G[u]){
		if(v == fa || v == now2){
			continue;
		}
		dfs2(v, u, now2, dep + 1);
	}
}

int vis[25];
int vis2[25];

void dfs3(int u, int fa){
	for(int v : G[u]){
		if(v == fa || vis2[v] == 1 || vis[v] == 0){
			continue;
		}
		vis2[v] = 1;
		dfs3(v, u);
	}
}

int mn2 = 1e9;

void dfs4(int u, int fa, int dep){
	for(int v : G[u]){
		if(vis[v] == 1){
			mn2 = min(mn2, dep + 1);
			continue;
		}
		if(v == fa){
			continue;
		}
		dfs4(v, u, dep + 1);
	}
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			G[i].clear();
		}
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(n <= 10){
			int mn = 1e9;
			for(int i = 1; i < (1 << n); i++){
				for(int j = 1; j <= n; j++){
					vis[j] = vis2[j] = 0;
				}
				int st1 = 0;
				int cnt = 0;
				for(int j = 0; j < n; j++){
					if(i & (1 << j)){
						st1 = j + 1;
						vis[j + 1] = 1;
						cnt++;
					}
				}
				if(cnt != k){
					continue;
				}
				vis2[st1] = 1;
				dfs3(st1, 0);
				int st2 = 0;
				for(int j = 1; j <= n; j++){
					if(vis[j] == 1 && vis2[j] == 0){
						st2 = j;
					}
				}
//				cout << st1 << " " << st2 << "\n";
				vis2[st2] = 1;
				dfs3(st2, 0);
				
				int f = 0;
				for(int j = 1; j <= n; j++){
					if(vis[j] == 1 && vis2[j] == 0){
						f = 1;
					}
				}
				if(f == 1){
					continue;
				}
//				for(int j = 0; j < n; j++){
//					if(i & (1 << j)){
//						cout << j + 1 << " ";
//					}
//				}
//				cout << "!\n";
//				cout << i << "!\n";
				int mx1 = 0;
				for(int j = 1; j <= n; j++){
					if(vis[j] == 1){
						continue;
					}
					mn2 = 1e9;
					dfs4(j, 0, 0);
//					cout << j << " " << mn2 << '\n';
					mx1 = max(mx1, mn2);
				}
				mn = min(mn, mx1);
			}
//			cout << "\n\n";
			cout << mn << "\n";
		}else{
			mx = 0;
			id = 1;
			dfs(id, 0, 0);
			mx = 0;
			dfs(id, 0, 0);
			int now = id;
			int ed = mx / 2;
			while(ed--){
				now = pre[now];
			}
			dfs(now, 0, 0);
			mx = 0;
			int now2 = id;
			ed = (mx + 1) / 2;
			while(ed--){
				now2 = pre[now2];
			}
			mx = 0;
			dfs2(now, now2, 0, 0);
			int mx1 = mx;
			mx = 0;
			dfs2(now2, now, 0, 0);
			cout << max(mx1, mx) << "\n";
		}
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