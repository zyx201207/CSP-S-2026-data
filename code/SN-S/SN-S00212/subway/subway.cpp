// 0≤c≤25，1≤n≤500，
//1≤m≤∑^n_i=1 k_i ≤5×10^5，1≤d≤20，1≤q ≤105
//考虑将一个点裂成20个点
//全源最短路会爆炸
//可以将相同线路缩成一个点！！！ 
//O(qmlogm)过不了
//形成一个二分图
//右点最多与d个左点有连边 
//求出地铁线路间的全源最短路，O(nmlogm)
//这里时间复杂度炸了 
#include<bits/stdc++.h>
#define pr pair<long long,int>
#define mp make_pair
#define fir first
#define se second
using namespace std;
const int maxn=5e5+505;
int c,n,m,d,q1,ta,tt,k[maxn],t,x,y,cnt;
int head[maxn],edgenum,head1[maxn],edgenum1,vis[maxn];
long long dis[maxn],w[maxn];
struct Edge{
	int to,nxt;
	long long w;
}edge[maxn*3],edge1[maxn*10];
void add(int from,int to,long long w){
	edge[++edgenum].to=to;
	edge[edgenum].nxt=head[from];
	edge[edgenum].w=w;
	head[from]=edgenum;
}
void add1(int from,int to,long long w){
	edge1[edgenum1].to=to;
	edge1[edgenum1].nxt=head1[from];
	edge1[edgenum1].w=w;
	head1[from]=edgenum1;
}
vector<pr> st[maxn];
priority_queue<pr,vector<pr>,greater<pr> > q;
void dijkstra(int x){
//	cout<<"alive\n";
	int cnt=0;
	for(int i=1;i<=n+m;i++)
		vis[i]=0,dis[i]=2e17;
	dis[x]=0;q.push(mp(0,x));
	while(!q.empty()){
		cnt++;
		pr tmp=q.top();q.pop();
		int tx=tmp.se;
		long long ty=tmp.fir;
		if(vis[tx]) continue;
		vis[tx]=1;
		for(int i=head[tx];i;i=edge[i].nxt){
			cnt++;
			int v=edge[i].to;
			if(dis[v]>ty+edge[i].w){
				dis[v]=ty+edge[i].w;
				if(!vis[v]) q.push({dis[v],v});
			}
		}
	}
//	cout<<cnt<<endl;
}
long long mp1[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q1);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%lld",&ta,&tt);
			add(i,n+ta,tt);
			add(n+ta,i,tt);
			st[ta].push_back(mp(tt,i)); 
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=1;j<=n;j++)
			if(i!=j)
				mp1[i][j]=dis[j];
	}
	for(int i=1;i<=q1;i++){
		scanf("%d%d",&x,&y);
		long long ans=1e17;
		for(auto v1:st[x])
			for(auto v2:st[y])
				ans=min(ans,v1.fir+v2.fir+mp1[v1.se][v2.se]);
		printf("%lld\n",w[x]+w[y]+ans);
	}
	return 0;
}

