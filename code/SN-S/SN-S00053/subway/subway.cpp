//subway
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510;
const int M=5e5+10;
struct node{
	int u,v,next=-1;
	ll w;
	bool operator < (const node &a)const{
		return w>a.w;
	}
}e[N*N];
ll dis[N][N],w[M];
ll mp[N][N];
int n,m,c,d,q,total=0;
int head[N];
ll road[M][25],roadn[M],roadv[M][25];
bool vis[N*N];
priority_queue<node>qe;
void init(){
	memset(vis,false,sizeof(vis));
	while(!qe.empty())qe.pop();
}
void add(int u,int v,int w){
	total++;
	e[total].u=u;
	e[total].v=v;
	e[total].w=w;
	e[total].next=head[u];
	head[u]=total;
}
void solve(int ut){
	dis[ut][ut]=0;
	for(int i=head[ut];i!=-1;i=e[i].next){
		qe.push(e[i]);
		vis[i]=true;
	}
	while(!qe.empty()){
		node t=qe.top();qe.pop();
		int u=t.u,v=t.v;
		ll w=t.w;
		if(dis[ut][v]>dis[ut][u]+w)dis[ut][v]=dis[ut][u]+w;
		for(int i=head[v];i!=-1;i=e[i].next){
			if(vis[i]==0&&dis[ut][e[i].v]>dis[ut][e[i].u]+e[i].w){
				qe.push(e[i]);
				vis[i]=true;
			}
		}
	}
}
int main(){
  	freopen("subway.in","r",stdin);
  	freopen("subway.out","w",stdout);
  	memset(head,-1,sizeof(head));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			dis[i][j]=2e18;
			mp[i][j]=2e9; 
		} 
	}
  	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
  	for(int i=1;i<=m;i++){
  		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int kt;
		cin>>kt;
	  	for(int j=1;j<=kt;j++){
	  		int sm,st;
	  		cin>>sm>>st;
	  		//每一个站台的编号为m+i;
			roadn[sm]++;
			road[sm][roadn[sm]]=i;
			roadv[sm][roadn[sm]]=st;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=roadn[i];j++){
			for(int k=1;k<=roadn[i];k++){
				if(j==k)continue;
				mp[road[i][j]][road[i][k]]=min(mp[road[i][j]][road[i][k]],roadv[i][j]+roadv[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]!=2e9)
			add(i,j,mp[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		init();
		solve(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=2e18;
		for(int i=1;i<=roadn[x];i++){
			for(int j=1;j<=roadn[y];j++){
				ans=min(ans,roadv[x][i]+roadv[y][j]+dis[road[x][i]][road[y][j]]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}	
	return 0;
} 
