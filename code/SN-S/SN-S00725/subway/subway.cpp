#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e2+10;
const int maxm=5e5+10;
const int maxe=1e7+10;
char buf[1<<20],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++) 
inline ll read(){
	char c=getchar(); ll t=1,k=0;
	for(;'0'>c||c>'9';c=getchar()) if(c=='-') t=-1;
	for(;'0'<=c&&c<='9';c=getchar()) k=k*10+(c^48);
	return t*k;
}
#define INF 1e15
struct node{
	int v,nxt;ll w;
}edge[maxe<<2];
int c,n,m,d,q,cnt,head[maxm<<1];
ll w[maxm],dis[maxn][maxn];
inline void add(int u,int v,ll w){
	edge[++cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read();ll t=read();
			add(m+i,a,t); add(a,m+i,t);
//			cout<<m+i<<' '<<a<<endl;
		}
	} 
//	for(int i=1;i<=m+n;i++){
//		printf("%d\n",i);
//		for(int j=head[i];j;j=edge[j].nxt){
//			printf("%d %d %lld\n",i,edge[j].v,edge[j].w);
//		}
//		printf("\n");
//	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) dis[i][j]=INF;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=head[m+i];j;j=edge[j].nxt){
			int v=edge[j].v;
			for(int k=head[v];k;k=edge[k].nxt){
				int to=edge[k].v;
				if(to==m+i) continue; 
				dis[to-m][i]=dis[i][to-m]=
				min(dis[i][to-m],edge[j].w+edge[k].w);
			}
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			printf("%lld%c",dis[i][j],j==n?'\n':' ');
	while(q--){
		int x=read(),y=read();ll ans=INF;
		for(int i=head[x];i;i=edge[i].nxt){
			int v=edge[i].v;
			for(int j=head[y];j;j=edge[j].nxt){
				int vv=edge[j].v;
				ans=min(ans,edge[i].w+edge[j].w+dis[v-m][vv-m]);
//				cout<<dis[v-m][vv-m]<<' '<<edge[i].w<<' '<<edge[j].w<<endl;
			}
		}
//		printf("%lld\n",ans); 
		printf("%lld\n",ans+w[x]+w[y]);
	}
//	for(int i=1;i<=m+n;i++){
//		printf("%d\n",i);
//		for(int j=head[i];j;j=edge[j].nxt){
//			printf("%d %d %lld\n",i,edge[i].v,edge[i].w);
//		}
//		printf("\n");
//	}
	return 0;
}
