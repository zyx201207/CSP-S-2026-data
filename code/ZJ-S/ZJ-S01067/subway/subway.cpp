#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e2+10;
const int M=5e5+10;
const ll inf=1e17;
int w[M],c,n,m,d,q;
ll dis[N][N];
struct node{
	int v,w;
};
vector<vector<node> > p(M,vector<node>() );
int read(){
	char x;
	int num=0;
	x=getchar();
	for(;x>='0' and x<='9';x=getchar()) num=(num*10)+(x-'0');
	return num;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	int x,a,t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		x=read();
		for(int j=1;j<=x;j++){
			a=read(),t=read();
			p[a].push_back({i,t});//pay attention to x,it isnt mean zhantai number
		}
	}
	node k1,k2;
	for(int i=1;i<=m;i++){
		for(int j=0;j<p[i].size();j++){
			for(int k=j+1;k<p[i].size();k++){
				k1=p[i][j],k2=p[i][k];
				dis[k1.v][k2.v]=min(dis[k1.v][k2.v],0LL+k1.w+k2.w);
				dis[k2.v][k1.v]=min(dis[k2.v][k1.v],0LL+k2.w+k1.w);
			}
		} 
	} 
	for(int u=1;u<=n;u++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][u]+dis[u][j]);
			}
		}
	}
	int xx,yy;
	ll res;
	node x1,x2;
	while(q--){
		xx=read(),yy=read();
		res=inf;
		for(int i=0;i<p[xx].size();i++){
			for(int j=0;j<p[yy].size();j++){
				x1=p[xx][i],x2=p[yy][j];
				res=min(res,dis[x1.v][x2.v]+0LL+x1.w+x2.w);
			}
		}
		res+=w[xx]+w[yy];
		printf("%lld\n",res);
	}
}
