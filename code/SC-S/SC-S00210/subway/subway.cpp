#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 105,M = 1e6+5,LOG = 20;
inline int read(){
	int x= 0,f = 1 ;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		x = (x<<3)+(x<<1)+(ch^48);
		ch = getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10^48);
}

int c,n,m,d,q,w[M],h[M],cnt,ct,di[M],dep[M],fa[22][M];
struct E{
	int to,nxt,dis;
}e[M*3];
inline void add(int f,int t,int dis){
	e[++cnt] = {t,h[f],dis};
	h[f] = cnt;
}
void dfs(int u,int Fa){
	dep[u] = dep[Fa]+1;
	fa[0][u] =Fa;
	for(int i = h[u];i;i = e[i].nxt){
		int v = e[i].to;
		if(v == Fa) continue;
		di[v] = di[u] + e[i].dis;
//		cerr<<u<<' '<<v<<'\n';
		dfs(v,u);
	}
}
void pre_work(){
	for(int i = 1;i<=LOG;i++){
		for(int j = 1;j<=ct+n;j++){
			fa[i][j] = fa[i-1][fa[i-1][j]];
		}
	}
}
int lca(int x,int y){
	if(dep[x] < dep[y]) swap(x,y);//x deeper
	int cha = dep[x] - dep[y];
	for(int i = 0;i<=LOG;i++){
		if(cha&(1<<i)){
			x = fa[i][x];
		}
	}
	if(x == y) return x;
	for(int i = LOG;i>=0;i--){
		if(fa[i][x]!=fa[i][y]){
			x = fa[i][x],y = fa[i][y];
		}
	}
	return fa[0][x];
}
int calculate(int x,int y){
	return di[x]+di[y] - 2*di[lca(x,y)];
}
bool vis[M];
void dij(int start){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
	memset(di,0x3f,sizeof di);
	memset(vis,0,sizeof vis);
	di[start] = 0;
	que.push({0,start});
	while(!que.empty()){
		int x = que.top().second;
		que.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = h[x];i;i = e[i].nxt){
			int v = e[i].to;
			if(di[v] > di[x] + e[i].dis){
				di[v] = di[x] + e[i].dis;
				que.push({di[v],v});
			}
		}
	}
}
void solve1(){
	int l,r;
	while(q--){
		l = read(),r =read();
		dij(l);
		write(di[r]+w[l]+w[r]);
		putchar('\n');
	}
}
void solve2(){
	dfs(1,0);
	pre_work();
	int l,r;
	while(q--){
		l = read(),r =read();
		write(calculate(l,r)+w[l]+w[r]);
		putchar('\n');
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	for(int i = 1;i<=m;i++) w[i]=read();
	ct = m;
	
	//不妨把一个路线视为一个点
	//lca???
	for(int i = 1,k;i<=n;i++){
		k = read();
		int nowtag = ct+i;
		for(int j = 1,a,t;j<=k;j++){
			a = read(),t = read();
			add(a,nowtag,t);
			add(nowtag,a,t);
		}
	}
	if(n<=50) solve1();
	else solve2();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16


*/