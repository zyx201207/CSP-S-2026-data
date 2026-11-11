#include<bits/stdc++.h>
using namespace std;
const int maxn=501,maxm=6e5;
#define int long long
#define re register
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		k=k*10+(int)(c-'0');
		c=getchar();
	}
	return k*f;
}
int c,n,m,s,q,w[maxm];
int d[maxn][maxn],dis[maxn][maxn],v[maxn];
int zh[maxm][21],dai[maxm][21],size[maxm];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q1;
struct node{
	int to,next,w;
}edge[2*maxn*maxn];
int vex[maxn],ei;
inline void add(int u,int v,int w){
	edge[++ei]=node{v,vex[u],w};
	vex[u]=ei;
}
inline void dij(int s){
	memset(v,0,sizeof(v));
	memset(dis[s],0x3f,sizeof(dis[s]));
	dis[s][s]=0;
	v[s]=1;
	q1.push(make_pair(0,s));
	while(q1.size()){
		int t=q1.top().second;
		q1.pop();
		for(re int j=vex[t];j;j=edge[j].next){
			int i=edge[j].to;
			if(i!=t&&d[t][i]){
				if(dis[s][i]>dis[s][t]+d[t][i]){
					dis[s][i]=dis[s][t]+d[t][i];
					if(v[i]==0){
						v[i]=1;
						q1.push(make_pair(dis[s][i],i));
					}
				}
			}
		}
	}
}
//inline int min(int x,int y){
//	return x<y?x:y;
//}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	s=read();
	q=read();
	for(re int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(re int i=1;i<=n;i++){
		int k=read();
		for(re int j=1;j<=k;j++){
			int v=read(),w=read();
			zh[v][++size[v]]=i;
			dai[v][size[v]]=w;
		}
	}
	memset(d,0x3f,sizeof(d));
	for(re int i=1;i<=m;i++){
		for(re int j=1;j<=size[i];j++){
			for(re int k=j+1;k<=size[i];k++){
//				if(j==k){
//					continue;
//				}
				int u=zh[i][j],v=zh[i][k],w1=dai[i][j],w2=dai[i][k];
				d[u][v]=min(d[u][v],w1+w2);
				d[v][u]=min(d[v][u],w1+w2);
			}
		}
	}
	for(re int i=1;i<=n;i++){
		for(re int j=i+1;j<=n;j++){
			if(d[i][j]!=d[i][i]){
				add(i,j,d[i][j]);
				add(j,i,d[i][j]);
			}
		}
	}
	for(re int i=1;i<=n;i++){
		dij(i);
	}
//	memset(dis,0x3f,sizeof(dis));
//	for(int k=1;k<=n;k++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//			}
//		}
//	}
	for(re int i=1;i<=q;i++){
		int u=read(),v=read(),ans=1e18;
		for(re int j=1;j<=size[u];j++){
			for(re int k=1;k<=size[v];k++){
				int e1=zh[u][j],e2=zh[v][k],w1=dai[u][j],w2=dai[v][k];
				ans=min(ans,w1+w2+w[u]+w[v]+dis[e1][e2]);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
}
