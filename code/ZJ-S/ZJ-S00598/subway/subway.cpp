#include<bits/stdc++.h>
#define int long long
#define raed(x) read(x)
#define Spa putchar(' ')
#define Nxt puts("");
#define Pline puts("--------------")
namespace FastIO{
	int read_x,read_f,write_top;
	int write_st[25];
	char read_char;
	inline int read(int &x){
		x=0;
		read_f=1;
		read_char=getchar();
		while(!isdigit(read_char)){
			if(read_char=='-')read_f=-1;
			read_char=getchar();
		}
		while(isdigit(read_char)){
			x=(x<<1)+(x<<3)+(read_char-'0');
			read_char=getchar();
		}
		return x*=read_f;
	}
	inline int read(){
		read_x=0;
		read_f=1;
		read_char=getchar();
		while(!isdigit(read_char)){
			if(read_char=='-')read_f=-1;
			read_char=getchar();
		}
		while(isdigit(read_char)){
			read_x=(read_x<<1)+(read_x<<3)+(read_char-'0');
			read_char=getchar();
		}
		return read_x*read_f;
	}
	inline void write(int x){
		if(x<0)putchar('-'),x=-x;
		do{
			write_st[++write_top]=x%10;
			x/=10;
		}while(x);
		while(write_top)putchar(write_st[write_top--]+'0');
		return ;
	}
	inline void tomax(int &x,int y){
		if(x<y)x=y;
		return ;
	}
	inline void tomin(int &x,int y){
		if(x>y)x=y;
		return ;
	}
}
using namespace FastIO;
using namespace std;
int type,n,m,d,q;
namespace Subtask1{
#define pii pair<int,int>
int w[405],dist[605][605];
vector<pii>e[605];

bool vis[605];
struct Node{
	int dis,u;
	bool operator >(const Node &T)const{
		return dis>T.dis;
	}
};
priority_queue<Node,vector<Node>,greater<Node>>Q;
void Dijkstra(int s){
	memset(vis,0,sizeof(vis));
	
	dist[s][s]=0;
	Q.push({dist[s][s],s});
	while(!Q.empty()){
		int u=Q.top().u;
		Q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto tmp:e[u]){
			int v=tmp.first,w=tmp.second;
			if(dist[s][v]>dist[s][u]+w){
				dist[s][v]=dist[s][u]+w;
				Q.push({dist[s][v],v});
			}
		}
	}
}
void solve(){
	for(int i=1;i<=m;i++)
		read(w[i]);
	for(int i=1,k;i<=n;i++){
		read(k);
		for(int j=1,a,b;j<=k;j++){
			read(a),read(b);
			e[a].push_back({i+m,b});
			e[i+m].push_back({a,b});
		}
	}
//	Pline;
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++)
		Dijkstra(i);
//	Pline;
	for(int i=1,x,y;i<=q;i++){
//		Pline;
		read(x),read(y);
		write(w[x]+dist[x][y]+w[y]),Nxt;
//		Pline;
	}
}
#undef pii
}
namespace Subtask2{
#define pii pair<int,int>
const int N=5e5+5;
int w[N];
int dist[505][505];
vector<pii>e[N];
void solve(){
	for(int i=1;i<=m;i++)
		read(w[i]);
	for(int i=1,k;i<=n;i++){
		read(k);
		for(int j=1,a,b;j<=k;j++){
			read(a),read(b);
			e[a].push_back({i,b});
		}
	}
	
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++)
		dist[i][i]=0;
	for(int u=1;u<=m;u++){
		for(auto tmp1:e[u]){
			for(auto tmp2:e[u]){
				int v1=tmp1.first,w1=tmp1.second;
				int v2=tmp2.first,w2=tmp2.second;
				tomin(dist[v1][v2],w1+w2);
				tomin(dist[v2][v1],w1+w2);
			}
		}
	}
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				tomin(dist[i][j],dist[i][k]+dist[k][j]);
	
	for(int i=1,x,y;i<=q;i++){
		read(x),read(y);
		int ans=LONG_LONG_MAX;
		for(auto tmp1:e[x]){
			for(auto tmp2:e[y]){
				int v1=tmp1.first,w1=tmp1.second;
				int v2=tmp2.first,w2=tmp2.second;
				tomin(ans,w1+dist[v1][v2]+w2);
			}
		}
		write(w[x]+ans+w[y]),Nxt;
	}
}
#undef pii
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(type),read(n),read(m),read(d),read(q);
//	Pline;
	Subtask2::solve();
}
/*
the d is small 
how can I use it?
I have a thought 
can I connect edge between the points of subway?
but I will type for the test from one to eight
*/
