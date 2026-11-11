#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int c, t, n, d, a[N];

int mindis;
vector<string>minpath;

bool vis[N];

void dfs(const int &ed, int x, int dis, string path){
	if(x == ed){
		if(dis < mindis){
			mindis = dis;
			minpath.clear();
			minpath.push_back(path);
		}
		else if(dis == mindis) minpath.push_back(path);
		return;
	}
	
	if(dis > mindis) return;
	
	for(int i = x + 1; i <= n; ++i){
		if(a[i] - a[x] > d) break;
		if(!vis[i]){
			vis[i] = true;
			char c = '0' + i;
			dfs(ed, i, dis + a[i] - a[x], path + c);
			vis[i] = false;
		}
	}
	for(int i = x - 1; i >= 1; --i){
		if(a[x] - a[i] > d) break;
		if(!vis[i]){
			vis[i] = true;
			char c = '0' + i;
			dfs(ed, i, dis + a[x] - a[i], path + c);
			vis[i] = false;
		}
	}
}

bool check(int x, int y){
	for(int i = 1; i <= n; ++i) vis[i] = false;
	mindis = 2e9;
	minpath.clear();
	vis[x] = true;
	dfs(y, x, 0, "");
	return minpath.size() == 2 && minpath[0] != minpath[1];
}

int main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = i + 1; j <= n; ++j){
				if(check(i, j)) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*

T3

n 个岛屿, 第 i 个坐标为 x[i]
每次最多飞过 d 的距离



*/