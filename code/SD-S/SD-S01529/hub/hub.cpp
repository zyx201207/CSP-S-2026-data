#include<bits/stdc++.h>

using namespace std;

int read(){
	int x = 0,y = 1;
	char ch = getchar();
	while(ch > '9'||ch < '0'){
		if(ch == '-') y = -1;
		ch = getchar();
	}
	while(ch >= '0'&&ch <= '9'){
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*y;
}

void print(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	char ch = x%10+'0';
	if(x >= 10) print(x/10);
	putchar(ch);
}

int ceshidian;

int n,k;
vector<int> e[1000005];

int dep[1000005];
int st[1000005][21];

void dfs_lca(int x,int com){
	
	dep[x] = dep[com]+1;
	
	st[x][0] = com;
	for(int i = 1;i < 21;++ i)
		st[x][i] = st[st[x][i-1]][i-1];
	
	for(int _ = 0;_ < e[x].size();++ _){
		int y = e[x][_];
		if(y == com) continue;
		dfs_lca(y,x);
	}
	
}

int get_lca(int x,int y){
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 20;i >= 0;-- i)
		if(dep[st[x][i]] >= dep[y])
			x = st[x][i];
	if(x == y) return x;
	for(int i = 20;i >= 0;-- i)
		if(st[x][i] != st[y][i])
			x = st[x][i],y = st[y][i];
	return st[x][0];
}

int get_dis(int x,int y){
	return dep[x]+dep[y]-2*dep[get_lca(x,y)];
}

int g[500005];
bool vs[1000005];
bool bfsvs[1000005];
int dans;

void bfs(int sta){
	queue<int> q;
	q.push(sta);
	bfsvs[sta] = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int _ = 0;_ < e[x].size();++ _){
			int y = e[x][_];
			if(vs[y]&&(!bfsvs[y])){
				q.push(y);
				bfsvs[y] = 1;
			}
		}
	}
}

bool check(){
	for(int i = 1;i <= n;++ i)
		bfsvs[i] = 0;
	int cnt = 2;
	for(int i = 1;i <= k;++ i)
		if(cnt&&(!bfsvs[g[i]])) bfs(g[i]),cnt--;
	for(int i = 1;i <= k;++ i)
		if(!bfsvs[g[i]]) return 0;
	return 1;
}

void dfs(int x){
	
	if(x > k){
		if(!check()) return;
		int ans = 0;
		for(int i = 1;i <= n;++ i){
			int res = n-1;
			for(int j = 1;j <= k;++ j){
				res = min(res,get_dis(i,g[j]));
			}
			ans = max(ans,res);
		}
		dans = min(dans,ans);
		return;
	}
	
	for(int i = 1;i <= n;++ i)
		if(!vs[i]){
			g[x] = i;
			vs[i] = 1;
			dfs(x+1);
			vs[i] = 0;
		}
	
}

void pwq_ovo(){
	
	n = read(),k = read();
	for(int i = 1;i < n;++ i){
		int u = read(),v = read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	dep[0] = -1;
	dfs_lca(1,0);
	
	dans = n-1;
	dfs(1);
	print(dans);putchar('\n');
	
	for(int i = 1;i <= n;++ i){
		e[i].clear();
		dep[i] = 0;
		for(int j = 0;j < 21;++ j)
			st[i][j] = 0;
	}
	
	return;
	
}

signed main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ceshidian = read();
	int _ = read();
	while(_--) pwq_ovo();
	
	return 0;
	
}
