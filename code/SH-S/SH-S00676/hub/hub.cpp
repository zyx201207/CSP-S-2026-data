#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;

const int maxn = 1e5 + 15,maxk = 21,inf = 1e9;
struct graph{
	int to,nex;
}a[maxn * 2];
int n,k,fa[maxn][maxk],d[maxn],cnt = 1,head[maxn],ans;
bool vis[maxn];
void add(int x,int y){
	a[cnt] = {y,head[x]};
	head[x] = cnt++;
}
void input(){
	scanf("%d%d",&n,&k);
	for(int i = 1;i < n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
}
void clean(){
	for(int i = 1;i <= cnt;i++) a[i] = {0,0};
	for(int i = 1;i <= n;i++){
		d[i] = head[i] = vis[i] = 0;
		for(int j = 0;j < maxk;j++) fa[i][j] = 0;
	}
	cnt = 1;
}
void dfs(int x,int pa){
	for(int i = head[x];i;i = a[i].nex){
		int to = a[i].to;
		if(to == pa) continue;
		d[to] = d[x] + 1;
		fa[to][0] = x;
		dfs(to,x);
	}
}
int getlca(int x,int y){
	int res = 0;
	if(d[x] < d[y]) swap(x,y);
	while(d[x] != d[y]){
		
		int r = log2(d[x] - d[y]);
		//printf("%d %d %d\n",x,y,r);
		res += (1 << r);
		x = fa[x][r];
	}
	if(x == y) return res;
	for(int j = maxk - 1;j >= 0;j--){
		if(fa[x][j] != fa[y][j]) x = fa[x][j],y = fa[y][j],res += 2 * (1 << j);
	}
	return res + 2;
}
void test(){
	int res = 0;
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		int di = inf;
		for(int j = 1;j <= n;j++){
			//printf("%d\n",j);
			if(vis[j]) di = min(di,getlca(i,j));
		}
		res = max(res,di);
	}
	ans = min(ans,res);
}
void bfs(int s,vector<bool> &ta){
	queue<int> q;
	q.push(s);
	ta[s] = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = head[x];i;i = a[i].nex){
			int to = a[i].to;
			if(vis[to] && !ta[to]){
				ta[to] = 1;
				q.push(to);
			}
		}
	}
}
void work(int x,int cnt){
	if(n - x + 1 + cnt < k) return ;
	if(cnt == k){
		int c = 0;
		vector<bool> ta(n + 5,0);
		
		for(int i = 1;i <= n;i++){
			if(vis[i] && !ta[i]){
				bfs(i,ta);
				c++;
			}
		}
		
		if(c > 2) return ;
		test();
		return ;
	}
	vis[x] = 1;
	work(x + 1,cnt + 1);
	vis[x] = 0;
	work(x + 1,cnt);
}
void solve(){
	ans = inf;
	input();
	d[1] = 1;
	dfs(1,0);
	for(int j = 1;j < maxk;j++){
		for(int i = 1;i <= n;i++){
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
	//printf("%d\n",fa[9][1]);
	work(1,0);
	//printf("%d\n",getlca(4,6));
	printf("%d\n",ans);
	clean();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
