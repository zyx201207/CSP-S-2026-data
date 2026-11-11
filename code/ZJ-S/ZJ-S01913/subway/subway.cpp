#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int N = 5e5+55;
int read(){
	int x=0,f=1;char s=getchar();
	while(!isdigit(s)){
		if (s == '-') f=-1;
		s=getchar();
	}while(isdigit(s)){
		x=x*10+s-'0';
		s=getchar();
	}return x*f;
}
ll SUM;
ll w[N],dis[505][505],tmpd[N+505];
int c,n,m,d,q;
int nums[505];
//vector<int>rd[505];
vector<int>tar[N],tms[N];//to visual dots >v<
ll val[(550)<<1];
int head[505],nxt[(505)<<1],to[(550)<<1],cnt;
void add(int u,int v,ll e) {
	nxt[++cnt] = head[u] ; 
	head[u] = cnt;
	to[cnt] = v;
	val[cnt] = e;
}
bool vis[505];
struct node {
	int id;
	ll ds;
	friend bool operator <(const node &a,const node &b) {
		return a.ds>b.ds;
	}
};
priority_queue<node> que;
void dij(int s) {
	//printf("---%d---\n",s);
	for(int i=1;i<=n;i++) {
		vis[i] = 0;
		tmpd[i] = SUM;
	}
	que.push({s,0});tmpd[s] = 0;
	while(!que.empty()){
		node now = que.top();
		que.pop();
		int id = now.id;
		if (vis[id]) continue;
		vis[id] = 1;
		//printf("(%d)\n",id);
		for(int i=head[id];i;i=nxt[i]) {
			int v = to[i];//printf("--->>>%d,%lld\n",v,tmpd[v]);
			if (tmpd[v]>tmpd[id]+val[i]){
				tmpd[v] = tmpd[id]+val[i];
				dis[s][v] = min(dis[s][v],tmpd[v]);
				que.push({v,tmpd[v]});
			}
		}
	}
}
int main(){
	
//	freopen("subway7.in","r",stdin);
//	freopen("bbb.ans","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	
	for(int i=1;i<=m;i++){
		w[i] = read(),SUM+=w[i];
	} 
	//n tiao xian 
	
	for(int i=1;i<=n;i++) {
		nums[i] = read();
		for(int j=1;j<=nums[i];j++) {
			int t = read();
			//rd[i].push_back(t);//zhongjian zhan
			tar[t].push_back(i);
			ll tt = read();
			tms[t].push_back(tt);//zhantai dao zhanting d shijian
			SUM+=tt+1;
//			add(i,n + t , tt ) ;
//			add(n+t , i , tt ) ;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if (i!=j) dis[i][j]= SUM;
	
	
	for(int i=1;i<=m;i++) {
		for(int j=1;j<tar[i].size();j++) {
			for(int k=0;k<j;k++) {
				int v1 = tar[i][j],v2 = tar[i][k];
				ll t1 = tms[i][j],t2 = tms[i][k] ; 
				add(v1,v2,t1+t2);
				add(v2,v1,t1+t2);
			}
		}
		
	}
	for(int i=1;i<=n;i++) {
		dij(i);
	}
	while(q--){
		int x=read(),y=read();
		
		ll ans = SUM;
		for(int i=0;i<tar[x].size();i++) {
			for(int j=0;j<tar[y].size();j++) {
				int u = tar[x][i],v = tar[y][j] ;
				if (dis[u][v]+tms[x][i]+tms[y][j] < ans) ans = dis[u][v]+tms[x][i]+tms[y][j];
			}
		}
		
		printf("%lld\n",ans +w[x] + w[y]);
	}
	return 0;
}/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/
