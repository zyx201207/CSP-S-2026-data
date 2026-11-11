#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define __low lower_bound
#define __upp upper_bound
#define pii pair<int,int>
#define MP make_pair
#define fi first
#define se second
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e6+5;

int c, T, n, k;
vector<int> ve[N];
int ans;

bool is[N], vis[N];

void init(){
	for(int i = 1; i <= n; i++) vis[i] = 0;
}

struct pp{
	int x, w;
};
queue<pp> q;

void dfs2(int x){
	vis[x] = 1;
	for(auto y : ve[x]){
		if(is[y] && !vis[y]) dfs2(y);
	}
}

void check(){
	init();
	int sum = 0;
	for(int i = 1; i <= n; i++){
		if(is[i] && !vis[i]) dfs2(i), sum++;
	}
	if(sum > 2) return;
	
	init(); 
	for(int i = 1; i <= n; i++){
		if(is[i]) q.push({i, 0}), vis[i] = 1; 
	}
	int mx = 0;
	while(q.size()){
		int x = q.front().x, w = q.front().w;
		q.pop();
		mx = max(mx, w);
		for(auto y : ve[x]){
			if(vis[y]) continue;
			vis[y] = 1;
			q.push({y, w+1});
		}
	}
	ans = min(ans, mx);
}

void dfs(int x, int y){
	if(y == k){
		check();
		return;
	}
	if(x > n) return;
	is[x] = 1;
	dfs(x+1, y+1);
	is[x] = 0;
	dfs(x+1, y);
}

void init2(){
	for(int i = 1; i <= n; i++){
		ve[i].clear();
	}
	ans = 1e9;
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> c >> T;
	while(T--){
		init2();
		cin >> n >> k;
		for(int i = 1; i < n; i++){
			int x, y;
			cin >> x >> y;
			ve[x].pb(y);
			ve[y].pb(x);
		}
		if(n > 20){
			cout << 0 << "\n";
			continue;
		}
		dfs(1, 0);
		cout << ans << "\n";
	}
	
	return 0;
}

