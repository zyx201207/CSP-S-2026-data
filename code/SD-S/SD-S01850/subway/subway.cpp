#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#define ll long long
using namespace std;
const int N=510,M=5e5+10,D=21;
int c,n,m,d,q,s,t,a[M][D],k,ax;
ll f[N][N],w[M],cst[M][D],tm,dis[N][N];
bool vis[N];
const ll INF=0x3f3f3f3f3f3f3f3f;
ll rd(){
	ll x=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-'){
			f=-1;
		}ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3ll)+(x<<1ll)+ch-'0';ch=getchar();
	}return x*f;
}
ll mn(ll a,ll b){
	return a<b?a:b;
}
void init(int x){
	int u,v;
	for(int i=1;i<=a[x][0];i++){
		for(int j=i+1;j<=a[x][0];j++){
			u=a[x][i],v=a[x][j];
			f[u][v]=mn(f[u][v],cst[x][i]+cst[x][j]);
			f[v][u]=mn(f[v][u],cst[x][i]+cst[x][j]);
		}
	}
}
void floyd(){
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=mn(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
struct node{
	int y;ll d;
};
vector<node>vc[N];
priority_queue<pair<ll,int> > Q;
void dij(int s){
	
	memset(dis[s],0x3f,sizeof(dis[s]));
	memset(vis,0,sizeof(vis));
	dis[s][s]=0;
	Q.push(make_pair(0,s));
	while(!Q.empty()){
		int x=Q.top().second;Q.pop();
		if(vis[x])continue;vis[x]=1;
		for(int i=0;i<vc[x].size();i++){
			int y=vc[x][i].y;
			if(dis[s][y]>dis[s][x]+vc[x][i].d){
				dis[s][y]=dis[s][x]+vc[x][i].d;
				Q.push(make_pair(-dis[s][y],y));
			}
		}
	}
}
void query(int s,int t){
	ll res=f[0][0];int u,v;
	for(int i=1;i<=a[s][0];i++){
		for(int j=1;j<=a[t][0];j++){
			u=a[s][i],v=a[t][j];
			res=mn(res,dis[u][v]+cst[s][i]+cst[t][j]);
//			cout<<s<<" "<<t<<" "<<u<<" "<<v<<" "<<cst[s][i]<<" "<<cst[t][j]<<endl;
		}
	}
	res+=w[s]+w[t];
	printf("%lld\n",res);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
//	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++){
//		scanf("%lld",&w[i]);
		w[i]=rd();
	}
	for(int i=1;i<=n;i++){
//		scanf("%d",&k);
		k=rd();
		for(int j=1;j<=k;j++){
//			scanf("%d%lld",&ax,&tm);
			ax=rd(),tm=rd();
			a[ax][0]++,a[ax][a[ax][0]]=i;
			cst[ax][a[ax][0]]=tm;
		}
	}
	for(int i=1;i<=m;i++)init(i);
//	floyd();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]!=INF&&i!=j)vc[i].push_back((node){j,f[i][j]});
		}
	}
	for(int i=1;i<=n;i++)dij(i);
	for(int i=1;i<=q;i++){
//		scanf("%d%d",&s,&t);
		s=rd(),t=rd();
		query(s,t);
	}
	return 0;
}
/*
不要被卡常 
不要被卡常 
不要被卡常 
*/
