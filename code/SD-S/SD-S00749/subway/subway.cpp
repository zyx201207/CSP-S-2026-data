#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	char c=getchar();
	long long x=0,f=1;
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		write(-x);
		return ;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
const int N=5e5+1,M=501;
const int inf=0x7fffffff;
const long long INF=1e16;
int len[M][M];
long long dis[M][M];
int c[N][21],a[N][21];
int w[N],cnt[N]; 
int C,m,n,d,q,x,y,t,tot=-1;
bool vis[M];
int head[M],num[M],e[N],nxt[N];
void add(int x,int y){
	e[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
struct node{
	int v;
	long long dis;
};
bool operator < (node a,node b){
	return a.dis>b.dis;
}
void dijkstra(int s){
	priority_queue<node> q;
	for(int i=1;i<=m;i++){
		vis[i]=0;
	}
	q.push({s,dis[s][s]});
	while(!q.empty()){
		int x=q.top().v;
		q.pop();
		if(vis[x]){
			continue;
		}
		vis[x]=1;
		for(int i=head[x];i!=-1;i=nxt[i]){
			int y=e[i];
			if(dis[s][y]>dis[s][x]+len[x][y]){
				dis[s][y]=dis[s][x]+len[x][y];
				q.push({y,dis[s][y]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read(),m=read(),n=read(),d=read(),q=read(); 
	for(int i=1;i<=n;++i){
		w[i]=read();
	}
	for(int i=1;i<=m;++i){
		head[i]=-1;
		for(int j=1;j<=m;++j){
			dis[i][j]=INF;
			len[i][j]=inf;
		}
		dis[i][i]=0,len[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		num[i]=read();
		for(int j=1;j<=num[i];j++){
			x=read(),t=read();
			cnt[x]++;
			c[x][cnt[x]]=t;
			a[x][cnt[x]]=i;
			for(int k=1;k<cnt[x];k++){
				int y=a[x][k];
				len[i][y]=min(len[i][y],t+c[x][k]);
				len[y][i]=min(len[y][i],t+c[x][k]);
			}
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=i+1;j<=m;++j){
			if(len[i][j]!=inf){
				add(i,j);
				add(j,i);
			}
		}
	}
	for(int i=1;i<=m;i++){
		dijkstra(i);
	}
	while(q--){
		x=read(),y=read();
		long long ans=1e18; 
		for(int i=1;i<=cnt[x];i++){
			int xx=a[x][i];
			for(int j=1;j<=cnt[y];j++){
				int yy=a[y][j];
				if(dis[xx][yy]==INF){
					continue;
				}
				long long d=c[x][i]+c[y][j];
				ans=min(ans,dis[xx][yy]+d);
			}
		}
		ans=ans+w[x]+w[y]; 
		write(ans);
		putchar('\n');
	}
	return 0;
} 
