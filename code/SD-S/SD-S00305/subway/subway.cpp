#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();return x*f;
}
const int M=1005,N=505;
int c,n,m,d,q,x,y,w[M],k,a[M],t[M];//m个地铁站！n条线路！ 
long long dis[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i) w[i]=read();
	for(int i=1;i<=m;++i) for(int j=1;j<=m;++j)
		if(i==j) dis[i][j]=0;
		else dis[i][j]=1e18;
	for(int i=1;i<=n;++i){
		k=read();
		for(int j=1;j<=k;++j)
			a[j]=read(),t[j]=read();
		for(int j=1;j<=k;++j) for(int _=1;_<=k;++_)
			dis[a[j]][a[_]]=min(dis[a[j]][a[_]],1ll*t[j]+1ll*t[_]);
	}
	for(int k=1;k<=m;++k) for(int i=1;i<=m;++i) for(int j=1;j<=m;++j)//floyd
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	
	while(q--){
		x=read(),y=read();
		cout<<dis[x][y]+1ll*w[x]+1ll*w[y]<<'\n';
	}
	return 0;
}
