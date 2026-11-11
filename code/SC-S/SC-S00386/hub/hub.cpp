#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000050;
const long long inf = 1000000000000000000;
struct Node{
	long long nxt,to;
};
vector<long long> e;
Node Graph[2 * MAXN];
long long t,head[MAXN],n,m,dep[MAXN],fa[MAXN][22],answer[MAXN],ans,r,c,x,y;
bool vis[MAXN],v[MAXN];
inline void insert_line(long long x,long long y);
inline void find(long long x,long long y);
inline long long query(long long x,long long y);
inline void bfs(long long x);
inline void check();
inline void work_out(long long x,long long y);
inline void solve();
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while (t --){
		solve();
	}
	return 0;
}
inline void insert_line(long long x,long long y){
	Graph[ans].to = y;
	Graph[ans].nxt = head[x];
	head[x] = ans++;
	return ;
}
inline void find(long long x,long long y){
	dep[x] = dep[y] + 1;
	fa[x][0] = y;
	for (long long i = 1;i <= 20;i ++){
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for (long long i = head[x];~i;i = Graph[i].nxt){
		long long to = Graph[i].to;
		if (to == y){
			continue;
		}
		find(to,x);
	}
	return ;
}
inline long long query(long long x,long long y){
	if (dep[x] < dep[y]){
		swap(x,y);
	}
	for (long long i = 20;i >= 0;i --){
		if (dep[fa[x][i]] >= dep[y]){
			x = fa[x][i];
		}
	}
	if (x == y){
		return x;
	}
	for (long long i = 20;i >= 0;i --){
		if (fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
inline void bfs(long long x){
	queue<long long> q;
	vis[x] = true;
	q.push(x);
	while (!q.empty()){
		long long cur = q.front();
		q.pop();
		for (long long i = head[cur];~i;i = Graph[i].nxt){
			long long to = Graph[i].to;
			if (vis[to] || !v[to]){
				continue;
			}
			vis[to] = true;
			q.push(to);
		}
	}
	return ;
}
inline void check(){
	for (long long i = 1;i <= n;i ++){
		vis[i] = false;
	}
	long long cnt = 0;
	for (long long i = 0;i < e.size();i ++){
		if (!vis[e[i]] && v[e[i]]){
			cnt ++;
			bfs(e[i]);
		}
	}
	if (cnt > 2){
		return ;
	}
	long long ans = -inf;
	for (long long i = 1;i <= n;i ++){
		answer[i] = inf;
		for (long long j = 0;j < e.size();j ++){
			answer[i] = min(answer[i],dep[i] + dep[e[j]] - 2ll * dep[query(i,e[j])]);
		}
		ans = max(ans,answer[i]);
	}
	r = min(r,ans);
	return ;
}
inline void work_out(long long x,long long y){
	if (y == m){
		check();
		return ;
	} else if (x == n + 1){
		return ;
	}
	v[x] = true;
	e.push_back(x);
	work_out(x + 1,y + 1);
	e.pop_back();
	v[x] = false;
	work_out(x + 1,y);
	return ;
}
inline void solve(){
	scanf("%lld %lld",&n,&m);
	r = inf;
	for (long long i = 0;i <= n;i ++){
		head[i] = -1;
	}
	ans = 0;
	for (long long i = 1;i < n;i ++){
		scanf("%lld %lld",&x,&y);
		insert_line(x,y);
		insert_line(y,x);
	}
	find(1,0);
	work_out(1,0);
	printf("%lld\n",r);
	return ;
}