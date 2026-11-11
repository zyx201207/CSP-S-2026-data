#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
void print(int x){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else if(x<10){
		putchar(x^48);
	}
	else{
		print(x/10);
		putchar((x%10)^48);
	}
}
const int inf=0x3f3f3f3f3f3f3f3fll;
const int M=5e5+10,N=510;
int c,n,m,d,q;
struct Edge{
	int nxt,to,t;
}e[M<<1];
bool vis[M<<1];
int head[M+N],cnt=1;
void add(int u,int v,int t){
//	cout<<u<<"->"<<v<<' '<<t<<'\n';
	e[++cnt]={head[u],v,t};
	head[u]=cnt;
}
int w[M];
int dis[N][N];
//void dfs(int u,int lst,int from,int T){
////	cout<<u<<' '<<lst<<' '<<from<<' '<<T<<'\n';
//	for(int i=head[u],v,t;i;i=e[i].nxt){
//		if(i==from||vis[i]||vis[i^1])continue;
//		v=e[i].to,t=e[i].t;
//		vis[i]=vis[v^1]=true;
//		if(v<=n){
//			dis[lst][v]=dis[v][lst]=min(dis[lst][v],T+t);
//			dfs(v,u,i,0);
//		}
//		else{
//			dfs(v,u,i,t);
//		}
//	}
//}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
//	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		w[i]=read();
//		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		k=read();
//		cin>>k;
		for(int j=1,v,t;j<=k;j++){
			v=read(),t=read();
//			cin>>v>>t;
			add(i,v+n,t);
			add(v+n,i,t);
		}
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
//	puts("asdfasdfasdfasd");
//	dfs(1,0,0,0);
	for(int st=n+1;st<=n+m;st++){
		for(int i=head[st],u,t1;i;i=e[i].nxt){
			u=e[i].to,t1=e[i].t;
			for(int j=e[i].nxt,v,t2;j;j=e[j].nxt){
				v=e[j].to,t2=e[j].t;
//				cout<<st-n<<' '<<u<<' '<<v<<' '<<t1<<' '<<t2<<'\n';
				dis[u][v]=dis[v][u]=min(dis[u][v],t1+t2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int S,E;q--;){
		S=read(),E=read();
//		cin>>S>>E;
		int ans=w[S]+w[E],minn=inf;
		S+=n,E+=n;
		for(int i=head[S],u,t1;i;i=e[i].nxt){
			u=e[i].to,t1=e[i].t;
			for(int j=head[E],v,t2;j;j=e[j].nxt){
				v=e[j].to,t2=e[j].t;
//				cout<<u<<' '<<v<<'\n';
//				cout<<t1<<' '<<t2<<'\n';
				minn=min(minn,t1+t2+dis[u][v]);
			}
		}
//		cout<<'\n';
//		cout<<minn<<' '<<ans<<' ';
		print(minn+ans);
		puts("");
//		cout<<minn+ans<<'\n';
//		puts("==================");
	}
}
