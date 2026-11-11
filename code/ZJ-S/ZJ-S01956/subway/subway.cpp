#include <bits/stdc++.h>
using namespace std;
const int M=5e5+1;
const int N=500;
int n,m,q,d;
int wn[M];
int to[M*20],h[M*20],val[M*20],nxt[M*20];
int du[21];
/*int read(){
	int res=0,sgn=0,ch=getchar();
	while(!isdigit(ch)) sgn|=ch=='-',ch=getchar();
	while(isdigit(ch)) res=res*10+ch,ch=getchar();
	return res;
}*/
long long cnt;
void add(int u,int v,int w1){
	to[++cnt]=v;
	nxt[cnt]=h[u];
	h[u]=cnt;
	val[cnt]=w1;
}
int dis[20*M];
struct node{
	int tn;
	int	w;
	friend bool operator < (node x,node y){
		return x.w >y.w ;
	}
}sum;
bool vis[M*20];
void dij(int u){
	priority_queue<node> q;
	for(int i=1;i<=n;i++){
		dis[i]=2147482647;
	}
	dis[0]=2147483647;
	dis[u]=0;
	sum.w=dis[u];
	sum.tn =u;
	vis[u]=1;
	while(!q.empty()){
		sum= q.top();
		q.pop();
		for(int i=h[sum.tn];i;i=nxt[i]){
			if(dis[i]>dis[sum.tn]+val[i]&&!vis[i]){
				dis[i]=dis[sum.tn]+val[i];
				sum.tn =i;
				sum.w =dis[i];
				q.push(sum);
				vis[i]=1;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
    scanf("%d",&c);
	/*n=read();
	m=read();
	d=read();
	q=read();*/
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&wn[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		int u=0,t=0;
		int u1;
		for(int j=1;j<=q;j++){
			scanf("%d%d",&u,&t);
			if(u1!=0){
				add(u1,u,0);
				add(u,u1,0);
				u1=u;
			}
			add(u,u+M,t);
			add(u+M,u,t);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		dij(x);
		int ans=dis[y]+wn[x]+wn[y];
		printf("%d\n",ans);
	}
	return 0;
} 
