#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5003;
const int F=N*N*N; 
int c,t,n,d;
int x[N],dis[N],cnt[N];
bool e[N][N];
struct edge{
	int v,w;
};
vector<edge> G[N]; 
queue<int> q;
bool typeA(){
	for(int i=3;i<=n;i++)
		if(x[i]-x[i-1]!=x[2]-x[1]) return 0;
	return 1;
}
int bfs(int s){
	while(!q.empty()) q.pop();
	q.push(s); int ret=0;
	for(int i=1;i<=n;i++) dis[i]=F;
	for(int i=1;i<=n;i++) cnt[i]=0;
	dis[s]=0; cnt[s]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int v=1;v<=n;v++){
			if(!e[u][v]) continue;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push(v);				
			}
			else if(dis[v]==dis[u]+1)
				cnt[v]+=cnt[u];
		}	
	}
	for(int i=1;i<=n;i++)
		ret+=(cnt[i]==2);
	return ret;
}
int work(){
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%lld",&x[i]);
	if(typeA()){
		int del=x[2]-x[1];
		int nd=d/del;
		if(nd<=1) return 0;
		int s=2*nd-1;
		return max(n-s,0LL);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(abs(x[i]-x[j])<=d)
				e[i][j]=1;	
			else e[i][j]=0;		
		}
	}	
	int ans=0;
	for(int i=1;i<=n;i++) ans+=bfs(i);
	return ans/2;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--) printf("%lld\n",work());
} 
