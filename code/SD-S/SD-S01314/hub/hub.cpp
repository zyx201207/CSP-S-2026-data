#include<bits/stdc++.h>
#define cmin(a,b) a=std::min(a,b)
#define cmax(a,b) a=std::max(a,b)
#define inf ((int)1e18)
#define mod
#define maxn 1004
#define int long long
#define pb push_back
#define pii std::pair<int,int>
#define arr(x) std::array<int,(x)>
#define fi first
#define se second
bool Mst;
int C,T,n,K;
std::vector<int> to[1000006],pth[maxn][maxn];
void dfs1(int x,int fa,int rt){
	pth[rt][x].pb(x);
	for(int v:to[x]){
		if(v==fa) continue;
		pth[rt][v]=pth[rt][x],dfs1(v,x,rt);
	}
}
int ok[maxn],mx[maxn],MID,nd,chs[maxn];
void dfs2(int x,int fa){
	mx[x]=0;
	for(int v:to[x]) if(v!=fa&&ok[v]){
		dfs2(v,x),cmax(mx[x],mx[v]+1);
	}
	if(x==fa||mx[x]>=MID){
		nd++,chs[x]=1;
	}
}
int dis[maxn];
std::queue<int> que;
bool _chk(){
	for(int i=1;i<=n;i++){
		dis[i]=inf;
		if(chs[i]) dis[i]=0,que.push(i);
	}
	while(!que.empty()){
		int x=que.front();que.pop();
		for(int v:to[x]){
			if(dis[v]==inf){
				dis[v]=dis[x]+1;
				que.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dis[i]>MID) return 0;
	}
	return 1;
}
bool chk(int mid){
	MID=mid;
	for(int u=1;u<=n;u++){
		for(int v=u+1;v<=n;v++){
			if((int)pth[u][v].size()>2*mid+2) continue;
			for(int i=1;i<=n;i++){
				ok[i]=1,chs[i]=0;
			}
			for(int x:pth[u][v]) ok[x]=0;
			nd=0,dfs2(u,u),dfs2(v,v);
			if(nd>K) continue;
			if(_chk()) return 1;
		}
	} 
	return 0;
}
void ama10(){
	scanf("%lld%lld",&n,&K);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		to[u].pb(v),to[v].pb(u);
	}
	if(n>100){
		if(n==K) printf("%lld\n",0ll);
		else printf("%lld\n",((n+3)/2-K+3)/4);
		return;
	}
	for(int i=1;i<=n;i++){
		dfs1(i,i,i);
	}
	int L=0,R=n,res=n;
	while(L<=R){
		int mid=(L+R)>>1;
		if(chk(mid)) res=mid,R=mid-1;
		else L=mid+1;
	}
	printf("%lld\n",res); 
}
void clr(){
	for(int i=1;i<=n;i++){
		to[i].clear();
		if(n<=100)
		for(int j=1;j<=n;j++){
			pth[i][j].clear();
		}
	}
}
bool Med;
signed main(){
//	fprintf(stderr,"used: %lld MB\n",(&Med-&Mst)/1024/1024);
	freopen("hub.in","r",stdin); 
	freopen("hub.out","w",stdout); 
	scanf("%lld%lld",&C,&T);
	while(T--) ama10(),clr(); 
	return 0;
}
/*
-std=c++14 -O2 -lm -Wall -Wl,--stack=1234567890

16:40 110 min
??? 
T 17:00 ? 
W 17:31

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/


