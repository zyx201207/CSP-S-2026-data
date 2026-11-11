#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,nn=505;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
int c,n,m,d,q,w[N];
bool used[N][nn];
struct node{
	int x,val;
};
vector<node>g[N];
struct edge{
	int to,val;
};
vector<edge>e[N];
inline void add(int x,int y,int z){
	e[x].push_back((edge){y,z});
	return;
}
struct point{
	int x,val;
	bool operator<(point xx)const{
		if(xx.val<val)return 1;
		return 0;
	}
};
priority_queue<point>que;
int dis[nn][nn],vis[nn];
inline void dij(int s){
	for(int i=0;i<nn;i++)vis[i]=0;
	que.push({s,0});
	while(!que.empty()){
		int u=que.top().x,val=que.top().val;
		vis[u]=1;
		que.pop();
		for(edge v:e[u]){
			if(vis[v.to])continue;
			if(dis[s][v.to]>dis[s][u]+v.val){
				dis[s][v.to]=dis[s][u]+v.val;
				que.push((point){v.to,v.val});
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int l=read();
		for(int j=1;j<=l;j++){
			int x=read(),z=read();
			used[i][x]=1;
			g[x].push_back((node){i,z});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				add(g[i][j].x,g[i][k].x,g[i][j].val+g[i][k].val);
				add(g[i][k].x,g[i][j].x,g[i][j].val+g[i][k].val);
			}
		}
	}
	for(int i=0;i<nn;i++)for(int j=0;j<nn;j++)dis[i][j]=1e18;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++)dij(i);
	while(q--){
		int x=read(),y=read(),ans=1e18,ans1=1e18,ans2=1e18;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				ans=min(ans,dis[g[x][i].x][g[y][j].x]+g[x][i].val+g[y][j].val);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
//#include<bits/stdc++.h>
//#include<queue>
//#define int long long
//using namespace std;
//const int N=3e6+5;
//inline int read(){
//	int x=0,f=1;
//	char c=getchar();
//	while(c<'0'||c>'9'){
//		if(c=='-')f=-1;
//		c=getchar();
//	}
//	while(c>='0'&&c<='9'){
//		x=(x<<3)+(x<<1)+c-48;
//		c=getchar();
//	}
//	return x*f;
//}
//int c,n,m,d,q,w[N],a[N],cnt[N];
//struct edge{
//	int to,val;
//};
//vector<edge>e[N];
//map<int,int>dis[N],vis;
//inline void add(int x,int y,int z){
////	printf("ADD%lld %lld %lld\n",x,y,z);
//	e[x].push_back((edge){y,z});
//	return;
//}
//struct node{
//	int x,val;
//	bool operator<(node xx)const{
//		if(xx.val<val)return 1;
//		return 0;
//	}
//};
//priority_queue<node>que;
//inline void dij(int s){
//	vis.clear();
////	puts("!");
//	que.push({s,0});
//	while(!que.empty()){
//		int u=que.top().x,val=que.top().val;
////		printf("U%lld %lld\n",u,dis[s][u]);
//		vis[u]=1;
//		que.pop();
//		for(edge v:e[u]){
//			if(vis[v.to]==1)continue;
////			printf("V%lld %lld %lld %lld ",v.to,dis[s][v.to],dis[s][u],v.val);
//			if(dis[s][v.to]==0||dis[s][v.to]>dis[s][u]+v.val){
////			printf("V%lld ",v.to);
//				dis[s][v.to]=dis[s][u]+v.val;
//				que.push((node){v.to,v.val});
//			}
//		}
////		puts("");
//	}
//	return;
//}
//signed main(){
//	freopen("subway3.in","r",stdin);
//	freopen("subway.out","w",stdout);
////	que.push((node){1,1});
////	que.push((node){1,2});
////	printf("%lld\n",que.top().val);
//	c=read(),n=read(),m=read(),d=read(),q=read();
//	for(int i=1;i<=m;i++)w[i]=read();
//	for(int i=1;i<=n;i++){
//		int l=read();
//		for(int j=1;j<=l;j++){
//			a[j]=read();
//			cnt[a[j]]++;
//			int z=read();
//			add(a[j]+m*cnt[a[j]],a[j],z);
//			add(a[j],a[j]+m*cnt[a[j]],z);
//			if(j>1){
//				add(a[j]+m*cnt[a[j]],a[j-1]+m*cnt[a[j-1]],0);
//				add(a[j-1]+m*cnt[a[j-1]],a[j]+m*cnt[a[j]],0);
//			}
//		}
//	}
//	for(int i=1;i<=m;i++)dis[i][i]=-1;
//	for(int i=1;i<=m;i++)dij(i);
////	dij(112);
////	for(int i=1;i<=m;i++){
////		for(int j=1;j<=m;j++){
////			printf("%lld ",dis[i][j]); 
////		}
////		puts("");
////	}
////	printf("##%lld %lld\n",w[112],w[57]);
//	while(q--){
//		int x=read(),y=read();
//		if(x==y)printf("0\n");
//		else printf("%lld\n",dis[x][y]+w[x]+w[y]+1);
//		
//	}
//	return 0;
//}
///*
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//*/
/*
作为退役一年后的第一战
打的应该还算可以
希望成绩能如我所愿吧 
*/
