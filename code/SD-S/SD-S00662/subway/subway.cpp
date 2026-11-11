#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int> PLI;
int c,n,m,d,q;
const int N=510,M=500010;
int w[M];
struct Edge{
	int v,t,nxt;
}ed[2*M];
int h[N+M],idx;
int read(){
	int k=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='9'&&ch>='0'){
		k=(k<<1)+(k<<3)+(ch^48);
		ch=getchar();
	}
	return k;
}
void add_edge(int a,int b,int c){
	ed[++idx].nxt=h[a];h[a]=idx;ed[idx].v=b;ed[idx].t=c;
}
long long f[N+M];
bool st[N+M];
void dijkstra(int x){
	memset(f,0x3f,sizeof(f));
	memset(st,false,sizeof(st));
	priority_queue<PLI>pq;
	pq.push({0,x});
	while(pq.size()){
		long long l=pq.top().first;
		int e=pq.top().second;
		pq.pop();
		if(st[e])continue;
		st[e]=true;
		f[e]=-l;
		for(int i=h[e];i!=-1;i=ed[i].nxt){
			int u=ed[i].v;
			int k=ed[i].t;
			pq.push({(long long)(-f[e]-k),u});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)w[i]=read();
	memset(h,-1,sizeof(h));
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read();
			int b=read();
			add_edge(i+m,a,b);
			add_edge(a,i+m,b);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		x=read();
		y=read();
		dijkstra(x);
		long long ans=(long long)(f[y]+w[x]+w[y]);
		printf("%lld\n",ans);
	}
	return 0;
}
