#include <bits/stdc++.h>

using namespace std;

int c;

const int N = 1e5 + 10;

struct Node{
	int to,nxt = -1;
}e[N << 1];

int h[N],tot;

void init(){
	memset(h,-1,sizeof h);
	tot = 0;
}

void add(int u,int v){
	e[++tot].to = v;
	e[tot].nxt = h[u];
	h[u] = tot;
}

void solve(){
	int n,k;
	cin >> n >> k;
	init();
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v),add(v,u);
	}
}

void solve1(){

}

bool check(){
	return 1;
}

int get(){
	return 0;
}

/*
void solve2(){
	int n,k;
	cin >> n >> k;
	vector<vector<bool>> g(n + 1,vector<bool>(n + 1,false)),d(n + 1,vector<int>(n + 1,1e9));
	for(int i = 0;i <= n;i++) d[i][i] = 0;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		d[u][v] = d[v][u] = g[u][v] = g[v][u] = true;
	}
	vector<bool> hub(n + 1,0);
	int res = 1e9;
	for(int k = 1;k <= n;k++) for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
	for(int i = 0;i < 1 << n;i++){
		int cnt = 0;
		for(int j = 0;j < n;j++){
			cnt += i >> j & 1;
			hub[j + 1] = i >> j & 1;
		}
		if(cnt != k) continue;
		if(!check()) continue;
		res = min(res,get());
	}
	cout << res << "\n";
}
*/

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> c >> t;
	if(c == 12 || c == 13){
		while(t--) solve1();
		return 0;
	}
	/*if(c >= 1 && c <= 3){
		while(t--) solve2();
	}*/
	while(t--) solve();
	return 0;
}
