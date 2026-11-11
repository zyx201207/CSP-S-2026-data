#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read() {
	ll res = 0, neg = 1; char ch = getchar();
	while(ch<'0' or ch>'9') { if(ch == '-') neg = -1; ch = getchar(); }
	while(ch>='0' and ch<='9') res = res*10 + ch-'0', ch = getchar();
	return res * neg;
}

void write(ll x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x+'0');
	else write(x/10), putchar(x%10+'0');
}

const int N = 1e3+10;

int C,T;

int n,k;
vector<int> g[N];

bool flag[N];
int nums[N], cnt;

int f[N];
void init() {
	for(int i=1; i<=n; i++) {
		f[i] = i;
	}
}
int find(int x) {
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

void merge(int x, int y) {
	f[find(y)] = find(x);
}

int dis[N]; bool vis[N];
int ans = 1e9;

void check() {
	init();
	for(int i=1; i<=cnt; i++)  {
		int u = nums[i];
		for(int v : g[u]) {
			if(flag[v]) merge(u,v);
		}
	}
	
	int scccnt = 0;
	for(int i=1; i<=n; i++) {
		if(flag[i] and f[i] == i) scccnt++;
	}
	
	if(scccnt > 2) return ;	
	
	int res = 0;
	queue<int> que;
	memset(vis, 0, sizeof(vis));
	memset(dis, 0, sizeof(dis));
	
	for(int i=1; i<=cnt; i++) que.push(nums[i]), dis[nums[i]] = 0, vis[nums[i]] = 1;
	while(que.size()) {
		int u = que.front(); que.pop();
		
		for(int v : g[u]) {
			if(!vis[v]) {
				vis[v] = 1;
				que.push(v);
				dis[v] = dis[u] + 1;
				res = max(res, dis[v]);
			}
		}
	}
	
//	if(res == 1) {
//		printf("#%d %d\n", scccnt,res);
//	for(int i=1; i<=cnt; i++) printf("%d ", nums[i]); puts("");
//	}
	
	ans = min(ans, res);
	
	return ;
}

void dfs(int x, int ek) {
	if(x > n) {
		if(ek != 0) return ;
		
		cnt = 0;
		for(int i=1; i<=n; i++) if(flag[i]) nums[++cnt] = i;
		check();
		
		return ;
	}
	
	dfs(x+1, ek);
	if(ek) {
		flag[x] = 1;
		dfs(x+1, ek-1);
		flag[x] = 0;
	}
}

void work() {
	if(C == 13 or C == 14) {
		n = read(), k = read();
		for(int i=1; i<n; i++) {
			int u = read(), v = read();
		}
		
		int ttt = 0;
		while(k < n) {
			n/=2;
		}
		write(ttt), putchar('\n');
		
		return ;
	}
	
	ans = 1e9;
	for(int i=1; i<=n; i++) g[i].clear();
	
	n = read(), k = read();
	for(int i=1; i<n; i++) {
		int u = read(), v = read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1,k);
	
	write(ans), putchar('\n');
	
	return ;
}


int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	C = read(), T = read();
	while(T--) work();
	
	/*
	//freopen(); -catching
	I failed.
	
	X X XXX
	XX X XXX
	X X X XXXX
	XX XX XXX X X
	*/
	
	return 0;
}
