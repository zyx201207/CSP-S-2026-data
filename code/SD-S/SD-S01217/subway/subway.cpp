#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e3+5;
const int N=505;
const int C=25;
const int B=5e5+5;
int c,n,m,d,q,w[M];
int a[N][C],t[N][C],k[N],head[M+N],cnt;
ll dis[N+M][N+M];
struct node{int to,ne,len;}e[B<<1];
inline void add(int A,int B,int w){
e[++cnt]={(node){B,head[A],w}};
head[A]=cnt;	
}
struct NO{int num;ll dist;};
priority_queue<NO>Q;
bool operator <(NO A,NO B){return A.dist>B.dist;}
inline void dijkstra(int s){
	while(!Q.empty())Q.pop();
	Q.push((NO){s,0});
	while(!Q.empty()){
		NO u=Q.top();
		Q.pop();
		ll o=u.num,w=u.dist;
		if(w>dis[s][o])continue;
		for(int i=head[o];i;i=e[i].ne){
			int v=e[i].to,W=e[i].len;
			if(dis[s][v]>W+dis[s][o]){
				dis[s][v]=W+dis[s][o];
				Q.push((NO){v,dis[s][v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
    	scanf("%d",&k[i]);
    	int num=m+i;
    	for(int j=1;j<=k[i];j++){
    	scanf("%d %d",&a[i][j],&t[i][j]);
    	add(m+i,a[i][j],t[i][j]);
    	add(a[i][j],m+i,t[i][j]);
    }
	}
	for(int i=1;i<=m+n;i++)
	for(int j=1;j<=m+n;j++)
	if(i!=j)
	dis[i][j]=1e15;
	for(int i=1;i<=m+n;i++)
	dijkstra(i);
	int x,y;
	for(int i=1;i<=q;i++){
		scanf("%d %d",&x,&y);
		printf("%lld\n",dis[x][y]+w[x]+w[y]);
	}
	return 0;
}

