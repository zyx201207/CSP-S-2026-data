#define MAXN 500005
#define INF 0x3f
#include <bits\stdc++.h>
using namespace std ;
struct fl{
	int r , w ;
	bool operator < (const fl &x)const{
	return x.w < w ; }
};
struct node{
	int lt ;
	vector<int>r ;
	vector<int>t ;
}w[MAXN];
int c,n,m,d,q ;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过
long long con[505][505] ;
bool vis[505] ;
int main(){
	memset(con , INF , sizeof(con)) ;
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q) ;
	for(int i = 1 ; i <= m ; i ++ ) {
		scanf("%d",&w[i].lt) ;
	}
	for(int i = 1 ; i <= n ; i ++ ){
		con[i][i] = 0 ;
		int k ; scanf("%d",&k) ;
		for(int j = 1 ; j <= k ; j ++){
			int a , t ;
			scanf("%d%d",&a,&t) ;
			w[a].r.push_back(i) ;
			w[a].t.push_back(t) ;
			if(w[a].r.size() >= 2){
				int len = w[a].r.size() ;
				len -- ;
				for(int l = 0 ; l <len ; l ++ ){
					long long W = w[a].t[l] + t ;
					con[i][w[a].r[l]] = min(con[i][w[a].r[l]],W) ;
					con[w[a].r[l]][i] = con[i][w[a].r[l]] ;
				}
			}
		}
	}
	for(int k = 1 ; k <= n ; k ++ ){
		for(int i = 1 ; i <= n ; i ++ ) {
			for(int j = 1 ; j <= n ; j ++ ) {
				if(con[i][k]+ con[k][j] < con[i][j]) con[i][j] =con[i][k]+ con[k][j] ;
			}
		}
	}
	for(int i = 1 ; i <= q ; i ++ ) {
		int s , v ;
		scanf("%d%d",&s,&v) ;
		long long ans = 1e18 ;
		int lens = w[s].r.size() ;
		int lenv = w[v].r.size() ;
		for(int j = 0 ; j < lens ; j ++ ) {
			for(int k = 0 ; k < lenv ; k ++ ){
				long long W = con[w[s].r[j]][w[v].r[k]]+w[s].t[j]+w[v].t[k] ;
				ans = min(ans,W) ;
			}
		}
		ans += w[s].lt + w[v].lt  ;
		printf("%lld\n",ans) ;
	}
//	for(int i = 1 ;; i <= q ; i ++ ) {
//		int s , v ;
//		scanf("%d%d",&s,&v) ;
//		priority_queue<fl>q ;
//		q.push(s) ;
//		while(!q.empty()){
//			fl f = q.top() ; q.pop() ;
//			for(int j = 1 ; j <= n ; j ++ ) {
//				if(con[f][j] == INF) continue ;
//				
//			}
//		}
//	}
	return 0 ;
}
