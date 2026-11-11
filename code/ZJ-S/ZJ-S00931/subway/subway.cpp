#include<bits/stdc++.h>
using namespace std;
long long op,n,m,d,q,zuizhong[600000],dist[600000],t,vis[600000],a[600000],b[600000];
priority_queue<int,vector<int >,greater<int > >pq;
long long e[6000][6000],shu[6000],w[6000][6000],y23[600000][2],y24[600000][2];
long long y25[600000][2];
long long p,liang,bj[600000][4],bj1[600000][4];
bool A,B;
inline int read(){
	long long f=1,x=0;
	char c=getchar();
	while(!(c>='0'&&c<='9')){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
int dij(int x,int y){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[x]=0;
	vis[x]=1;
	pq.push(x);
	while(!pq.empty()){
		if(vis[y]==1) return dist[y];
		p=pq.top();
		pq.pop();
		for(int v=1;v<=shu[p];v++){
			if(vis[e[p][v]]) continue;
			vis[e[p][v]]=1;
			dist[e[p][v]]=min(dist[e[p][v]],dist[p]+w[p][v]);
			pq.push(e[p][v]);
		}
	}
	return dist[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	op=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		zuizhong[i]=read();
	}
	if(op>=7&&op<=11){
		A=true;
	}
	if(op>=12&&op<=19){
		B=true;
	}
	for(int ppp=1;ppp<=n;ppp++){
		t=read();
		for(int i=1;i<=t;i++){
			a[i]=read(),b[i]=read();
		}
		for(int i=1;i<=t;i++){
			for(int j=1;j<=t;j++){
				if(i==j) continue;
				w[a[i]][++shu[a[i]]]=b[i]+b[j];
				e[a[i]][shu[a[i]]]=a[j];
				shu[a[i]]++;
			}
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		x=read(),y=read();
		cout<<dij(x,y)+zuizhong[x]+zuizhong[y]<<"\n";
	}
	return 0;
}

