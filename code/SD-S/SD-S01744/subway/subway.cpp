#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=1e3;
int c,n,m,d,q;
int w[N];
int k[N];
const int M=1e6+10;
int cnt,to[M],v[M],head[M],nxt[M];
void add(int x,int y,int z){
	cnt++;
	to[cnt]=y;
	v[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int tai[505][505];
int daihao=600*600+10;
void pre(){
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			daihao++;
			tai[i][j]=daihao;
		}
	}
}
int dist[M];
bool vis[M];
struct qqq{
	int pos,dis;
	friend bool operator<(const qqq &x,const qqq &y){
		return x.dis>y.dis;
	}
};
void dji(int s){
	for(int i=1;i<=M-10;i++) dist[i]=100000;
	for(int i=1;i<=M-10;i++) vis[i]=0;
	dist[s]=0;
	vis[s]=1;
	priority_queue<qqq> q;
	q.push({s,0});
	while(!q.empty()){
		qqq xxx=q.top();
		q.pop();
		int poss=xxx.pos;
		int distt=xxx.dis;
		if(vis[poss]) continue;
		vis[poss]=1;
		for(int i=head[poss];i;i=nxt[i]){
			int tto=to[i];
			if(dist[tto]>v[i]+dist[poss]){
				dist[tto]=v[i]+dist[poss];
				q.push({tto,dist[tto]});
			}
		}
	}
}
void sol_A(){
	for(int i=1;i<=m;i++){
		w[i]=read();
	} 
	int csh=2*m+1;
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=0;j<k[i];j++){
			int a=read();
			int t=read();
			add(a,tai[a][i],t);
			add(tai[a][i],a,t);
			add(tai[a][i],1000+i,0);
			add(1000+i,tai[a][i],0);
		}
	}
	for(int i=1;i<=q;i++){
		int x=read(),y=read();
		dji(x);
		cout<<dist[y]+w[x]+w[y]<<'\n';
	}
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	pre();
	sol_A();
}
