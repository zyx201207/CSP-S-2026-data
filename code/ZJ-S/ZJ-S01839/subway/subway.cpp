#include<bits/stdc++.h>
using namespace std;
const int MA=500005;
const int MMA=2000005;
#define int long long
int c,n,m,d,q,tot;
int w[MA],k;
int g[MA],t[MA],dist[MA];
bool vis[MMA];
int ver[MMA],edge[MMA],Next[MMA],head[MMA];
struct data{
	int sum;	
}gj[MA];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
void add(int x,int y,int z)
{
	ver[++tot]=y;
	edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
priority_queue< pair<long long,long long> > qu;
void Dijkstra(int start)
{
	memset(dist,0x3f,sizeof(dist));
	memset(vis,false,sizeof(vis));
	dist[start]=0;
	qu.push(make_pair(0,start));
	while(qu.size()){
		int x=qu.top().second;
		qu.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(int i=head[x];i;i=Next[x]){
			int y=ver[i];
			int z=edge[i];
			if(dist[y]>dist[x]+z){
				dist[y]=dist[x]+z;
				qu.push(make_pair(-dist[y],y));
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			g[j]=read();
			t[j]=read();
		}
		for(int x=1;x<=k;x++){
			for(int y=x+1;y<=k;y++){
				add(g[x],g[y],t[x]+t[y]);
			}
		}
	}
	int x,y;
	while(q--){
		scanf("%lld %lld",&x,&y);
		Dijkstra(x);
		printf("%lld\n",dist[y]+w[x]+w[y]);
	}
}