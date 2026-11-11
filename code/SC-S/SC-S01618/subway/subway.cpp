#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q;
int w[M];
ll f[N][N];
struct node{
	int id,val;
};
vector<node>vec[M];
int head[N],cnt;
struct edge{
	int v,w,next;
}a[M];
void add(int u,int v,int w){
	a[++cnt]=(edge){v,w,head[u]};
	head[u]=cnt;
}
int vis[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >Q;
void dijkstra(int s){
	for(int i=1;i<=n;i++)f[s][i]=1e18,vis[i]=0;
	f[s][s]=0;
	Q.push(make_pair(0,s));
	while(!Q.empty()){
		int d=Q.top().second;
		Q.pop();
		if(vis[d])continue;
		vis[d]=1;
		for(int i=head[d];i;i=a[i].next){
			int v=a[i].v;
			if(f[s][v]>f[s][d]+(ll)a[i].w){
				f[s][v]=f[s][d]+(ll)a[i].w;
				Q.push(make_pair(f[s][v],v));
			}
		}
	}
}
int main(){
//	freopen("C:\\Users\\user\\Desktop\\输入.txt","r",stdin);
//	freopen("C:\\Users\\user\\Desktop\\输出.txt","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int d,t;
			scanf("%d%d",&d,&t);
			vec[d].push_back((node){i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)f[i][j]=0;
			else f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size();j++){
			for(int k=0;k<j;k++){
				if(j==k)continue;
				int u=vec[i][j].id,v=vec[i][k].id;
				f[u][v]=min(f[u][v],(ll)vec[i][j].val+(ll)vec[i][k].val);
				f[v][u]=min(f[v][u],(ll)vec[i][j].val+(ll)vec[i][k].val);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&f[i][j]!=1e18)add(i,j,f[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ll minn=1e18;
		for(int j=0;j<vec[u].size();j++){
			for(int k=0;k<vec[v].size();k++){
				int x=vec[u][j].id,y=vec[v][k].id;
				minn=min(minn,(ll)w[u]+(ll)w[v]+(ll)vec[u][j].val+(ll)vec[v][k].val+f[x][y]);
			}
		}
		printf("%lld\n",minn);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}