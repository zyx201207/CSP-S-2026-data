#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long res = 0ll;
	long long a = 1ll;
	char ch = getchar();
	while (ch < '0' || ch > '9'){
		if (ch == '-') a = -1ll;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9'){
		res = res * 10ll + ch - '0';
		ch = getchar();
	}
	return res * (long long)a;
} 
int c , n , m , d , q;
long long w[1000005];
struct Edge{
	int to;
	int next;
	long long val;
}edge[2000005];
int tot;
int head[1000005];
void add(int x,int y,long long val){
	edge[++tot].to = y;
	edge[tot].next = head[x];
	edge[tot].val = val;
	head[x] = tot;
	return ;
}
struct FT{
	int from;
	int to;
	int id;
}ft[1000005];
bool cmp(FT x,FT y){
	if (x.from == y.from) return x.to < y.to;
	return x.from < y.from;
}
long long ans[1000005];
long long dp[1000005];
int vis[1000005];
queue <int> qu;
void bfs(int f){
	while (qu.size() > 0) qu.pop();
	qu.push(f);
	dp[f] = 0;
	while (qu.size()){
		int x = qu.front();
		qu.pop();
		for (int i = head[x];i;i = edge[i].next){
			int y = edge[i].to;
			
			if (vis[y] == 0 || dp[x] + edge[i].val < dp[y]){
				dp[y] = dp[x] + edge[i].val;
				vis[y] = 1;
				qu.push(y);
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for (int i = 1;i <= m;i++){
		w[i] = read();
	}
	for (int i = 1;i <= n;i++){
		int k = read();
		for (int j = 1;j <= k;j++){
			long long a = read(),t = read();
			add(a,m + i+1,t);
			add(m + i+1,a,t);
		}
//		for (int j = head[m + i + 1];j;j = edge[j].next){
//			printf("i:%d,j:%d",edge[j].to,m + i + 1);
//			printf("val:%lld\n",edge[j].val);
//		}
	}
	for (int i = 1;i <= q;i++){
		ft[i].from = read();
		ft[i].to = read();
		ft[i].id = i;
	}
	sort(ft+1,ft+1+q,cmp);
	int lf = 0;
	for (int i = 1;i <= q;i++){
		if (lf == 0 || ft[i].from != lf){
			for (int j = 1;j <= n + m + 1;j++){
				dp[j] = (1 << 30);
				vis[j] = 0;
			}
			lf = ft[i].from;
			bfs(lf);
//			for (int j = 1;j <= m + n + 1;j++){
//				printf("%d,%lld\n",j ,dp[j]);
//			}
//			printf("\n");
		}
		ans[ft[i].id] = dp[ft[i].to] + w[ft[i].from] + w[ft[i].to];
	}
	for (int i = 1;i <= q;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
